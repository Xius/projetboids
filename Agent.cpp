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
#include "param.h"
#include <cmath>



//############################################################################
//                                                                           #
//                           Class Agent                            #
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
	//width = x, height = y
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
	double norm = sqrt(position[0]*other.get_position()[0] + position[1]*other.get_position()[1]);
	if(norm<R)
	{
		n=1;
	}
	return n;
}
bool Agent::nearC(Agent &other) const
{
	bool n = 0;
	double norm = sqrt(position[0]*other.get_position()[0] + position[1]*other.get_position()[1]);
	if(norm<C)
	{
		n=1;
	}
	return n;
}
double* Agent::V1(int pos, Agent* Shield, int size)
{
	double* V1 = new double[2];
	V1[0]=0;
	V1[1]=1;
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
	V1[0]= V1[0]/nb;
	V1[1]= V1[1]/nb;
	return V1;
}

double* Agent::V2(int pos, Agent* Shield, int size)
{
	double* V2 = new double[2];
	V2[0]=0;
	V2[1]=1;
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
	V2[0]= V2[0]/nb;
	V2[1]= V2[1]/nb;
	return V2;
}
double* Agent::V3(int pos, Agent* Shield, int size)
{
	double* V3 = new double[2];
	V3[0]=0;
	V3[1]=1;
	int nb = 0;
	for(int i=0;i<size;i++)
	{
		if(this->nearR(Shield[i])==1 && i!= pos)
			{
				V3[0] = V3[0] + Shield[i].get_position()[0] - position[0];
				V3[1] = V3[1] + Shield[i].get_position()[1] - position[1];
				nb++;
			}
	}
	V3[0]= -V3[0]/nb;
	V3[1]= -V3[1]/nb;
	return V3;
}
// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
