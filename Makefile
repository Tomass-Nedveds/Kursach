TARGET = ./main.o

CC = gcc

CFLAGS = -Wall -Wextra -std=c11

SRC = main.c students.c

.PHONY: all clean build run

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

all: clean build

build: $(TARGET)

clean:
	rm -rf $(TARGET)