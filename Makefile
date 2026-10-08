CC = gcc
CFLAGS = -std=c99 -Wall -Wextra

all: build/lr_parser

build/lr_parser: src/lr_parser.c
	mkdir -p build
	$(CC) $(CFLAGS) src/lr_parser.c -o build/lr_parser

run: all
	./build/lr_parser

clean:
	rm -rf build *.exe
