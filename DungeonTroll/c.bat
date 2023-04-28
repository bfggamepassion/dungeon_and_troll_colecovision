path c:\sdcc\bin
@echo off
sdcc -mz80 -c --std-c99 --opt-code-speed charset.c
del charset.lst
del charset.sym
del charset.asm
sdcc -mz80 -c --std-c99 --opt-code-speed fonctions.c
del fonctions.lst
del fonctions.sym
del fonctions.asm
sdcc -mz80 -c --std-c99 --opt-code-speed laby.c
del laby.lst
del laby.sym
del laby.asm
sdcc -mz80 -c --std-c99 --opt-code-speed main.c
del main.lst
del main.sym
del main.asm
sdasz80 -o music.rel music.s
sdcc -mz80 -c --std-c99 --opt-code-speed rooms.c
del rooms.lst
del rooms.sym
del rooms.asm
sdcc -mz80 -c --std-c99 --opt-code-speed sprites.c
del sprites.lst
del sprites.sym
del sprites.asm
pause
