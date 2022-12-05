CC = g++
exe_file = multdiv_run

all: $(exe_file)

$(exe_file): multdiv.o multdiv.h prog.cpp
	$(CC) multdiv.o prog.cpp -o $(exe_file)

multdiv.o: multdiv.h multdiv.cpp
	$(CC) -c multdiv.cpp

clean:
	rm -f *.o $(exe_file)
