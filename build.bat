@echo off

cl /W3 /nologo /FoBinary\ /Za /Od /I lib\SDL2\include main.cpp /link /SUBSYSTEM:CONSOLE /LIBPATH:lib\SDL2\lib\x86 /OUT:Binary\main.exe SDL2main.lib SDL2.lib Shell32.lib 
