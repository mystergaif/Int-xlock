# Переменные
CC = clang
CFLAGS = -Wall -Wextra -std=c11
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
SRC = src/main.c
TARGET = target/main

# Основная цель
all: prepare build

build:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)

prepare:
	mkdir -p target

clean:
	rm -rf target

run: all
	./$(TARGET)
