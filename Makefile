CC=cc
CFLAGS=-Wall
LFLAGS=

all: skeltal

skeltal: skeltal.c
	$(CC) skeltal.c -o skeltal $(CFLAGS) $(LFLAGS)

run: skeltal
	./skeltal