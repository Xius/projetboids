//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================



// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "Agent.h"
#include <ctime>
#include <cmath>



//############################################################################
//                                                                           #
//                           Class Agent                                     # 
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
Agent::Agent(void)
{
	position = new double[2];
	position[0] = (rand()/(double)RAND_MAX)*WIDTH;
	position[1] = (rand()/(double)RAND_MAX)*HEIGHT;
	speed = new double[2];
	speed[0]= 1;
	speed[1]= 1;
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Agent::~Agent(void)
{
	delete position;
	position = NULL;
	delete speed;
	speed = NULL;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================
double* Agent::get_position(void)
{
	return position;
}
double* Agent::get_speed(void)
{
	return speed;
}
bool Agent::nearR(Agent &other) const
{
	bool n = 0;
	double norm=sqrt((position[0]-other.get_position()[0])*(position[0]-other.get_position()[0])+(position[1]-other.get_position()[1])*(position[1]-other.get_position()[1]));
	if(norm<R)
	{
		n=1;
	}
	return n;     
}
bool Agent::nearC(Agent &other) const
{
	bool n = 0;
	double norm=sqrt((position[0]-other.get_position()[0])*(position[0]-other.get_position()[0])+(position[1]-other.get_position()[1])*(position[1]-other.get_position()[1]));	
	if(norm<C)
	{
		n=1;
	}
	return n;
}
bool Agent::nearOBS(Agent &other) const
{
	bool n = 0;
	double norm=sqrt(((CENTEROBSTACLE +10)-other.get_position()[0])*((CENTEROBSTACLE +10)-other.get_position()[0])+((CENTEROBSTACLE +10)-other.get_position()[1])*((CENTEROBSTACLE +10)-other.get_position()[1]));	
	if(norm<C)
	{
		n=1;
	}
	return n;
}
/*
bool Agent::nearP(Pred &other) const
{
	bool n = 0;
	double norm=sqrt((position[0]-other.get_position()[0])*(position[0]-other.get_position()[0])+(position[1]-other.get_position()[1])*(position[1]-other.get_position()[1]));
	if(norm<P)
	{
		n=1;
	}
	return n;
}*/
double* Agent::V1(int pos, Agent* Shield, int size)
{
	double* V1 = new double[2];
	V1[0]=0;
	V1[1]=0;
	int nb = 0;
	for(int i=0;i<size;i++)
	{
		if(this->nearR(Shield[i])==1 && i!= pos)
			{
				V1[0] = V1[0] + Shield[i].get_speed()[0] - speed[0];
				V1[1] = V1[1] + Shield[i].get_speed()[1] - speed[1];
				nb++;
			}
	}	
	if(nb!=0)
	{
		V1[0]= V1[0]/nb;
		V1[1]= V1[1]/nb;
	}
	return V1;
}

double* Agent::V2(int pos, Agent* Shield, int size)
{
	double* V2 = new double[2];
	V2[0]=0;
	V2[1]=0;
	int nb = 0;
	for(int i=0;i<size;i++)
	{
		if(this->nearR(Shield[i])==1 && i!= pos)
			{
				V2[0] = V2[0] + Shield[i].get_position()[0] - position[0];
				V2[1] = V2[1] + Shield[i].get_position()[1] - position[1];
				nb++;
			}
	}
	if(nb!=0)
	{
		V2[0]= V2[0]/nb;
		V2[1]= V2[1]/nb;
	}
	return V2;
}
double* Agent::V3(int pos, Agent* Shield, int size)
{
	double* V3 = new double[2];
	double* VOBS = new double[2];
	V3[0]=0;
	V3[1]=0;
	VOBS[0]=0;
	VOBS[1]=0;
	int nb = 0;
	int o = 0;
	int i=0;
	for(i=0;i<size;i++)
	{
		if(this->nearC(Shield[i])==1 && i!= pos )
		{
			V3[0] = V3[0] + Shield[i].get_position()[0] - position[0];
			V3[1] = V3[1] + Shield[i].get_position()[1] - position[1];				
			nb++;
		}
		if(this->nearOBS(Shield[i])==1)
		{
			VOBS[0] = VOBS[0] + (CENTEROBSTACLE + 10) - position[0];
			VOBS[1] = VOBS[1] + (CENTEROBSTACLE + 10) - position[1];				
			o++;
		}
	}
	if(nb!=0)
	{
		V3[0]= -V3[0]/nb ;
		V3[1]= -V3[1]/nb;
	}
	if(o!=0)
	{
		V3[0]= V3[0] - VOBS[0]/o;
		V3[1]= V3[1] - VOBS[1]/o;
	}
	return V3;
}
/*double* Agent::V4(int pos, Pred Predators, int size)
{
	double* V4 = new double[2];
	V4[0]=0;
	V4[1]=0;
	int nb = 0;
	int i=0;
	for(i=0;i<size;i++)
	{
		if(this->nearP(Predators)==1 && i!= pos)
		{
			V4[0] = V4[0] + (Predators.get_position()[0] - position[0])/ (std::abs(Predators.get_position()[0] - position[0]));
			V4[1] = V4[1] + (Predators.get_position()[1] - position[1]) / (std::abs(Predators.get_position()[1] - position[1]));
			nb++;
		}
	}
	if(nb!=0)
	{
		V4[0]= -V4[0]/nb;
		V4[1]= -V4[1]/nb;
	}
	return V4;
}*/
void Agent::Vtot(Agent* Shield, int size, int pos)
{
	double* speed1 = V1(pos, Shield, size);
	double* speed2 = V2(pos, Shield, size);
	double* speed3 = V3(pos, Shield, size);
	double norm = 0;
	speed[0] = speed[0] + TIME*(gam1*speed1[0]+gam2*speed2[0]+gam3*speed3[0]);
	speed[1] = speed[1] + TIME*(gam1*speed1[1]+gam2*speed2[1]+gam3*speed3[1]);
	norm = sqrt(speed[0]*speed[0]+speed[1]*speed[1]);

	if(norm > 10)
	{
		double max = norm/10;
		speed[0] = speed[0]/max;
		speed[1] = speed[1]/max;
	}
	

	if(position[0]< L)
	{
		speed[0] = speed[0] + 1;
	}
	if(position[0]> WIDTH - L)
	{
		speed[0] = speed[0] - 1;
	}
	if(position[1]>HEIGHT - H)
	{
		speed[1] = speed[1] - 1;
	}
	if(position[1]< H)
	{
		speed[1] = speed[1] + 1;
	}

}
void Agent::newcoord(Agent* Shield, int pos, int size)
{
	Vtot(Shield, size, pos);
	position[0] = position[0] + TIME*speed[0];
	position[1] = position[1] + TIME*speed[1];
	
}
void Agent::printcoord(void) const
{
	printf(" x=%lf, y=%lf\n", position[0], position[1]);
}
// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
