// modules/ai.js
const Groq = require('groq-sdk');

class AIService {
    constructor(apiKey) {
        this.groq = new Groq({ apiKey: apiKey });
        this.model = "llama-3.1-8b-instant";  // Ganti dari 70B ke 8B (hemat token)
    }

    async generateResponseWithPrompt(systemPrompt, userMessage) {
        try {
            const completion = await this.groq.chat.completions.create({
                messages: [
                    { role: "system", content: systemPrompt },
                    { role: "user", content: userMessage }
                ],
                model: this.model,
                max_tokens: 200,
                temperature: 0.9  // Naikkan sedikit untuk lebih kreatif
            });

            let aiResponse = completion.choices[0]?.message?.content || "Maaf, gak nangkep nih.";
            
            aiResponse = aiResponse
                .replace(/[\r\n]+/g, ' ')
                .replace(/\s+/g, ' ')
                .trim();

            return aiResponse;

        } catch (error) {
            console.error('[AI Error]', error.message);
            return "Maaf, sistem lagi sibuk nih. Coba lagi ya.";
        }
    }
}

module.exports = { AIService };