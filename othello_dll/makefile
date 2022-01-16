# Project: othello_dll

CPP      = g++
CC       = gcc
OBJ      = dllmain.o dll.o
LINKOBJ  = dllmain.o dll.o
LIBS     = -static-libgcc -m32
BIN      = othello.dll
CXXFLAGS = -m32 -DBUILDING_DLL=1
CFLAGS   = -m32 -DBUILDING_DLL=1
RM       = rm.exe -f
DEF      = libothello.def
STATIC   = libothello.a

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN) $(DEF) $(STATIC)

$(BIN): $(LINKOBJ)
	$(CC) -shared $(LINKOBJ) -o $(BIN) $(LIBS) -Wl,--output-def,$(DEF),--out-implib,$(STATIC),--add-stdcall-alias

dllmain.o: dllmain.c
	$(CC) -c dllmain.c -o dllmain.o $(CFLAGS)

dll.o: dll.c
	$(CC) -c dll.c -o dll.o $(CFLAGS)
