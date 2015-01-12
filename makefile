all: testboid test.out




testboid: testboid.cpp Agent.o Boids.o bwindow.o
	g++ -o testboid testboid.cpp Agent.o Boids.o




Agent.o: Agent.h Agent.cpp 
	g++ -Wall -o Agent.o Agent.cpp -c




Boids.o: Boids.h Boids.cpp Agent.h
	g++ -Wall -o Boids.o Boids.cpp -c




test.out: main.o bwindow.o Agent.o Boids.o
	g++ -o test.out main.o bwindow.o Agent.o Boids.o  -lX11 -L/usr/X11R6/lib 



main.o: main.cpp Boids.h Agent.h 
	g++ -c main.cpp 



bwindow.o: bwindow.cpp bwindow.h Agent.h Boids.h
	g++ -c bwindow.cpp



clean :
	rm *.o *.out