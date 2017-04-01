CFLAGS=-Wall -Wextra -g -std=c++11
LDFLAGS=

all: main

main: main.o Envir.o Box.o Cell.o SCell.o LCell.o
	g++ $(LDFLAGS) $^ -o $@

%.o: %.cpp
	g++ $(CFLAGS) -c $< -o $@

clean: 
	rm -f *.o
