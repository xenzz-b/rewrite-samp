// config/constants.js
// ============================================
// KONFIGURASI SERVER
// ============================================

const SERVER_INFO = {
    name: "Nexston Roleplay",
    owner: "Felix",
    developer: "Chess7",
    city_ic: "Nexston",  // Nama kota In Character
    city_desc: "Kota metropolitan dengan berbagai aktivitas roleplay",
    region: "San Andreas"  // Region/wilayah
};

// ============================================
// JOB INFO (13 JENIS PEKERJAAN)
// ============================================

const JOBS_INFO = {
    FARMER: {
        id: 1,
        name: "Petani",
        desc: "Menanam dan memanen hasil pertanian seperti padi, jagung, dan sayuran",
        enak: "Cocok buat pemula, mudah dipelajari, hasil stabil",
        lokasi: "Area pertanian di pinggir kota (timur laut kota)",
        modal: "Minimal, cukup beli bibit dan alat pertanian",
        penghasilan: "Rp 5.000 - Rp 15.000 per panen",
        skill: "Kesabaran dan ketekunan"
    },
    MINER: {
        id: 2,
        name: "Penambang",
        desc: "Menambang batu bara, besi, tembaga, dan mineral berharga",
        enak: "Penghasilan lumayan besar kalau rajin, bisa dapat mineral langka",
        lokasi: "Area tambang di pegunungan timur",
        modal: "Beli beliung dan peralatan tambang",
        penghasilan: "Rp 10.000 - Rp 25.000 per trip",
        skill: "Ketelitian dan fisik kuat"
    },
    BUTCHER: {
        id: 3,
        name: "Tukang Daging",
        desc: "Memotong dan menjual daging dari hewan buruan atau ternak",
        enak: "Permintaan tinggi, harga jual bagus, bisa buka lapak sendiri",
        lokasi: "Area peternakan dan pasar tradisional",
        modal: "Pisau daging dan tempat jualan",
        penghasilan: "Rp 7.000 - Rp 20.000 per hari",
        skill: "Ketelitian dan kebersihan"
    },
    OILMAN: {
        id: 4,
        name: "Pekerja Minyak",
        desc: "Mengebor dan mengolah minyak bumi menjadi bahan bakar",
        enak: "Gaji paling besar di antara job biasa, cocok yang mau kaya cepat",
        lokasi: "Area kilang minyak di selatan kota",
        modal: "Modal besar untuk peralatan bor",
        penghasilan: "Rp 20.000 - Rp 50.000 per trip",
        skill: "Fisik kuat dan tahan panas"
    },
    ANGKOT: {
        id: 5,
        name: "Supir Angkot",
        desc: "Mengangkut penumpang keliling kota dengan rute tetap",
        enak: "Santai, sambil jalan-jalan kenal kota, bisa sambil dengerin musik",
        lokasi: "Terminal angkot di pusat kota",
        modal: "Kendaraan angkot (bisa rental)",
        penghasilan: "Rp 8.000 - Rp 15.000 per hari",
        skill: "Menguasai rute kota"
    },
    FISHERMAN: {
        id: 6,
        name: "Nelayan",
        desc: "Memancing ikan di laut atau sungai, menjual ke pasar",
        enak: "Santai, cocok buat yang suka tenang dan pemandangan laut",
        lokasi: "Pelabuhan dan pantai di barat kota",
        modal: "Joran pancing atau perahu kecil",
        penghasilan: "Rp 5.000 - Rp 12.000 per hari",
        skill: "Kesabaran dan mengetahui spot ikan"
    },
    CARGO: {
        id: 7,
        name: "Hauling",
        desc: "Mengantarkan barang antar kota dan antar pulau",
        enak: "Penghasilan konsisten, rute jelas, bisa keliling kota",
        lokasi: "Gudang kargo di pelabuhan dan bandara",
        modal: "Truk kargo (bisa rental)",
        penghasilan: "Rp 15.000 - Rp 30.000 per pengantaran",
        skill: "Menguasai rute dan disiplin waktu"
    },
    PORTER: {
        id: 8,
        name: "Kuli Angkut",
        desc: "Mengangkut barang di pelabuhan atau bandara",
        enak: "Mudah dimulai tanpa modal, cocok untuk pemula",
        lokasi: "Bandara dan pelabuhan",
        modal: "Minimal, cukup tenaga",
        penghasilan: "Rp 3.000 - Rp 8.000 per jam",
        skill: "Fisik kuat dan kecepatan"
    },
    MIXER: {
        id: 9,
        name: "Tukang Racik",
        desc: "Meracik dan membuat berbagai produk seperti minuman dan makanan",
        enak: "Produk bisa dijual dengan harga tinggi, kreativitas",
        lokasi: "Pabrik dan workshop di area industri",
        modal: "Modal sedang untuk bahan baku",
        penghasilan: "Rp 10.000 - Rp 25.000 per produk",
        skill: "Kreativitas dan ketelitian"
    },
    LUMBERJACK: {
        id: 10,
        name: "Penebang Kayu",
        desc: "Menebang pohon dan mengolah kayu menjadi papan",
        enak: "Kayu selalu dibutuhkan, harga stabil, bisa buka usaha mebel",
        lokasi: "Hutan di pinggir kota utara",
        modal: "Kapak dan peralatan tebang",
        penghasilan: "Rp 7.000 - Rp 15.000 per pohon",
        skill: "Fisik kuat dan tahu jenis kayu"
    },
    PELAUT: {
        id: 11,
        name: "Pelaut",
        desc: "Berlayar dan mengangkut barang lewat laut antar pulau",
        enak: "Penghasilan besar untuk rute jauh, bisa lihat pemandangan laut",
        lokasi: "Pelabuhan utama",
        modal: "Kapal (bisa rental) dan izin berlayar",
        penghasilan: "Rp 25.000 - Rp 50.000 per pelayaran",
        skill: "Navigasi dan pengalaman berlayar"
    },
    MILKER: {
        id: 12,
        name: "Pemerah Susu",
        desc: "Merawat dan memerah susu sapi perah di peternakan",
        enak: "Cocok pemula, tugas rutin dan jelas, hasil stabil",
        lokasi: "Peternakan sapi di area pertanian",
        modal: "Minimal, cukup tenaga",
        penghasilan: "Rp 4.000 - Rp 10.000 per hari",
        skill: "Kesabaran dan perawatan hewan"
    },
    TAILOR: {
        id: 13,
        name: "Penjahit",
        desc: "Membuat dan menjual pakaian, seragam, dan aksesoris",
        enak: "Kreatif, produk fashion selalu laku, bisa buka butik sendiri",
        lokasi: "Workshop pakaian di pusat kota",
        modal: "Mesin jahit dan bahan kain",
        penghasilan: "Rp 8.000 - Rp 20.000 per pakaian",
        skill: "Kreativitas dan ketelitian"
    }
};

// ============================================
// FACTION INFO (13 FRAKSI)
// ============================================

const FACTIONS_INFO = {
    LSPD: {
        id: 1,
        name: "LSPD (Polisi)",
        desc: "Kepolisian kota Los Santos, menjaga keamanan dan ketertiban",
        tugas: "Menangkap kriminal, patroli kota, menegakkan hukum, melayani masyarakat",
        cocok: "Yang suka peran law enforcement dan action",
        lokasi: "Markas Kepolisian di pusat kota",
        rank: "Mulai dari Kadet sampai Kepala Kepolisian",
        gaji: "Rp 15.000 - Rp 50.000 per jam duty"
    },
    LSFD: {
        id: 2,
        name: "LSFD (Pemadam & Medis)",
        desc: "Dinas pemadam kebakaran dan layanan medis darurat",
        tugas: "Memadamkan kebakaran, menolong korban, layanan ambulans, evakuasi",
        cocok: "Yang suka membantu dan peran heroik",
        lokasi: "Kantor pemadam dan rumah sakit",
        rank: "Mulai dari Kadet sampai Kepala Dinas",
        gaji: "Rp 12.000 - Rp 40.000 per jam duty"
    },
    PRINGSEWU: {
        id: 3,
        name: "Pringsewu (Restoran)",
        desc: "Restoran legendaris kota Los Santos yang menyajikan masakan Nusantara",
        tugas: "Melayani pelanggan, memasak, mengelola restoran, event kuliner",
        cocok: "Yang suka roleplay santai dan bisnis kuliner",
        lokasi: "Restoran Pringsewu di pusat kota",
        rank: "Mulai dari Pelayan sampai Manajer",
        gaji: "Rp 8.000 - Rp 25.000 per jam duty"
    },
    SAGOV: {
        id: 4,
        name: "SA Government (Pemerintahan)",
        desc: "Pemerintahan resmi kota Los Santos",
        tugas: "Membuat kebijakan, mengurus administrasi kota, layanan publik",
        cocok: "Yang suka politik dan roleplay formal",
        lokasi: "Balai Kota",
        rank: "Mulai dari Staff sampai Walikota",
        gaji: "Rp 10.000 - Rp 35.000 per jam duty"
    },
    BENNYS: {
        id: 5,
        name: "Benny's (Bengkel)",
        desc: "Bengkel modifikasi dan servis kendaraan terbaik di kota",
        tugas: "Servis kendaraan, modifikasi mobil, jual beli spare part",
        cocok: "Yang suka otomotif dan mekanik",
        lokasi: "Benny's Motorworks di timur kota",
        rank: "Mulai dari Mekanik sampai Kepala Bengkel",
        gaji: "Rp 10.000 - Rp 30.000 per jam duty"
    },
    UBER: {
        id: 6,
        name: "Uber (Transportasi)",
        desc: "Layanan transportasi online 24 jam di kota Los Santos",
        tugas: "Mengantarkan penumpang ke berbagai lokasi, layanan cepat",
        cocok: "Yang suka interaksi dengan banyak orang",
        lokasi: "Seluruh kota (basis online)",
        rank: "Mulai dari Driver sampai Supervisor",
        gaji: "Rp 5.000 - Rp 20.000 per penumpang"
    },
    DINARBUCKS: {
        id: 7,
        name: "Pinky Tiger (Kafe)",
        desc: "Kafe hits dan tempat nongkrong populer di kalangan anak muda",
        tugas: "Melayani pelanggan, membuat minuman, mengelola kafe",
        cocok: "Yang suka suasana santai dan bisnis kafe",
        lokasi: "Pinky Tiger Cafe di pusat kota",
        rank: "Mulai dari Barista sampai Manajer",
        gaji: "Rp 7.000 - Rp 20.000 per jam duty"
    },
    FOX11: {
        id: 8,
        name: "Fox 11 (Media)",
        desc: "Stasiun berita dan media massa terkemuka di kota",
        tugas: "Meliput berita, siaran langsung, jurnalisme investigasi",
        cocok: "Yang suka roleplay jurnalis dan media",
        lokasi: "Gedung Fox 11 di pusat kota",
        rank: "Mulai dari Reporter sampai Pemimpin Redaksi",
        gaji: "Rp 10.000 - Rp 30.000 per berita"
    },
    DRIFTKING: {
        id: 9,
        name: "Drift King (Racing)",
        desc: "Komunitas balap dan drifting resmi kota",
        tugas: "Mengadakan event balap, latihan drift, kompetisi, tuning",
        cocok: "Yang suka balap dan otomotif",
        lokasi: "Sirkuit Drift King di timur kota",
        rank: "Mulai dari Member sampai Team Leader",
        gaji: "Rp 15.000 - Rp 50.000 per event"
    },
    JAYAABADI: {
        id: 10,
        name: "Jaya Abadi (Konstruksi)",
        desc: "Perusahaan konstruksi dan properti terbesar di kota",
        tugas: "Membangun infrastruktur, proyek konstruksi, renovasi",
        cocok: "Yang suka roleplay bisnis besar",
        lokasi: "Kantor Jaya Abadi di area industri",
        rank: "Mulai dari Pekerja sampai Direktur",
        gaji: "Rp 12.000 - Rp 40.000 per proyek"
    },
    SRIMERSING: {
        id: 11,
        name: "Sri Mersing (Resto)",
        desc: "Restoran mewah dengan masakan Melayu dan Indonesia",
        tugas: "Melayani pelanggan VIP, memasak, mengelola restoran",
        cocok: "Yang suka roleplay fine dining",
        lokasi: "Restoran Sri Mersing di pusat kota",
        rank: "Mulai dari Pelayan sampai Manajer",
        gaji: "Rp 10.000 - Rp 35.000 per jam duty"
    },
    BINTANGKEJORA: {
        id: 12,
        name: "Bintang Kejora (Food & Beverage)",
        desc: "Perusahaan katering dan minuman kemasan terkemuka",
        tugas: "Memproduksi makanan/minuman, distribusi, event catering",
        cocok: "Yang suka bisnis F&B dan logistik",
        lokasi: "Pabrik Bintang Kejora di area industri",
        rank: "Mulai dari Staff Produksi sampai Direktur",
        gaji: "Rp 10.000 - Rp 35.000 per jam duty"
    },
    FEDERAL: {
        id: 13,
        name: "Federal (Agen Rahasia)",
        desc: "Badan intelijen dan keamanan federal",
        tugas: "Investigasi kasus besar, operasi rahasia, kontra-intelijen",
        cocok: "Yang suka roleplay serius dan misi rahasia",
        lokasi: "Rahasia (tersembunyi)",
        rank: "Mulai dari Agen sampai Direktur",
        gaji: "Rp 20.000 - Rp 60.000 per misi"
    }
};

// ============================================
// COMMAND INFO
// ============================================

const COMMANDS_INFO = {
    // Roleplay Commands
    me: {
        desc: "Melakukan aksi roleplay (contoh: /me mengangguk)",
        usage: "/me [aksi]",
        category: "Roleplay"
    },
    do: {
        desc: "Mendeskripsikan sesuatu (contoh: /do suara mesin mobil)",
        usage: "/do [deskripsi]",
        category: "Roleplay"
    },
    b: {
        desc: "Chat OOC (Out of Character) di sekitar",
        usage: "/b [pesan]",
        category: "Roleplay"
    },
    ooc: {
        desc: "Chat OOC global ke semua player",
        usage: "/o [pesan]",
        category: "Roleplay"
    },
    attempt: {
        desc: "Melakukan aksi dengan sistem chance (acak berhasil/gagal)",
        usage: "/attempt [aksi]",
        category: "Roleplay"
    },
    dice: {
        desc: "Melempar dadu (1 atau 2 dadu)",
        usage: "/dice [1/2]",
        category: "Roleplay"
    },
    me: {
        desc: "Aksi roleplay (contoh: /me duduk)",
        usage: "/me [aksi]",
        category: "Roleplay"
    },
    do: {
        desc: "Deskripsi roleplay (contoh: /do suara hujan)",
        usage: "/do [deskripsi]",
        category: "Roleplay"
    },
    cc: {
        desc: "Membersihkan chat (clear chat)",
        usage: "/cc",
        category: "Utility"
    },
    pay: {
        desc: "Memberi uang ke player lain (maksimal $5.000 untuk non-admin)",
        usage: "/pay [playerid] [jumlah]",
        category: "Utility"
    },
    carry: {
        desc: "Menggendong player lain (perlu /accept carry)",
        usage: "/carry [playerid]",
        category: "Utility"
    },
    accept: {
        desc: "Menerima tawaran dari player lain (carry, buyveh, dll)",
        usage: "/accept [type]",
        category: "Utility"
    },
    myv: {
        desc: "Melihat daftar kendaraan yang dimiliki",
        usage: "/myv",
        category: "Kendaraan"
    },
    stats: {
        desc: "Melihat statistik karakter",
        usage: "/stats",
        category: "Utility"
    },
    id: {
        desc: "Mencari ID player berdasarkan nama",
        usage: "/id [nama]",
        category: "Utility"
    },
    admins: {
        desc: "Melihat daftar admin yang sedang online",
        usage: "/admins",
        category: "Utility"
    },
    flist: {
        desc: "Melihat daftar faction dan jumlah member online",
        usage: "/flist",
        category: "Faction"
    },
    fa: {
        desc: "Announcement faction (hanya untuk anggota faction)",
        usage: "/fa [pesan]",
        category: "Faction"
    },
    fhelp: {
        desc: "Melihat command khusus faction",
        usage: "/fhelp",
        category: "Faction"
    },
    delay: {
        desc: "Melihat waktu delay sidejob",
        usage: "/delay",
        category: "Job"
    },
    cook: {
        desc: "Memasak di faction restoran (Pringsewu, Dinarbucks, dll)",
        usage: "/cook",
        category: "Job"
    },
    slice: {
        desc: "Memotong bahan masakan di faction restoran",
        usage: "/slice",
        category: "Job"
    },
    pawn: {
        desc: "Menggadaikan barang di pawn shop",
        usage: "/pawn",
        category: "Job"
    }
};

// ============================================
// LOCATIONS INFO
// ============================================

const LOCATIONS_INFO = {
    bandara: {
        desc: "Bandara Internasional Los Santos - tempat check-in, keberangkatan, kedatangan, dan area drop off",
        koordinat: "1722, -2259, 13"
    },
    balai_kota: {
        desc: "Balai Kota Los Santos - tempat mengurus administrasi, membuat KTP, SIM, SKCK",
        koordinat: "1485, -1739, 13"
    },
    rumah_sakit: {
        desc: "Rumah Sakit Los Santos - tempat berobat, perawatan medis, dan respawn",
        koordinat: "1175, -1324, 13"
    },
    polisi: {
        desc: "Markas Kepolisian LSPD - tempat melapor, membuat laporan, SKCK, dan urusan kepolisian",
        koordinat: "1585, -1638, 13"
    },
    dinarbucks: {
        desc: "Pinky Tiger Cafe - kafe hits tempat nongkrong dan bekerja sebagai barista",
        koordinat: "381, -184, 1000 (interior)"
    },
    pringsewu: {
        desc: "Restoran Pringsewu - restoran legendaris masakan Nusantara",
        koordinat: "608, -1885, 6"
    },
    bennys: {
        desc: "Benny's Motorworks - bengkel modifikasi kendaraan terbaik",
        koordinat: "2058, -1895, 13"
    },
    terminal: {
        desc: "Terminal Angkot - pusat transportasi umum kota",
        koordinat: "1913, -1779, 13"
    },
    tambang: {
        desc: "Area Tambang - tempat menambang mineral dan batu bara",
        koordinat: "0, 0, 0 (belum tersedia)"
    },
    kilang_minyak: {
        desc: "Kilang Minyak - tempat bekerja sebagai pekerja minyak",
        koordinat: "0, 0, 0 (belum tersedia)"
    },
    pelabuhan: {
        desc: "Pelabuhan Los Santos - tempat nelayan dan kargo",
        koordinat: "0, 0, 0 (belum tersedia)"
    }
};

// ============================================
// RULES INFO
// ============================================

const RULES_INFO = {
    br: {
        name: "Break Rules",
        desc: "Melanggar aturan server. Konsekuensi: peringatan, jail, atau ban",
        detail: "Setiap pemain wajib mematuhi aturan server. Pelanggaran akan ditindak sesuai tingkat pelanggaran."
    },
    ooc: {
        name: "Out of Character",
        desc: "Berbicara di luar karakter (dunia nyata) di dalam game",
        detail: "OOC hanya boleh dilakukan di chat /b dan /ooc. OOC di chat roleplay (IC) dilarang."
    },
    metagaming: {
        name: "Metagaming",
        desc: "Menggunakan informasi dari luar game untuk keuntungan di dalam game",
        detail: "Contoh: menggunakan informasi dari Discord atau voice chat untuk mengetahui lokasi musuh."
    },
    powergaming: {
        name: "Powergaming",
        desc: "Memaksa aksi tanpa memberi kesempatan player lain merespon",
        detail: "Contoh: /me menembak kepala player tanpa memberi kesempatan menghindar."
    },
    dm: {
        name: "Deathmatch",
        desc: "Membunuh tanpa alasan roleplay yang jelas",
        detail: "Setiap aksi kekerasan harus memiliki latar belakang roleplay yang jelas."
    },
    fearrp: {
        name: "Fear RP",
        desc: "Karakter harus menunjukkan ketakutan saat dalam bahaya nyata",
        detail: "Jika ditodong senjata, karakter harus takut dan menurut, bukan malah melawan."
    },
    nonrp: {
        name: "Non-RP",
        desc: "Aksi yang tidak realistis dalam roleplay",
        detail: "Contoh: bunuh diri lalu respawn, terbang dengan kendaraan, dll."
    }
};

// ============================================
// SIDEJOBS DELAY INFO
// ============================================

const SIDEJOBS_INFO = {
    mowing: {
        name: "Mowing (Potong Rumput)",
        delay: "60 menit",
        desc: "Memotong rumput di area kota, hadiah $1.000 - $3.000"
    },
    sweeper: {
        name: "Sweeper (Penyapu Jalan)",
        delay: "60 menit",
        desc: "Menyapu jalan kota, hadiah $1.000 - $3.000"
    },
    forklift: {
        name: "Forklift",
        delay: "60 menit",
        desc: "Memindahkan barang dengan forklift, hadiah $2.000 - $5.000"
    },
    trash_collector: {
        name: "Trash Collector",
        delay: "60 menit",
        desc: "Mengumpulkan sampah, hadiah $1.500 - $4.000"
    },
    pizza_delivery: {
        name: "Pizza Delivery",
        delay: "60 menit",
        desc: "Mengantar pizza, hadiah $2.000 - $5.000"
    }
};

// ============================================
// CHEAT COMMANDS (TERLARANG)
// ============================================

const CHEAT_COMMANDS = [
    "tr", "menu", "dm", "ngaceng", "ngocok", "dpraumenu", "y", 
    "invisible", "invis", "marker", "rem", "fcrash", "fspawn", 
    "be", "xray", "kill", "gunspawn", "whack", "dgun", "pgun", 
    "xgun", "skema", "sekema", "cboom", "fdeath", "fkill", 
    "intoarce", "co", "zboara", "bubule", "reconnect", "recon", 
    "name", "connect", "disconnect", "massban", "massiveban", 
    "maprecord", "mapinfo", "mapsave", "mapstealer", "mapsteal", 
    "rco", "rcignite", "rchell", "startrecording", "stoprecording", 
    "savemodels", "saveremovebuildings"
];

// ============================================
// HELP MENU (Untuk pemula)
// ============================================

const HELP_MENU = {
    pemula: [
        "1. Buat karakter - tentukan nama, latar belakang, dan penampilan karakter kamu",
        "2. Pilih job - mulai dari Petani, Kuli Angkut, atau Nelayan (paling mudah)",
        "3. Cari uang - lakukan job untuk mendapatkan uang",
        "4. Beli kebutuhan - beli makanan, minuman, dan pakaian",
        "5. Belajar roleplay - gunakan /me, /do, /b untuk berinteraksi",
        "6. Cari teman - bergabung dengan faction atau komunitas",
        "7. Upgrade karakter - naik level dan beli kendaraan sendiri"
    ],
    perintah_dasar: [
        "/me [aksi] - untuk melakukan aksi roleplay",
        "/do [deskripsi] - untuk mendeskripsikan sesuatu",
        "/b [pesan] - chat OOC di sekitar",
        "/o [pesan] - chat OOC global",
        "/pay [id] [jumlah] - memberi uang",
        "/carry [id] - menggendong player",
        "/accept [type] - menerima tawaran"
    ],
    cara_naik_level: [
        "Level naik berdasarkan playtime (waktu bermain)",
        "Setiap 5 jam playtime = +1 level",
        "Level mempengaruhi job yang bisa diakses",
        "Level tinggi membuka fitur lebih banyak"
    ]
};

module.exports = {
    SERVER_INFO,
    JOBS_INFO,
    FACTIONS_INFO,
    COMMANDS_INFO,
    LOCATIONS_INFO,
    RULES_INFO,
    SIDEJOBS_INFO,
    CHEAT_COMMANDS,
    HELP_MENU
};