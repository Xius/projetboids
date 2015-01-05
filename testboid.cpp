//****************************************************************************
//
//
//
//****************************************************************************
 
 
 
 
// ===========================================================================
//                               Include Libraries
// ===========================================================================
#include <stdlib.h>
#include <stdio.h>
#include "Agent.h"
#include <ctime>
//#include "bwindows.h"


// ===========================================================================
//                             Include Project Files
// ===========================================================================



// ===========================================================================
//                         Declare Miscellaneous Functions
// ===========================================================================








// ===========================================================================
//                                   The Main
// ===========================================================================
int main(int argc, char* argv[])
{
  srand(time(NULL));
  Agent* bond = new Agent();
  Agent* romanoff = new Agent();
  printf("x = %lf, y = %lf\n", bond->get_position()[0], bond->get_position()[1]);
  printf("x = %d\n ", bond->nearC(*romanoff));

  printf("x = %d\n", bond->nearR(*romanoff));

  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

