all: testboid
testboid: testboid.cpp Agent.o
	g++ -o testboid testboid.cpp Agent.o
Agent.o: Agent.h Agent.cpp
	g++ -Wall -o Agent.o Agent.cpp -c
