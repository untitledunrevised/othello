# Project: othello_dll

CPP      = g++.exe
CC       = gcc.exe
WINDRES  = windres.exe
OBJ      = dllmain.o othello.o
LINKOBJ  = dllmain.o othello.o
LIBS     = -static-libgcc -m32
BIN      = othello.dll
CXXFLAGS = -m32 -DBUILDING_DLL=1
CFLAGS   = -m32 -DBUILDING_DLL=1
RM       = rm.exe -f
DEF      = libothello.def
STATIC   = libothello.a

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) othello_console.exe all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN) othello_console.exe $(DEF) $(STATIC)

$(BIN): $(LINKOBJ)
	$(CC) -shared $(LINKOBJ) -o $(BIN) $(LIBS) -Wl,--output-def,$(DEF),--out-implib,$(STATIC),--add-stdcall-alias

dllmain.o: dllmain.c
	$(CC) -c dllmain.c -o dllmain.o $(CFLAGS)

othello.o: othello.c
	$(CC) -c othello.c -o othello.o $(CFLAGS)

othello_console.exe: testmain.c
	$(CC) testmain.c -o othello_console.exe -m32
