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
	srand(time(NULL));
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
	delete speed;
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
// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================