.SUFFIXES:.c .o

CC = gcc
SRCS = othello.c
OBJS = othello.o
EXEC = libothello.so

start: $(OBJS)
	$(CC) -shared -o $(EXEC) $(OBJS)

.c.o:
	$(CC) -fPIC -Wall -o $@ -c $<

clean:
	rm -rf $(EXEC) $(OBJS)
