CC = g++ -std=c++11
exe_file = run_wizard

all: $(exe_file)

$(exe_file): run_wizard.cpp catalog.o
	$(CC) run_wizard.cpp catalog.o -o $(exe_file)

catalog.o: catalog.cpp catalog.h
	$(CC) -c catalog.cpp

clean:
	rm -f *.o $(exe_file)
