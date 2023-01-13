CC = gcc
CFLAGS = -Wall -g

.PHONY: all clean

all: graph

graph: main.o edges.o algo.o nodes.o graph.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c graph.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o graph