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
#include "Pred.h"
#include <ctime>
#include <cmath>
#include "param.h"


//############################################################################
//                                                                           #
//                           Class Pred                            #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================

Pred::Pred() 
{
	Agent();
	huntrange = RP;
	VPmax = VPhunt;
}  

Pred::~Pred(void)
{
	huntrange = NULL;
	VPmax = NULL;
}














