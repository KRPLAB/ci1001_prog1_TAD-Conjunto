CC = gcc
CFLAGS = -Wall

all: conjunto

conjunto: conjunto.o testa_conjunto.o
	$(CC) $(CFLAGS) -o conjunto conjunto.o testa_conjunto.o

conjunto.o: conjunto.c
	$(CC) $(CFLAGS) -c conjunto.c

testa_conjunto.o: testa_conjunto.c
	$(CC) $(CFLAGS) -c testa_conjunto.c

clean:
	rm -f conjunto *.o
