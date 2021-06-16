#ifndef Stepper_H
#define Stepper_H


/*! \file Stepper.h
\brief Defines general interface for numerical integrator.
*/


#include "GeneralDefinitions.h"
#include "Equation.h"

///Tries to make step of prescribed length or handle the encounter of singularity
class Stepper
{
public:
	
	Stepper( Equation * eq, double solAbsMax ): eq( eq ), solAbsMax( solAbsMax ){};
	virtual ~Stepper( void ){};
	
	
	///Tries to make step form x with y value to x+h
	///\returns true - when step is good or false otherwise
	///\param [in] x beginning point
	///\param [in] y value of silution at the beginning
	///\param [in] h stepsize and direction (complex value)
	virtual bool makeStep( cmplx x, cvector y, cmplx h ) = 0; 
	
	
	///\returns current position after making step or last goog position if step failed
	virtual cmplx getCurrentX( void ) = 0;
	
	
	///\returns current value of the solution after making step; If step failed returns last goog position.
	virtual cvector getCurrentY( void ) = 0;
	
	
protected:
		
	///Maximal value of solution. Above integration is stopped.
	double solAbsMax;
	
	///Check if a norm solution is bounded by solAbsMax
	bool isSolutionBoundedNorm( cvector sol, int rank );
	
	///Check if max of the solution is bounded by solAbsMax
	bool isSolutionBoundedMax( cvector sol, int rank );
	
	///Returns euclidean norm of vector vect of range [1:rank]
	double norm( cvector vect, int rank );
	
	///Equation
	Equation * eq;
	
	
};


#endif
