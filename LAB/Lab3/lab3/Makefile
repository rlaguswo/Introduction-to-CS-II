CC = g++
exe_file = run_card

all: $(exe_file)

$(exe_file): run_card.cpp card.o
	$(CC) run_card.cpp card.o -o $(exe_file)

card.o: card.cpp card.h
	$(CC) -c card.cpp

clean: 
	rm -f *.o $(exe_file)

