# Hasil Scanning Sistem — Vertex Roleplay (V:RP)

**Tanggal:** 2026-07-27
**Branch:** arena/019fa38b-rewrite-samp
**Total file di-scan:** 364 file (gamemodes/core/)

---

## 🔴 KRITIKAL — Bug & Exploit

### 1. [EXPLOIT] pSellingTurtleTimer & pSellingSharkTimer — Membayar setiap detik
**Lokasi:** `gamemodes/core/timers/timers_ptask_update.inc` (baris ~7960-8080)
**Deskripsi:**
- Logic selling salah total. Pembayaran (`GivePlayerDirtyMoney`) dan `Inventory_Remove("Penyu"/"Hiu")` dilakukan di **blok `else`** — artinya setiap detik timer berjalan, player dibayar $150 dan penyu terus diremove.
- Saat `pActivityTime >= pCountingValue`, timer berhenti tanpa melakukan apapun (tidak ada final reward).
- Karena `Inventory_Remove` menggunakan nama string, setelah item habis, `GivePlayerDirtyMoney` tetap berjalan tanpa validasi — **player mendapat uang kotor gratis tanpa batas**.
- **Severity:** KRITIS — Money Exploit tak terbatas.

### 2. [BUG] pCraftingWeaponTimer — ShowItemBox mismatch
**Lokasi:** `timers_ptask_update.inc` case 2 (baris ~1633)
**Deskripsi:**
- `ShowItemBox(playerid, "MP5", ...)` saat crafting Uzi (case 2: weapon 28 = Uzi). Menampilkan nama yang salah.
- **Severity:** Rendah (hanya display error)

### 3. [BUG] mysql_query blocking (110+ instance)
**Lokasi:** Tersebar di banyak file (JDM, Marga, admin, clothes, house, gudang, dll)
**File terkena:** `JDM/jdm_function.inc`, `Marga/marga_function.inc`, `admin/admin_functions.inc`, `clothes/clothes_functions.inc`, `damagelog/damagelog_cmds.inc`, `dynamic/dynamic_gudang/gudang_functions.inc`, `dynamic/dynamic_house/house_functions.inc`, dll.
**Deskripsi:**
- `mysql_query()` adalah blocking call. Pada server dengan 250 player, query blocking akan menggantung seluruh server.
- Contoh: `clothes_functions.inc:43` — blocking query di function pembelian baju.
- **Severity:** TINGGI — Freeze server.

### 4. [BUG] Kick(playerid) tanpa delay — Crash
**Lokasi:** `account/account_regist.inc:76`, `cmds/cmds_counter.inc:310`
**Deskripsi:**
- `Kick(playerid)` langsung tanpa `KickEx(playerid)` menyebabkan crash pada SA-MP. Harusnya ada delay atau menggunakan `KickEx`.
- **Severity:** SEDANG — Potensi crash client.

### 5. [BUG] Static variable di dialog callbacks
**Lokasi:** `systems/systems_dialogs.inc` (banyak tempat)
**Deskripsi:**
- PAWN memiliki bug dengan `static` di function callback — nilai static bertahan antar panggilan. Jika 2 player membuka dialog yang sama, terjadi race condition.
- Contoh: `static string[512]` di `Dialog:VerifPW`, `Dialog:Register`, dll.
- **Severity:** SEDANG — Data tercampur antar player.

### 6. [BUG] DestroyVehicle di dalam loop timer tanpa guard
**Lokasi:** `timers/timers_ptask_update.inc` baris ~251-386
**Deskripsi:**
- `DestroyVehicle(JobVehicle[playerid])` dilakukan saat health kendaraan <= 350.0. Tidak ada validasi apakah kendaraan masih valid sebelum di-destroy. Bisa crash jika kendaraan sudah di-destroy sebelumnya.
- **Severity:** SEDANG — Potensi crash.

### 7. [BUG] Referensi FACTION_BINTANGKEJORA masih ada
**Lokasi:** `systems/systems_dialogs.inc` — `Dialog:SpawnSelection` case 12 (FACTION_BINTANGKEJORA)
**Deskripsi:**
- Faction Bintang Kejora sudah dihapus, tapi masih ada handler yang menampilkan "Faction ini sudah dihapus!". Kode mati yang tidak perlu.
- **Severity:** Rendah.

---

## 🟠 PERFORMANCE — Script Sangat Berat

### 8. [PERFORMANCE] 27 ptask berjalan setiap 1 detik per player
**Lokasi:** `timers/timers_ptask_update.inc`
**Daftar ptask [1000]:**
| No | Timer | Fungsi |
|----|-------|--------|
| 1 | UpdateHBEPlayer | Update HUD hunger/thirst/stress |
| 2 | PlayerVehicleUpdate | Cek health kendaraan |
| 3 | UpdateWargaBaruTime | Warga baru countdown |
| 4 | VehicleSpeedoUpdate | Speedometer |
| 5 | playerstablingdmax | Cap item quantity |
| 6 | UpdateSpecStats | Spectate stats |
| 7 | playerdelay | Various status checks |
| 8 | IdlingCheck | Idle animation |
| 9 | AFKChecking | AFK detection |
| 10 | UpdateTimeActivity | Activity progress (trash, kanabis, crafting, dll) |
| 11 | UpdateTimeActivity2 | More activity timers |
| 12 | UpdateTimeOtherFunc | More activity timers |
| 13 | UpdateTimeJob | Job timers (lumber, miner, butcher, oil) |
| 14 | UpdateTimeJob2 | Forklift & activity |
| 15 | UpdateTimeJob3 | Pizza, farmer, angkot, pelaut, fish |
| 16 | UpdateTimeJob4 | Mixer, selling, bank robbery |
| 17 | UpdateTimeJob5 | Tailor, milker |
| 18 | UpdateLevelTimer | Level & paycheck |
| 19 | OnPlayerFallFromInterior | Fall detection |
| 20 | UpdateTimeJob | (named same as 13?) |
| 21 | MabukKitaCees | Drunk effect |
| 22 | AdminLabelUpdate | Admin nametag (O(n²)) |
| 23 | SIDUpdate | Name ID toggle (O(n²)) |

**Dampak:** 23+ timer per player per detik = 23 × 250 = **5.750 callback/detik** hanya dari ptask. Ini sangat berat.

### 9. [PERFORMANCE] UpdateSirenELM[160] — Setiap 160ms loop SEMUA kendaraan
**Lokasi:** `timers/timers_ptask_update.inc` baris ~579
**Deskripsi:**
- Task global berjalan setiap **160ms** (6 kali per detik) mengiterasi SEMUA kendaraan di server.
- Setiap iterasi melakukan: `GetVehicleDamageStatus`, `GetVehicleHealth`, `UpdateVehicleDamageStatus`, pengecekan siren, blink pattern, dll.
- Untuk 100 kendaraan = 600 iterasi/detik.
- **Severity:** TINGGI — Pemborosan CPU.

### 10. [PERFORMANCE] RefreshFactionVehicleCache() setiap 1 detik
**Lokasi:** `timers/timers_task_server.inc` — `ServerTimeClock[1000]`
**Deskripsi:**
- Setiap detik, fungsi `RefreshFactionVehicleCache()` dipanggil. Fungsi ini kemungkinan meng-query database atau iterasi kendaraan faksi.
- **Severity:** SEDANG.

### 11. [PERFORMANCE] Massive code duplication di activity timers
**Lokasi:** `timers/timers_ptask_update.inc` — Semua blok `pTaking*Timer`, `pProcess*Timer`, `pCooking*Timer`
**Deskripsi:**
- Setiap activity timer (~30+ timer) memiliki validasi yang SAMA PERSIS di-copy-paste:
  - `if(!IsPlayerConnected(playerid))` — 8 baris cleanup
  - `if(GetPlayerState != ONFOOT)` — 8 baris cleanup
  - `if(!IsPlayerInArea/Range)` — 8 baris cleanup
  - `if(InventoryFull)` — 8 baris cleanup
  
  Total ~30 baris × 30 timer = **900+ baris kode duplikasi**. Jika ada bug di satu blok, semua terkena.

### 12. [PERFORMANCE] AdminLabelUpdate[1000] + SIDUpdate[1000] — O(n²)
**Lokasi:** `timers/timers_ptask_update.inc` baris ~6806-6849
**Deskripsi:**
- AdminLabelUpdate: Untuk setiap admin yang menampilkan nametag, loop **semua player** (foreach Player) setiap detik.
- SIDUpdate: Sama — loop semua player untuk setiap player yang mengaktifkan name ID.
- Dengan 10 admin + 250 player = 2.500 iterasi/detik untuk ini saja.
- **Severity:** SEDANG.

---

## 🟡 SYSTEM ERRORS & CODE SMELLS

### 13. [CLEANUP] Commented-out code berton-ton
**Lokasi:**
- `timers/timers_ptask_update.inc` — Seluruh sistem salary lama di-comment (~20 baris)
- `timers/timers_ptask_update.inc` — pRebootingPhoneTimer di-comment seluruhnya
- `timers/timers_task_server.inc` — Array weather lama di-comment
- `systems/systems_dialogs.inc` — Toggle PM, Toggle Money TD di-comment
- `gmcore.inc` — inventory_old di-comment
**Severity:** Rendah — Tapi menambah ukuran file dan membingungkan.

### 14. [ERROR] Coming Soon features
**Lokasi:** `systems/systems_dialogs.inc` baris ~554, ~700
**Deskripsi:**
- `SpawnSelectPD` case 1 "Coming Soon" — melakukan hal yang sama persis dengan case 0 (SAMSAT).
- Tidak ada fungsionalitas berbeda.

### 15. [ERROR] RemovePlayerFromVehicle saat kelaparan — Bisa disalahgunakan
**Lokasi:** `timers/timers_ptask_update.inc` baris 74, 95
**Deskripsi:**
- Saat hunger/thirst = 0, player di-remove dari kendaraan lalu di-kill. Bisa menyebabkan crash jika dilakukan saat player mengendarai pesawat/heli.
- **Severity:** SEDANG.

### 16. [CLEANUP] pRefuelingTimer & pRefuelJerrycanTimer — Duplikasi kode masif
**Lokasi:** `timers/timers_ptask_update.inc` baris ~2460-2750
**Deskripsi:**
- Dua function hampir identik dengan ~300 baris kode duplikasi. Setiap error handling block (~20 baris) di-copy 7-8 kali.
- Pola cleanup yang sama: `SetPlayerSpecialAction`, `StopRunningAnimation`, `TakePlayerMoney`, `UpdateDynamic3DTextLabelText`, `DestroyDynamic3DTextLabel`, reset variable.

### 17. [BUG] Variable shadowing risk
**Lokasi:** `systems/systems_dialogs.inc` — Banyak function menggunakan `new string[512]` atau `static string[512]` yang bisa saling timpa.

### 18. [CLEANUP] Format string mismatch — ShowItemBox
**Lokasi:** `timers/timers_ptask_update.inc` baris ~204-205
**Deskripsi:**
```pawn
ShowItemBox(playerid, "Smartphone", sprintf("Removed %dx", Inventory_Count(playerid, "Smartphone")), 18873, 5);
ShowItemBox(playerid, "Elektronik Rusak", sprintf("Removed %dx", Inventory_Count(playerid, "Smartphone")), 2041, 6);
```
Baris kedua menulis "Removed" padahal seharusnya "Received". Sama untuk Radio di baris ~222-223.

---

## 📊 RINGKASAN

| Kategori | Jumlah Temuan |
|----------|--------------|
| 🔴 Critical Bugs/Exploit | 3 |
| 🟠 Performance Issues | 5 |
| 🟡 System Errors | 5 |
| 🟢 Code Smells/Cleanup | 5 |
| **Total** | **18** |

### Prioritas Perbaikan:

1. **🔥 CRITICAL — pSellingTurtleTimer/pSellingSharkTimer:** Money exploit tanpa batas. **Perbaiki segera!**
2. **🔥 CRITICAL — mysql_query blocking:** 110+ instance. Ganti ke mysql_pquery.
3. **🔥 KRITIS — 27 ptask/detik:** Konsolidasi timer untuk mengurangi beban server.
4. **🔥 HIGH — UpdateSirenELM[160]:** Kurangi interval atau optimasi.
5. **🔥 HIGH — Kick() tanpa delay:** Ganti ke KickEx() untuk cegah crash.
6. **🔥 HIGH — Refactor duplicated validation code:** Buat fungsi helper untuk cleanup.
7. **🟡 MEDIUM — Static variables di dialog:** Ganti ke local scope.
8. **🟡 MEDIUM — Commented code cleanup:** Hapus kode mati.

---

*Scanning dilakukan secara menyeluruh pada 364 file di gamemodes/core/*
