CC=gcc
SRC=src/utils.c src/case.c
CFLAGS=-Werror -Wextra -Wall -pedantic -std=c99
BIN=libString

all:
	$(CC) $(CFLAGS) test/test.c $(SRC) -o $(BIN)

clean:
	rm $(BIN)