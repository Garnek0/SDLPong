CC = gcc

CFLAGS := -Wall -O2 `pkg-config --cflags sdl2`
LDFLAGS := -Iinclude `pkg-config --libs sdl2`

SRC := $(shell find src -name '*.c')

all: build

build:
	mkdir -p bin
	$(CC) $(SRC) $(CFLAGS) $(LDFLAGS) -o bin/sdlpong

run: build
	bin/sdlpong

clean:
	rm -rf bin

