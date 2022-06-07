CXX_FLAG = --std=c++11 -g

all: testbst

testbst: testbst.o bst.o
	g++ $(CXX_FLAG) -o testbst testbst.o bst.o

testbst.o: testbst.cpp
	g++ -c $(CXX_FLAG) testbst.cpp

bst.o: bst.cpp bst.h
	g++ -c $(CXX_FLAG) bst.cpp

clean:
	rm -f testbst *.o