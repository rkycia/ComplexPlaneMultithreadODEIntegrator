#ifndef Equation_H
#define Equation_H


/*! \file Equation.h
\brief Defines equation as a system of first order ODEs
*/


#include "GeneralDefinitions.h"


///Contains the information about the differential equation
class Equation
{
public:
	
	///Constructor
	Equation( void ) { setRank(); };
	///Destructor
	virtual ~Equation( void ){};
	
	///Calculate RHS of equations
	///\param x value of independent variable at which the RHS of the equations are calculated
	///\param y value of dependent varaible at which the RHS of the equations are calculated
	///\returns vextor of RHS of the system of first order equations
	///\warning User should adjust it to its needs
	cvector derivs( cmplx x, cvector y );
	
	///\returns The rank of the equation
	int getRank( void ){ return eqRank; };
	
	
private:
	
	///Set rank of the equation
	void setRank( void );
	
	///Rank of the equation
	int eqRank;
	
	
};









#endif
