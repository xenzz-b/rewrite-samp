# Vertex Roleplay

**Vertex Roleplay (V:RP)** - SAMP Roleplay Gamemode  
Developed by **Claps**

## Overview
Vertex Roleplay adalah gamemode SA-MP Roleplay dengan fokus pada clean architecture, modular systems, dan performa tinggi.

- **Hostname**: Vertex Roleplaya
- **Gamemode**: V:RP V0.1.5
- **Web**: discord.gg/vertexroleplay
- **Database**: vrp
- **Language**: Indonesia
- **Max Players**: 250
- **Developer**: Claps

## Credits
- Development & Rewrite: **Claps**
- Mapping: Converted to Vertex sign system
- UI/UX: Vertex Roleplay branding
- Community: Vertex Roleplay Team

## Structure
- `gamemodes/main.pwn` - Entry point (print Vertex Roleplay | V:RP | Developed by Claps)
- `gamemodes/core/` - Modular core (factions, jobs, dynamic, inventory, phone, etc)
- `filterscripts/mapping/` - Map exterior/interior (Vertex sign)
- `database/db_gta.sql` - Full DB schema for VRP
- `include/` - Pawn includes

## Features
- 13 Factions (LSPD, LSFD, Gov, etc)
- 14 Jobs (farmer, miner, lumberjack, etc)
- Dynamic systems (houses, biz, atms, doors, garages, etc)
- Inventory, Phone (Twitter/Whatsapp/Bank), Vehicle system
- Voice system (SampVoice)

## Build
```bat
pawno/pawncc.exe main.pwn -Dgamemodes -;+ -(+ -d3
```

## Server Config
```
hostname Vertex Roleplay
gamemode0 main
filterscripts mapping testvoice hotkeys Buttons
maxplayers 250
```

## Branding
- Server Name: Vertex Roleplay
- Short: V:RP / VRP
- Domain: samp.vertexroleplay.id
- Discord: discord.gg/vertexroleplay
- Theater: Vertex Theater

## License & Credit
All rights under **Vertex Roleplay** by **Claps**.
© 2026 Vertex Roleplay. All rights reserved.
