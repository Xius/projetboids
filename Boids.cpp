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
#include "Boids.h"





//############################################################################
//                                                                           #
//                           Class Boids                            #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
Boids::Boids(void)
{
	flock = NULL;
	nbA = 0;
}
Boids::Boids(int size)
{
	int i = 0;
	flock = new Agent[size];
	for(i=0; i<nbA; i++)
	{
		flock[i]= Agent();
	}

}
// ===========================================================================
//                                  Destructor
// ===========================================================================
Boids::~Boids(void)
{
	delete flock;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================
Agent* Boids::get_flock(void)
{
	return flock;
}

int Boids::get_NBA(void)
{
	return nbA;
}
// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
