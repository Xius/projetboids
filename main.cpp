#include <stdlib.h>
#include <stdio.h>
#include "Agent.h"
#include "Boids.h"
#include <ctime>
#include "bwindow.h"
#include "param.h"
#include "Pred.h"

int main()
{
    bwindow win(640,480);
    printf("%d\n",win.init());
    win.map();
    srand(time(NULL));
	Boids shield = Boids(100);
	Pred predators;
    for(;;)
    {
		int ev = win.parse_event();
		switch(ev)
		{
	    	case BKPRESS :
			printf("keypressed\n"); 
			printf("key : %s\n",win.get_lastkey());
			break;
	    	case BBPRESS:
			printf("buttonpressed\n"); break;
	    	case BEXPOSE:
			printf("expose\n"); break;
	    	case BCONFIGURE:
			printf("configure\n"); break;
		}
		win.draw_fsquare(0,0,640,480,0xFFFFFF);
		win.draw_fsquare(CENTEROBSTACLE - 5,CENTEROBSTACLE -5,CENTEROBSTACLE + 5,CENTEROBSTACLE + 5,0xFF00);
		win.draw_boids(shield);
		shield.nextflock();
		usleep(100000);
		/*
		win.draw_point(100,100,0xFF00);
		win.draw_line(100,100,200,200,0xFF0000);
		win.draw_text(10,10,0x0,"Hello World",strlen("Hello World"));
		win.draw_square(200,200,220,220,0xFF00);
		win.draw_fsquare(400,400,440,440,0xFF00);
		*/
    }
    return 0;
}
