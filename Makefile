CC = gcc
WCC = x86_64-w64-mingw32-gcc

SRC = src/main.c \
      src/clock/segment.c \
      src/clock/digit.c \
      src/clock/number.c \
      src/clock/time.c \
      src/tools/math/my_math.c

LIB_LINUX = ./dependencies/linux
LIB_WIN = ./dependencies/windows

CFLAGS_LINUX = -Isrc -I. -I$(LIB_LINUX)
LIBS_LINUX = -L$(LIB_LINUX) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

CFLAGS_WIN = -Isrc -I. -I$(LIB_WIN)
LIBS_WIN = -L$(LIB_WIN) -lraylib -lopengl32 -lgdi32 -lwinmm -mwindows

OUT_DIR = .target
OUT_NAME = clock

all: linux

linux:
	mkdir -p $(OUT_DIR)
	$(CC) $(SRC) $(CFLAGS_LINUX) -o $(OUT_DIR)/$(OUT_NAME) $(LIBS_LINUX)
	./$(OUT_DIR)/$(OUT_NAME)

windows:
	mkdir -p $(OUT_DIR)
	$(WCC) $(SRC) $(CFLAGS_WIN) -o $(OUT_DIR)/$(OUT_NAME).exe $(LIBS_WIN)

clean:
	rm -rf $(OUT_DIR)
