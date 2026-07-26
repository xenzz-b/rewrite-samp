// modules/memory.js
// Manajemen memory percakapan per player

class ConversationMemory {
    constructor(maxHistory = 20) {
        this.conversations = {};
        this.maxHistory = maxHistory;
    }

    getHistory(playerId) {
        if (!this.conversations[playerId]) {
            this.conversations[playerId] = [];
        }
        return this.conversations[playerId];
    }

    addMessage(playerId, role, content) {
        if (!this.conversations[playerId]) {
            this.conversations[playerId] = [];
        }
        
        this.conversations[playerId].push({
            role: role,
            content: content,
            timestamp: Date.now()
        });
        
        // Batasi jumlah history
        if (this.conversations[playerId].length > this.maxHistory) {
            this.conversations[playerId] = this.conversations[playerId].slice(-this.maxHistory);
        }
    }

    clearHistory(playerId) {
        if (this.conversations[playerId]) {
            delete this.conversations[playerId];
            console.log(`[Memory] History cleared for player ${playerId}`);
            return true;
        }
        return false;
    }

    getHistoryAsText(playerId) {
        const history = this.getHistory(playerId);
        if (history.length === 0) return "";
        
        let text = "=== RIWAYAT PERCAKAPAN ===\n";
        for (const msg of history) {
            const role = msg.role === "user" ? "Player" : "Nexston Guardian";
            text += `${role}: ${msg.content}\n`;
        }
        text += "=== AKHIR RIWAYAT ===\n";
        return text;
    }
}

module.exports = { ConversationMemory };