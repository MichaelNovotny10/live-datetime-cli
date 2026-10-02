CC      = gcc
SRC     = live-datetime.c
EXE     = live-datetime
BIN_DIR = /usr/local/bin
CFLAGS  = -Wall -Wextra

.PHONY: build run clean install uninstall

build:
	$(CC) $(CFLAGS) $(SRC) -o $(EXE)

run: build
	./$(EXE)

clean:
	rm -f ./$(EXE)

install: build
	sudo cp $(EXE) $(BIN_DIR)/$(EXE)

uninstall:
	sudo rm -f $(BIN_DIR)/$(EXE)
