.PHONY:clean
CC=gcc
CFLAG=-Wall -g
MAIN=toyFTP
OBJS=main.o sysutil.o

$(MAIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.O:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(MAIN)
