CC = g++ -g 
exe_file = driver

all: $(exe_file)

$(exe_file): animal.o monkey.o sea_otter.o sloth.o zoo.o animal.h monkey.h sea_otter.h sloth.h zoo.h main.cpp
	$(CC) animal.o monkey.o sea_otter.o sloth.o zoo.o main.cpp -std=c++11  -o  $(exe_file)

animal.o: animal.cpp animal.h
	$(CC) -c animal.cpp

monkey.o: monkey.cpp monkey.h
	$(CC) -c monkey.cpp

sea_otter.o: sea_otter.cpp sea_otter.h
	$(CC) -c sea_otter.cpp

sloth.o: sloth.cpp sloth.h
	$(CC) -c sloth.cpp

zoo.o: zoo.cpp zoo.h
	$(CC) -c zoo.cpp

clean:
	rm -f *.o $(exe_file)
