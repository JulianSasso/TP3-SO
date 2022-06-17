GCC = @gcc
GCCFLAGS = -std=c99 -Wall -pedantic -lm

CLIENT_C = client.c
SERVER_C = server.c
GAME_C = game.c


CLIENT_OUTPUT_FILE = client
SERVER_OUTPUT_FILE = server

all:
	$(GCC) $(GCCFLAGS) $(SERVER_C) $(GAME_C) -o $(SERVER_OUTPUT_FILE)
	$(GCC) $(GCCFLAGS) $(CLIENT_C) -o $(CLIENT_OUTPUT_FILE)

clean:
	@rm -f $(SERVER_OUTPUT_FILE) $(CLIENT_OUTPUT_FILE) 

.PHONY: all clean