//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __AGENT_H__
#define __AGENT_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>



// ===========================================================================
//                                Project Files
// ===========================================================================




// ===========================================================================
//                              Class declarations
// ===========================================================================






class Agent
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    Agent(void);

    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~Agent(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
    double* get_position(void);
    double* get_speed(void);
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
    bool near(Agent &other) const;

    double* V1(int pos, Agent* Shield, int size);

    double* V2(int pos, Agent* Shield, int size);
    // =======================================================================
    //                             Public Attributes
    // =======================================================================





  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    /*Agent(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/
    Agent(const Agent &model)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };


    // =======================================================================
    //                              Protected Methods
    // =======================================================================

    // =======================================================================
    //                             Protected Attributes
    // =======================================================================
    double* position;
    double* speed; 
    double R;
    double* gam;
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


#endif // __Agent_H__

