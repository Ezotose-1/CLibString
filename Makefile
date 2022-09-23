CC=gcc
SRC=
CFLAGS=-Werror -Wextra -Wall -pedantic -std=c99
BIN=libString

all:
	$(CC) test/test.c $(CFLAGS) $(SRC) -o $(BIN)

clean:
	rm $(BIN)