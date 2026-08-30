Verified build, avr-gcc 7.3.0, -mmcu=atmega32 (same target EmbeddedBuilder's
avr8-gnu-toolchain uses).

pwdlock.elf / pwdlock.hex - ready to load into SimulIDE.

Build result: 0 errors. Only pre-existing, harmless warnings in DIO_Program.c
(comparing an unsigned value against its own minimum -- redundant, not wrong).
Flash: 4084 / 32768 bytes (12%)
SRAM:  344 / 2048 bytes (17%)

Default password: 1 2 3 4  (App/SystemMap.h -- SystemMap_Password)
No EEPROM persistence was requested for this project, so this is a
compile-time constant, not stored/read from EEPROM.
