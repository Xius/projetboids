//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __BOIDS_H__
#define __BOIDS_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>
#include "Agent.h"


// ===========================================================================
//                                Project Files
// ===========================================================================




// ===========================================================================
//                              Class declarations
// ===========================================================================






class Boids
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    Boids(void);
    Boids(int size);
    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~Boids(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================

    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
    void nextflock(void);
    Agent* get_flock(void);
    int get_NBA(void);
   
    // =======================================================================
    //                             Public Attributes
    // =======================================================================




  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    /*Boids(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/
    /*Boids(const Boids &model)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/


    // =======================================================================
    //                              Protected Methods
    // =======================================================================

    // =======================================================================
    //                             Protected Attributes
    // =======================================================================
    Agent* flock;
    int nbA;
};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================

// ===========================================================================
//                              Setters' definitions
// ===========================================================================

// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __BOIDS_H__

