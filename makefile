all: testboid
testboid: testboid.cpp Agent.o Boids.o
	g++ -o testboid testboid.cpp Agent.o Boids.o
Agent.o: Agent.h Agent.cpp
	g++ -Wall -o Agent.o Agent.cpp -c
Boids.o: Boids.h Boids.cpp 
	g++ -Wall -o Boids.o Boids.cpp  -c