all:
	gcc `sdl-config --libs --cflags` -pthread -g main.c init.c -o cubebox
	
