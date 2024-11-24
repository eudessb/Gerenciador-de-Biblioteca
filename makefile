#to_do
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
SRC = src/main.c src/arvore.c
OBJ = $(SRC:.c=.o)
EXEC = bin/main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

.PHONY: run
run: $(EXEC)
	./$(EXEC)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
