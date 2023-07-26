CC = g++ -g 
exe_file = Driver

all: $(exe_file)

$(exe_file): card.o deck.o hand.o player.o game.o card.h deck.h hand.h player.h game.h driver.cpp
	$(CC) card.o deck.o hand.o player.o game.o driver.cpp -std=c++11  -o  $(exe_file)

card.o: card.cpp card.h
	$(CC) -c card.cpp

deck.o: deck.cpp deck.h
	$(CC) -c deck.cpp

hand.o: hand.cpp hand.h
	$(CC) -c hand.cpp

player.o: player.cpp player.h
	$(CC) -c player.cpp

game.o: game.cpp game.h
	$(CC) -c game.cpp -std=c++11

clean:
	rm -f *.o $(exe_file)
