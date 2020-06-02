GCC = gcc
CFLAGS = -g
TARGETS = server client

all: $(TARGETS)

server: server.c
	$(GCC) $(CFLAGS) $^ -o $@

client: client.c
	$(GCC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	$(RM) $(TARGETS) ProgramY*
