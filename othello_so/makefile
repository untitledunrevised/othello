# Project: othello_so

CC       = gcc
OBJ      = othello.o
BIN      = libothello.so
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(LINKOBJ)
	$(CC) -shared -o $(BIN) $(OBJ) -m32

OBJ: othello.c
	$(CC) -fPIC -o $(OBJ) -c othello.c
