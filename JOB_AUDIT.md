# Audit Sistem Job

Tanggal audit: 2026-07-27
Branch: `arena/019fa31b-rewrite-samp`

## Cakupan

Diperiksa seluruh modul pada `gamemodes/core/jobs`:

- Butcher
- Cargo/Hauling
- Farmer
- Fisherman
- Lumberjack
- Miner
- Oilman
- Pelaut
- Peternak/Milker
- Porter
- Sawit
- Supir Angkot
- Supir Mixer
- Tailor
- Integrasi timer pada `timers/timers_ptask_update.inc`

Total yang dibaca: 15 modul, sekitar 3.982 baris job, termasuk seluruh jalur pembayaran `GivePlayerMoneyEx` dan timer job terkait.

## A. Temuan kritis — berpotensi menyebabkan uang berlebih

### A1. Pelaut membayar dua kali pada akhir rute
**Lokasi:** `gamemodes/core/timers/timers_ptask_update.inc`, blok `SailDockTimer` sekitar baris 7160–7205.

Saat player menyelesaikan checkpoint dock, script selalu membayar `$800`. Saat `SailRute[playerid] == 13`, script membayar `$800` lagi sebelum job diakhiri. Jadi checkpoint terakhir/finish menerima dua pembayaran dalam satu siklus.

**Dampak:** player dapat menerima tambahan `$800` tanpa menyelesaikan perjalanan tambahan. Ini temuan paling jelas yang perlu diperbaiki.

**Perbaikan yang disarankan:** bayar hanya satu kali per checkpoint, atau jadikan pembayaran finish sebagai bonus terpisah dengan nominal yang memang disengaja. Tambahkan flag transaksi/checkpoint agar callback tidak dapat diproses ulang.

### A2. Semua pembayaran checkpoint perlu idempotency
**Lokasi:** terutama `SailDockTimer`, `UpdateTimeJob`, angkot, mixer, dan cargo.

Sebagian pembayaran dilakukan di timer berdasarkan state global per-player. State memang biasanya di-reset, tetapi belum ada satu guard umum seperti `RewardClaimed`/`JobTransactionID`. Bila callback/checkpoint dipicu ulang sebelum state dibersihkan, pembayaran dapat berulang.

**Perbaikan yang disarankan:** sebelum membayar:

1. Pastikan state job aktif.
2. Pastikan checkpoint adalah checkpoint aktif player.
3. Set state/flag selesai terlebih dahulu.
4. Hancurkan checkpoint.
5. Baru bayar.

## B. Bug gameplay/state

### B1. Cleanup job harus diuji pada disconnect, death, ganti job, dan kendaraan hancur
Job kendaraan membuat `JobVehicle[playerid]`, `JobCP[playerid]`, actor, trailer, dan timer. Risiko terbesar ada pada Pelaut, Angkot, Mixer, Fisherman, dan Cargo.

State yang tidak dibersihkan dapat menyebabkan:

- player lama masih memiliki checkpoint/job vehicle;
- player baru yang memakai slot `playerid` mewarisi state lama;
- timer masih membayar setelah job dibatalkan;
- kendaraan job tertinggal di dunia.

**Perbaikan yang disarankan:** buat satu fungsi cleanup per job dan panggil dari `OnPlayerDisconnect`, death/cancel, ganti job, dan kendaraan dihancurkan. Jangan hanya mengandalkan timer untuk cleanup.

### B2. Cargo memakai request bisnis global
Cargo menggunakan `g_FuelRestockRequest[bizid]` dan `g_FuelRestockAmount[bizid]`. Ini perlu dipastikan memiliki ownership/lock yang benar ketika dua player mengambil request bisnis yang sama.

**Risiko:** request dapat ditimpa, diselesaikan oleh player yang bukan pengambil awal, atau reward menggunakan amount yang berubah.

**Perbaikan yang disarankan:** simpan `requester player/account ID`, `request ID`, dan amount yang immutable di `PlayerCargoVars[playerid]`. Saat finish, validasi request ID, bukan hanya business ID.

### B3. Farmer, Butcher, Miner, Lumberjack, dan job serupa bergantung pada timer progress
Progress berbasis `pActivityTime` dan flag timer. Semua jalur harus membatalkan progress ketika player:

- keluar area;
- mati/knockdown;
- berganti job;
- disconnect;
- inventory penuh atau item berubah;
- bergerak/teleport secara tidak sah.

Jika salah satu jalur hanya mematikan animasi tetapi tidak mematikan flag timer, player dapat melanjutkan progress pada state lama.

## C. Potensi eksploit uang / validasi reward

### C1. Sawit menjual seluruh inventory sekaligus
**Lokasi:** `gamemodes/core/jobs/sawit/sawit.inc`, sekitar baris 295–305.

Script menghitung seluruh `Sawit Olahan`, menghapusnya, lalu memberi uang. Urutan remove sebelum give sudah benar untuk mencegah pembayaran tanpa item pada jalur normal. Namun command/event harus tetap dibatasi pada lokasi jual dan job yang benar.

**Perbaikan:** tambahkan audit log penjualan dan batasi jumlah maksimum per transaksi untuk menghindari overflow atau transaksi abnormal.

### C2. Nominal job tersebar di banyak file
Nominal ditemukan di modul job dan timer, antara lain `$35`, `$50`, `$150`, `$175`, `$250`, `$800`, serta formula cargo/porter/sawit. Ini menyulitkan balancing dan audit.

**Perbaikan:** pindahkan reward ke konstanta/config terpusat, contohnya:

```pawn
#define JOB_PAY_ANGKOT_STOP 35
#define JOB_PAY_PELAUT_STOP 800
#define JOB_PAY_MIXER_GOOD 250
```

Dengan begitu perubahan ekonomi tidak membutuhkan pencarian manual di banyak blok.

## D. Ketidaksesuaian ekonomi yang perlu keputusan pemilik server

Belum ada data biaya operasional server seperti bensin, servis, pajak, harga item, dan waktu rata-rata rute yang cukup untuk menyatakan angka tertentu pasti salah. Namun secara struktur:

- Pelaut berpotensi membayar `$800` di setiap dock dan tambahan `$800` di finish.
- Angkot membayar per titik/penumpang, sehingga harus dibandingkan dengan waktu satu rute lengkap.
- Mixer membayar berdasarkan kualitas/slump, tetapi perlu dihitung terhadap waktu muat, waktu antar, bensin, dan risiko gagal.
- Sawit adalah produksi item + proses + penjualan; perlu dihitung sebagai total pendapatan per jam, bukan harga per item saja.
- Cargo menggunakan formula amount, sehingga perlu batas atas amount dan batas atas reward.

**Rekomendasi balancing:** ukur pendapatan bersih per jam, bukan pendapatan per checkpoint. Target awal yang aman adalah job legal entry-level memiliki pendapatan bersih sedikit di atas kebutuhan hidup dasar, sementara job dengan risiko/modal lebih besar mendapat kompensasi lebih tinggi.

## E. Optimasi performa

### E1. Timer job terpusat sangat besar
`timers_ptask_update.inc` menjalankan banyak state job per detik untuk setiap player. Optimasi yang disarankan:

- lakukan early return ketika player tidak spawned;
- proses blok timer hanya ketika flag job aktif;
- gunakan timer/event khusus per job ketika state aktif, bukan memeriksa semua job setiap detik;
- jangan melakukan operasi database pada setiap tick progress;
- cache data konstan seperti route dan reward.

### E2. Hindari foreach global untuk event yang bisa ditargetkan
Cargo mencari owner bisnis dengan `foreach(new i : Player)`. Simpan mapping `business owner account ID -> playerid` atau gunakan fungsi lookup terpusat agar tidak scan semua player setiap penyelesaian cargo.

### E3. Satukan fungsi validasi
Buat helper seperti:

```pawn
stock bool:Job_IsActive(playerid, jobid)
stock bool:Job_IsValidVehicle(playerid, vehicleid)
stock bool:Job_IsValidCheckpoint(playerid, checkpointid)
stock Job_Cancel(playerid)
```

Ini mengurangi duplikasi dan membuat semua job memiliki standar validasi yang sama.

## F. Prioritas pengerjaan

### Prioritas 1 — segera

1. Perbaiki pembayaran ganda Pelaut.
2. Tambahkan guard anti-double-reward pada semua finish checkpoint.
3. Pastikan cleanup state pada disconnect/death/change job.
4. Validasi request Cargo dengan request ID dan owner.

### Prioritas 2

1. Audit setiap callback progress pada Farmer, Butcher, Miner, Lumberjack, Peternak, dan Tailor.
2. Pastikan item selalu dikurangi tepat satu kali sebelum reward diberikan.
3. Pastikan checkpoint hanya dapat menyelesaikan job aktif milik player tersebut.

### Prioritas 3

1. Pusatkan konfigurasi reward.
2. Hitung pendapatan bersih per jam setiap job.
3. Refactor timer job besar dan kurangi scan global.
4. Tambahkan transaction log untuk semua pembayaran job.

## Status

Audit statis selesai dan menghasilkan temuan awal di atas. Kode belum diubah pada audit ini. Temuan A1 adalah kandidat bug yang paling jelas dan sebaiknya dipatch terlebih dahulu, kemudian dilakukan audit dinamis/in-game untuk memastikan callback dan cleanup tidak bisa dipicu ulang.
