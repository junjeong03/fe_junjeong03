CXX_FLAG = --std=c++11 -g

all: testbst

testbst: test.o bst.o
	g++ $(CXX_FLAG) -o testbst test.o bst.o

bst.o: bst.cpp bst.h
	g++ -c $(CXX_FLAG) bst.cpp

test.o: testbst.cpp
	g++ -c $(CXX_FLAG) testbst.cpp

clean:
	rm -f runMovies *.o