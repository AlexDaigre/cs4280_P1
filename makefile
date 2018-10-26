CC      = gcc
CFLAGS  = -g
TARGET = oss
OBJS   = main.o scanner.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.c token.h
	$(CC) $(CFLAGS) -c main.c

scanner.o: scanner.c token.h
	$(CC) $(CFLAGS) -c scanner.c

clean:
	/bin/rm -f *.o $(TARGET)