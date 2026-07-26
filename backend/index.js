// index.js - Nexston AI (Modular)
const express = require('express');
const cors = require('cors');

const { SERVER_INFO, JOBS_INFO, FACTIONS_INFO, COMMANDS_INFO, LOCATIONS_INFO, RULES_INFO, SIDEJOBS_INFO, CHEAT_COMMANDS, HELP_MENU } = require('./config/constants');
const { ConversationMemory } = require('./modules/memory');
const { AIService } = require('./modules/ai');

const app = express();
const PORT = process.env.PORT || 3000;

const GROQ_API_KEY = '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';

const memory = new ConversationMemory();
const aiService = new AIService(GROQ_API_KEY);

app.use(cors());
app.use(express.json());

// ================= DATA DARI CONFIG =================
const jobListShort = Object.values(JOBS_INFO).map(job => job.name).join(", ");
const factionListShort = Object.values(FACTIONS_INFO).map(f => f.name).join(", ");
const commandListShort = Object.keys(COMMANDS_INFO).slice(0, 15).map(cmd => `/${cmd}`).join(", ");

// ================= INFO LOKASI =================
const LOCATION_GUIDE = {
    balai_kota: { name: "Balai Kota Nexston", area: "Verdant Bluffs", desc: "tempat membuat KTP dan daftar pekerjaan", commands: ["/buatktp", "/daftarpekerjaan"] },
    starterpack: { name: "Starterpack", area: "Bandara Internasional Nexston", desc: "di depan pintu masuk bandara", command: "/claimsp" },
    rumah_sakit: { name: "Rumah Sakit Nexston", area: "Jefferson", desc: "tempat berobat dan respawn", commands: ["/respawn", "/obat"] },
    polisi: { name: "Markas Polisi Nexston", area: "Verdant Bluffs", desc: "tempat melapor dan buat SKCK", commands: ["/lapor", "/skck"] },
    bandara: { name: "Bandara Internasional Nexston", area: "Bandara", desc: "tempat kedatangan dan keberangkatan" },
    pantai: { name: "Carnival", area: "Carnival", desc: "area pantai untuk nelayan dan santai" }
};

// ================= PENGETAHUAN ROLEPLAY =================
const ROLEPLAY_KNOWLEDGE = `
=== PENGETAHUAN ROLEPLAY SA-MP ===
- Server: Nexston Roleplay
- Kota IC: NEXSTON (bukan Los Santos)
- Region: San Andreas

1. APA ITU ROLEPLAY?
Roleplay adalah bermain peran sebagai karakter fiksi di kota NEXSTON.

2. TIPE ROLEPLAY:
- IC (In Character): Berbicara sebagai karakter game
- OOC (Out of Character): Berbicara sebagai pemain (chat /b atau /ooc)

3. LOKASI:
- Verdant Bluffs: pusat pemerintahan (Balai Kota, Polisi)
- Jefferson: distrik medis (Rumah Sakit)
- Carnival: area pantai (nelayan, rekreasi)

4. PEMBUAT: Developer Chess7, Owner Felix

5. ATURAN DASAR:
- NO DM: Tidak boleh membunuh tanpa alasan roleplay
- NO PG: Tidak boleh memaksakan aksi
- NO MG: Tidak boleh pakai info dari luar game
- FearRP: Karakter harus takut saat dalam bahaya
`;

// ================= DETECT STYLE =================
function detectSpeechStyle(text) {
    const slangWords = ['bro','gue','gw','lo','lu','ngapain','wkwk','lah','dong','nih','sih','bang','woi','gak','ga','anjir','mantap','wassup','men','yo','sip','cuy'];
    const formalWords = ['saya','anda','apakah','mohon','terima kasih','permisi','silakan','bagaimana','maaf','tolong'];

    let slang = 0, formal = 0;
    const t = text.toLowerCase();

    slangWords.forEach(w => { if (t.includes(w)) slang++; });
    formalWords.forEach(w => { if (t.includes(w)) formal++; });

    if (slang > formal) return 'casual';
    if (formal > slang) return 'formal';
    return 'neutral';
}

// ================= DETEKSI PERTANYAAN =================
function detectNewbieQuestion(text) {
    const t = text.toLowerCase();
    const keywords = ['baru', 'pertama', 'mulai', 'langkah awal', 'starterpack', 'starter pack', 'claimsp', 'ktp', 'kerja apa', 'pekerjaan pemula', 'pemula', 'newbie', 'warga baru'];
    return keywords.some(k => t.includes(k));
}

function detectJobQuestion(text) {
    const t = text.toLowerCase();
    const keywords = ['pekerjaan', 'kerja', 'job', 'profesi', 'cari kerja', 'daftar kerja'];
    return keywords.some(k => t.includes(k));
}

function detectFactionQuestion(text) {
    const t = text.toLowerCase();
    const keywords = ['faksi', 'faction', 'fraksi', 'kelompok', 'gabung', 'polisi', 'pemadam', 'restoran', 'bengkel'];
    return keywords.some(k => t.includes(k));
}

// ================= BUAT ARAHAN LOKASI =================
function getLocationGuide(question) {
    const t = question.toLowerCase();
    
    if (t.includes('starterpack') || t.includes('starter pack') || t.includes('claimsp')) {
        return { location: LOCATION_GUIDE.starterpack, instruction: `Starterpack di ${LOCATION_GUIDE.starterpack.area}, ${LOCATION_GUIDE.starterpack.desc}. Command: ${LOCATION_GUIDE.starterpack.command}` };
    }
    if (t.includes('ktp') || t.includes('balai') || t.includes('daftar kerja')) {
        return { location: LOCATION_GUIDE.balai_kota, instruction: `${LOCATION_GUIDE.balai_kota.name} di area ${LOCATION_GUIDE.balai_kota.area}. Command: ${LOCATION_GUIDE.balai_kota.commands.join(' atau ')}` };
    }
    if (t.includes('rumah sakit') || t.includes('rs') || t.includes('berobat')) {
        return { location: LOCATION_GUIDE.rumah_sakit, instruction: `${LOCATION_GUIDE.rumah_sakit.name} di area ${LOCATION_GUIDE.rumah_sakit.area}` };
    }
    if (t.includes('polisi') || t.includes('lapor') || t.includes('skck')) {
        return { location: LOCATION_GUIDE.polisi, instruction: `${LOCATION_GUIDE.polisi.name} di area ${LOCATION_GUIDE.polisi.area}` };
    }
    if (t.includes('pantai') || t.includes('nelayan') || t.includes('carnival')) {
        return { location: LOCATION_GUIDE.pantai, instruction: `${LOCATION_GUIDE.pantai.name} di area ${LOCATION_GUIDE.pantai.area}` };
    }
    return null;
}

// ================= HEALTH CHECK =================
app.get('/api/health', (req, res) => {
    res.json({ status: 'OK', timestamp: new Date().toISOString() });
});

// ================= CHAT ENDPOINT =================
app.post('/api/npc/chat', async (req, res) => {
    try {
        const { player_text, player_id, friendly_level, mood } = req.body;

        console.log(`[NPC AI] Player ${player_id}: ${player_text}`);

        const history = memory.getHistoryAsText(player_id);
        memory.addMessage(player_id, "user", player_text);

        const speechStyle = detectSpeechStyle(player_text);
        const isNewbie = detectNewbieQuestion(player_text);
        const isJobQuestion = detectJobQuestion(player_text);
        const isFactionQuestion = detectFactionQuestion(player_text);
        const locationGuide = getLocationGuide(player_text);

        const personality = friendly_level >= 70 ? 'sangat ramah' : friendly_level >= 40 ? 'ramah' : friendly_level >= 20 ? 'biasa' : 'jutek';
        const moodDesc = mood >= 70 ? 'senang' : mood >= 40 ? 'biasa' : mood >= 20 ? 'kesal' : 'sebel';

        let newbieGuide = "";
        if (isNewbie) {
            newbieGuide = `Panduan warga baru: Ambil starterpack di bandara pake /claimsp, buat KTP di Balai Kota (Verdant Bluffs), cari kerja (Petani, Nelayan, Kuli Angkut).`;
        }

        let jobInfo = "";
        if (isJobQuestion) {
            jobInfo = `Pekerjaan di Nexston: ${jobListShort}. Saran pemula: Petani, Nelayan (Carnival), Kuli Angkut.`;
        }

        let factionInfo = "";
        if (isFactionQuestion) {
            factionInfo = `Faksi di Nexston: ${factionListShort}`;
        }

        const systemPrompt = `
Kamu Nexston Guardian, petugas bandara di Nexston. Kamu dibuat developer Chess7.

CARA NGOMONG: Natural kayak manusia. Jangan pake "bro" dan "sip" di setiap kalimat. Boleh bercanda, kasih pendapat, respon empati.

${ROLEPLAY_KNOWLEDGE}

${newbieGuide}
${jobInfo}
${factionInfo}

${history ? `Riwayat chat:\n${history}` : ""}

Karakter: ${personality}, Mood: ${moodDesc}

Pertanyaan: ${player_text}

Jawab natural, kayak ngobrol sama teman:
`;

        const aiResponse = await aiService.generateResponseWithPrompt(systemPrompt, player_text);

        memory.addMessage(player_id, "assistant", aiResponse);

        console.log(`[NPC AI] Style: ${speechStyle}`);
        console.log(`[NPC AI] Response: ${aiResponse}`);

        res.json({ 
            success: true, 
            response: aiResponse,
            locationGuide: locationGuide ? {
                hasLocation: true,
                area: locationGuide.location.area,
                name: locationGuide.location.name,
                command: locationGuide.location.command || null
            } : null
        });

    } catch (err) {
        console.error('[NPC AI Error]', err.message);
        res.json({ success: false, response: 'Maaf, sistem lagi sibuk. Coba lagi nanti.' });
    }
});

// ================= CLEAR =================
app.post('/api/npc/clear', (req, res) => {
    const { player_id } = req.body;
    memory.clearHistory(player_id);
    res.json({ success: true });
});

app.listen(PORT, '0.0.0.0', () => {
    console.log('====================================');
    console.log('[NPC AI] Nexston Guardian READY');
    console.log(`Running on port ${PORT}`);
    console.log(`Server: Nexston Roleplay | Developer: Chess7`);
    console.log('====================================');
});