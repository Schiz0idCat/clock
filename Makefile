CC = gcc
CFLAGS = $(shell pkg-config --cflags raylib) -I.
LIBS = $(shell pkg-config --libs raylib) -lm

SRC = main.c \
      clock/segment.c \
      tools/math/my_math.c

OUT = main

all:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT) $(LIBS)
	./$(OUT)

clean:
	rm -f $(OUT)
