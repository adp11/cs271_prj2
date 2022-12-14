# minor changes based on the template provided from Bootcamp C++ pdf
all: test usecase

usecase: main.o minqueue.o
	g++ -std=c++11 minqueue.o main.o -o usecase

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

test: minqueue.o test_minqueue.o
	g++ -std=c++11 minqueue.o test_minqueue.o -o test

test_minqueue.o: minqueue.o test_minqueue.cpp
	g++ -std=c++11 -c test_minqueue.cpp

minqueue.o: minqueue.cpp minqueue.h
	g++ -std=c++11 -c minqueue.cpp

clean:
	rm -f all *.o