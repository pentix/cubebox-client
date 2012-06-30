CC=gcc
CFLAGS=`sdl-config --libs --cflags` -pthread -g
FILES=main.c init.c
OUTPUT=cubebox


all:
	$(CC) $(CFLAGS) $(FILES) -o $(OUTPUT)


clean:
	rm *.o
