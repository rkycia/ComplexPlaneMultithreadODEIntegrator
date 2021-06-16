#ifndef fixedRK4Stepper_H
#define fixedRK4Stepper_H


/*! \file fixedRK4Stepper.h
\brief Integrate using fixed stepsize classial (4th order) Runge-Kutta method.
*/


#include "GeneralDefinitions.h"
#include "Equation.h"
#include "Stepper.h"


///Integrate using fixed stepsize classial (4th order) Runge-Kutta method.
class fixedRK4Stepper : public Stepper
{

public:	
	
	///Constructor
	///\param [in] eq  equation 
	///\param [in] solAbsMax maximal value of solution at which the integration stopped (it is assumed that there is proximity of singularity)
	///\param [in] hmin  minimal stepsize
	///\param [in] hmax maximal stepsize
	fixedRK4Stepper( Equation * eq, double solAbsMax, double hmin  = 1e-14, double hmax  = 1e-6 ): Stepper( eq, solAbsMax ), hmin( hmin ), hmax( hmax ) {};
	///Destructor
	virtual ~fixedRK4Stepper( void ){};
	
	
	///Tries to make step form x with y value to x+h
	///\returns true - when step is good or false otherwise
	///\param [in] x beginning point
	///\param [in] y value of silution at the beginning
	///\param [in] h stepsize and direction (complex value)
	bool makeStep( cmplx x, cvector y, cmplx h ); 
	
	
	///\returns current after making step, if step failed returns last goog position
	cmplx getCurrentX( void ) { return currX; };
	
	
	///\returns current after making step; If step failed returns last goog position.
	cvector getCurrentY( void ) { return currY; };
	
	
private:
	
	///minimal value of step
	double hmin ;
	
	///maximal value of single step
	double hmax;
	
	///Performs classical RK4 step
	cvector RK4( cmplx x, cvector y, cmplx h);
	
	///Current Value of X;
	cmplx currX;
	
	///Current value of y
	cvector currY;

	
};



#endif
