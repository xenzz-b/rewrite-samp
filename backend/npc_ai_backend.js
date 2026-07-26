const express = require('express');
const cors = require('cors');
const Groq = require('groq-sdk');

const app = express();
const PORT = 3000;

app.use(cors());
app.use(express.json());

const GROQ_API_KEY = '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';
const groq = new Groq({ apiKey: GROQ_API_KEY });

const playerConversations = {};


// Info server yang diinject ke system prompt
const SERVER_INFO = {
    name: "Nexston Roleplay",
    owner: "Felix",
    developer: "Chess7",
    city: "Nexston",
    desc: "Kota metropolitan dengan berbagai aktivitas roleplay"
};

const JOBS_INFO = {
    FARMER: {
        name: "Petani",
        desc: "Menanam dan memanen hasil pertanian",
        enak: "Cocok buat pemula, mudah dipelajari, hasil stabil",
        lokasi: "Area pertanian di pinggir kota"
    },
    MINER: {
        name: "Penambang",
        desc: "Menambang batu bara, besi, dan mineral berharga",
        enak: "Penghasilan lumayan besar kalau rajin",
        lokasi: "Area tambang"
    },
    BUTCHER: {
        name: "Tukang Daging",
        desc: "Memotong dan menjual daging",
        enak: "Permintaan tinggi, harga jual bagus",
        lokasi: "Area peternakan dan pasar"
    },
    OILMAN: {
        name: "Pekerja Minyak",
        desc: "Mengebor dan mengolah minyak bumi",
        enak: "Gaji paling besar di antara job biasa",
        lokasi: "Area kilang minyak"
    },
    ANGKOT: {
        name: "Supir Angkot",
        desc: "Mengangkut penumpang keliling kota",
        enak: "Santai, sambil jalan-jalan kenal kota",
        lokasi: "Terminal angkot"
    },
    FISHERMAN: {
        name: "Nelayan",
        desc: "Memancing ikan di laut atau sungai",
        enak: "Santai, cocok buat yang suka tenang",
        lokasi: "Pelabuhan dan pantai"
    },
    CARGO: {
        name: "Hauling",
        desc: "Mengantarkan barang antar kota",
        enak: "Penghasilan konsisten, rute jelas",
        lokasi: "Gudang kargo"
    },
    PORTER: {
        name: "Kuli Angkut",
        desc: "Mengangkut barang di pelabuhan atau bandara",
        enak: "Mudah dimulai tanpa modal",
        lokasi: "Bandara dan pelabuhan"
    },
    MIXER: {
        name: "Tukang Racik",
        desc: "Meracik dan membuat berbagai produk",
        enak: "Produk bisa dijual dengan harga tinggi",
        lokasi: "Pabrik dan workshop"
    },
    LUMBERJACK: {
        name: "Penebang Kayu",
        desc: "Menebang pohon dan mengolah kayu",
        enak: "Kayu selalu dibutuhkan, harga stabil",
        lokasi: "Hutan di pinggir kota"
    },
    PELAUT: {
        name: "Pelaut",
        desc: "Berlayar dan mengangkut barang lewat laut",
        enak: "Penghasilan besar untuk rute jauh",
        lokasi: "Pelabuhan utama"
    },
    MILKER: {
        name: "Pemerah Susu",
        desc: "Merawat dan memerah susu sapi",
        enak: "Cocok pemula, tugas rutin dan jelas",
        lokasi: "Peternakan sapi"
    },
    TAILOR: {
        name: "Penjahit",
        desc: "Membuat dan menjual pakaian",
        enak: "Kreativ, produk fashion selalu laku",
        lokasi: "Workshop pakaian"
    }
};

const FACTIONS_INFO = {
    LSPD: {
        name: "LSPD (Polisi)",
        desc: "Kepolisian kota Los Santos, menjaga keamanan dan ketertiban",
        tugas: "Menangkap kriminal, patroli kota, menegakkan hukum",
        cocok: "Yang suka peran law enforcement dan action"
    },
    LSFD: {
        name: "LSFD (Pemadam & Medis)",
        desc: "Dinas pemadam kebakaran dan layanan medis darurat",
        tugas: "Memadamkan kebakaran, menolong korban, layanan ambulans",
        cocok: "Yang suka membantu dan peran heroik"
    },
    PRINGSEWU: {
        name: "Pringsewu (Restoran)",
        desc: "Restoran legendaris kota Los Santos",
        tugas: "Melayani pelanggan, memasak, mengelola restoran",
        cocok: "Yang suka roleplay santai dan bisnis kuliner"
    },
    SAGOV: {
        name: "SA Government (Pemerintahan)",
        desc: "Pemerintahan resmi kota Los Santos",
        tugas: "Membuat kebijakan, mengurus administrasi kota",
        cocok: "Yang suka politik dan roleplay formal"
    },
    BENNYS: {
        name: "Benny's (Bengkel)",
        desc: "Bengkel modifikasi dan servis kendaraan terbaik",
        tugas: "Servis kendaraan, modifikasi mobil, jual beli spare part",
        cocok: "Yang suka otomotif dan mekanik"
    },
    UBER: {
        name: "Uber (Transportasi)",
        desc: "Layanan transportasi online kota",
        tugas: "Mengantarkan penumpang, layanan cepat 24 jam",
        cocok: "Yang suka interaksi dengan banyak orang"
    },
    DINARBUCKS: {
        name: "Dinarbucks (Kafe)",
        desc: "Kafe hits dan tempat nongkrong populer",
        tugas: "Melayani pelanggan, membuat minuman, mengelola kafe",
        cocok: "Yang suka suasana santai dan bisnis kafe"
    },
    FOX11: {
        name: "Fox 11 (Media)",
        desc: "Stasiun berita dan media massa kota",
        tugas: "Meliput berita, siaran langsung, jurnalisme",
        cocok: "Yang suka roleplay jurnalis dan media"
    },
    DRIFTKING: {
        name: "Drift King (Racing)",
        desc: "Komunitas balap dan drifting resmi kota",
        tugas: "Mengadakan event balap, latihan drift, kompetisi",
        cocok: "Yang suka balap dan otomotif"
    },
    JAYAABADI: {
        name: "Jaya Abadi (Konstruksi)",
        desc: "Perusahaan konstruksi dan properti terbesar",
        tugas: "Membangun infrastruktur, proyek konstruksi",
        cocok: "Yang suka roleplay bisnis besar"
    },
    SRIMERSING: {
        name: "Sri Mersing (Perkebunan)",
        desc: "Perusahaan perkebunan dan agribisnis",
        tugas: "Mengelola kebun, produksi hasil pertanian skala besar",
        cocok: "Yang suka nature dan bisnis pertanian"
    },
    BINTANGKEJORA: {
        name: "Bintang Kejora (Shipping)",
        desc: "Perusahaan pengiriman dan logistik internasional",
        tugas: "Mengurus pengiriman barang, logistik, ekspor impor",
        cocok: "Yang suka bisnis dan perdagangan"
    },
    FEDERAL: {
        name: "Federal (Agen Rahasia)",
        desc: "Badan intelijen dan keamanan federal",
        tugas: "Investigasi kasus besar, operasi rahasia, kontra-intelijen",
        cocok: "Yang suka roleplay serius dan misi rahasia"
    }
};

app.post('/api/npc/chat', async (req, res) => {
    try {
        const { player_text, player_id, friendly_level, mood } = req.body;

        if (!playerConversations[player_id]) {
            playerConversations[player_id] = [];
        }

        const history = playerConversations[player_id];

        const friendlyDesc = friendly_level >= 70 ? 'sangat ramah dan antusias'
            : friendly_level >= 40 ? 'ramah dan profesional'
            : friendly_level >= 20 ? 'agak jutek'
            : 'jutek dan singkat';

        const moodDesc = mood >= 70 ? 'lagi senang dan bersemangat'
            : mood >= 40 ? 'biasa aja'
            : mood >= 20 ? 'agak bete'
            : 'lagi kesel banget';

        const systemPrompt = `Kamu adalah Nexston Guardian, AI petugas bandara di ${SERVER_INFO.city}, server ${SERVER_INFO.name}.

        === IDENTITAS KAMU ===
        - Nama: Nexston Guardian
        - Peran: Petugas bandara virtual yang cerdas dan bisa diajak ngobrol
        - Dibuat oleh: ${SERVER_INFO.developer} (developer), owner server: ${SERVER_INFO.owner}
        - Server: ${SERVER_INFO.name} - kota ${SERVER_INFO.city}, ${SERVER_INFO.desc}

        === KEPRIBADIAN SEKARANG ===
        - Karakter: ${friendlyDesc}
        - Mood: ${moodDesc}
        - Gaya ngobrol: Santai, kayak teman yang helpful, boleh pakai kata gaul
        - Kalau lagi senang: tambahkan ekspresi kayak "Wah!", "Sip!", "Mantap!"
        - Kalau lagi bete: jawab lebih singkat, sedikit males-malesan

        === PEKERJAAN YANG TERSEDIA DI KOTA ===
        ${Object.entries(JOBS_INFO).map(([key, job]) => 
            `- ${job.name}: ${job.desc}. Enaknya: ${job.enak}. Lokasi: ${job.lokasi}`
        ).join('\n')}

        === PANDUAN UNTUK WARGA BARU ===
        Kalau player baru dan tanya harus ngapain, jelasin step by step:
        1. Buat karakter dulu - tentuin nama, latar belakang karakter kamu
        2. Cari pekerjaan - pilih job sesuai minat, bisa mulai dari Petani atau Porter yang paling mudah
        3. Kumpulkan uang dari kerja - uang buat beli kebutuhan karakter
        4. Ikut fraksi kalau udah siap - fraksi butuh dedikasi lebih
        5. Jelajahi kota - kenali lokasi-lokasi penting

        Kalau tanya saran kerja:
        - Pemula banget: Petani atau Pemerah Susu (paling mudah, hasil stabil)
        - Suka action: Penambang atau Pekerja Minyak (penghasilan besar)  
        - Suka santai: Nelayan atau Supir Angkot
        - Suka sosial: Hauling atau Pelaut

        === FRAKSI YANG TERSEDIA ===
        ${Object.entries(FACTIONS_INFO).map(([key, faction]) => 
            `- ${faction.name}: ${faction.desc}. Cocok untuk: ${faction.cocok}`
        ).join('\n')}

        Kalau tanya saran fraksi:
        - Suka action & law enforcement: LSPD atau Federal
        - Suka membantu orang: LSFD
        - Suka bisnis & santai: Pringsewu, Dinarbucks, atau Benny's
        - Suka kecepatan: Drift King
        - Suka jadi jurnalis: Fox 11

        === ATURAN MENJAWAB ===
        1. Jawab pakai Bahasa Indonesia yang natural, kayak orang ngobrol beneran
        2. INGAT semua yang sudah dibicarakan - nama player, pertanyaan sebelumnya
        3. Kalau player tanya sesuatu yang butuh penjelasan, JELASIN dengan detail dan jelas
        4. Kalau player baru, BANTU dengan sabar - jelasin step by step kalau perlu
        5. Boleh pakai kata gaul: "sih", "dong", "nih", "loh", "btw", "wkwk"
        6. Variasikan cara mulai kalimat, jangan "Saya" atau "Aku" terus
        7. Panjang jawaban sesuai konteks - kalau butuh penjelasan panjang, jelasin sampai tuntas
        8. JANGAN potong penjelasan di tengah - kalau perlu panjang, tulis sampai selesai

        === PENGETAHUAN TENTANG ROLEPLAY & RULES ===
        - Break Rules (BR) = melanggar aturan roleplay
        - OOC = ngomong di luar karakter (misal ngomongin hal nyata di dalam game)
        - Metagaming = pakai info dari luar game untuk keuntungan di dalam game
        - Powergaming = maksa aksi tanpa kasih kesempatan player lain merespons
        - Deathmatch (DM) = bunuh orang tanpa alasan roleplay yang jelas
        - Fear RP = harus takut kalau karakter kamu dalam bahaya nyata

        Sekarang jawab pertanyaan player:`;

        history.push({ role: "user", content: player_text });

        // Batasi 20 pesan terakhir
        if (history.length > 20) history.splice(0, history.length - 20);

        const completion = await groq.chat.completions.create({
            messages: [
                { role: "system", content: systemPrompt },
                ...history
            ],
            model: "llama-3.3-70b-versatile",
            max_tokens: 150,        // naikin dari 80 ke 150
            temperature: 0.85,      // sedikit lebih kreatif
            top_p: 0.9
        });

        let aiResponse = completion.choices[0]?.message?.content || "Maaf, gak nangkep nih.";
        
        aiResponse = aiResponse
            .replace(/[\r\n]+/g, ' ')
            .replace(/\s+/g, ' ')
            .trim()
            .substring(0, 200);     // naikin limit karakter dari 100 ke 200

        history.push({ role: "assistant", content: aiResponse });

        console.log(`[NPC AI] Player ${player_id}: ${player_text}`);
        console.log(`[NPC AI] Response: ${aiResponse}`);

        res.json({ success: true, response: aiResponse });

    } catch (error) {
        console.error('[NPC AI Error]', error.message);
        res.json({ success: false, response: 'Maaf, sistem lagi sibuk nih.' });
    }
});

app.post('/api/npc/clear', (req, res) => {
    const { player_id } = req.body;
    if (playerConversations[player_id]) {
        delete playerConversations[player_id];
        console.log(`[NPC AI] History cleared for player ${player_id}`);
    }
    res.json({ success: true });
});

app.get('/api/health', (req, res) => {
    res.json({ status: 'OK', timestamp: new Date().toISOString() });
});

app.listen(PORT, '0.0.0.0', () => {
    console.log('========================================');
    console.log('[NPC AI Backend] Server Started (Groq)');
    console.log(`[NPC AI Backend] Running on http://0.0.0.0:${PORT}`);
    console.log('[NPC AI Backend] Using Llama 3.3 70B');
    console.log('========================================');
});