.PHONY:clean
CC=gcc
CFLAGS=-Wall -g
MAIN=toyFTP
OBJS=main.o sysutil.o session.o ftpproto.o privparent.o

$(MAIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.O:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(MAIN)
