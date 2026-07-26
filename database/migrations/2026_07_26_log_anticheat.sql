-- Anticheat v2 : tabel log deteksi & kick otomatis (by Claps)
-- Dipakai oleh AC_LogDetect() di gamemodes/core/anticheat/anticheat.inc

CREATE TABLE IF NOT EXISTS `log_anticheat` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Nama` VARCHAR(32) NOT NULL DEFAULT '',
  `UCP` VARCHAR(32) NOT NULL DEFAULT '',
  `Reason` VARCHAR(64) NOT NULL DEFAULT '',
  `Detail` VARCHAR(128) NOT NULL DEFAULT '',
  `Action` VARCHAR(8) NOT NULL DEFAULT 'WARN',
  `Ping` INT(11) NOT NULL DEFAULT 0,
  `Tanggal` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`ID`),
  KEY `idx_ucp` (`UCP`),
  KEY `idx_reason` (`Reason`),
  KEY `idx_tanggal` (`Tanggal`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
