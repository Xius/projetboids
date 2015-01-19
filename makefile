all: test.out









Agent.o: Agent.h Agent.cpp 
	g++ -Wall -o Agent.o Agent.cpp -c




Boids.o: Boids.h Boids.cpp Agent.h
	g++ -Wall -o Boids.o Boids.cpp -c




test.out: main.o bwindow.o Agent.o Boids.o Pred.o
	g++ -o test.out main.o bwindow.o Agent.o Boids.o Pred.o  -lX11 -I/opt/X11/include -L/usr/X11R6/lib 



main.o: main.cpp Boids.h Agent.h Pred.h 
	g++ -c main.cpp -I/opt/X11/include

Pred.o: Pred.cpp Pred.h Agent.h
	g++ -c Pred.cpp -I/opt/X11/include


bwindow.o: bwindow.cpp bwindow.h Agent.h Boids.h
	g++ -c bwindow.cpp -I/opt/X11/include



clean :
	rm *.o *.out