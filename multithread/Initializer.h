#ifndef Initializer_H
#define Initializer_H

/*! \file Initializer.h
\brief Defines initial conditions
*/

#include "GeneralDefinitions.h"
#include "Equation.h"



//Calculates initial value
class Initializer{
	
public:	
	
	///Constructor
	Initializer(){};
	///Destructor
	virtual ~Initializer(){};
	
	///Calaculates initial data at x0;
	///\param [in] x0 point at which the initial conditions are calculated
	///\param [in] eq pinter to the equation class
	///\returns the value of the solution at x0 - initial conditions
	///\warning Should be supplied by the User.
	cvector initialize( cmplx x0, Equation * eq );

};

#endif
