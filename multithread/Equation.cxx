#include "Equation.h"

////////////////////////////////////////////////////////////////////////
void Equation::setRank( void )
{
	
	///Set rank of the equation
	eqRank = 2;
	
};

////////////////////////////////////////////////////////////////////////
cvector Equation::derivs( cmplx x, cvector y )
{
	
	//simple check
	assert( y.size() == eqRank + 1);
	
	//temporary vector of RHS of the equation
	cvector tmp( eqRank + 1 );
	
	
	//USER SECTION:
	
	///Write here the RHS of the equation:
	/// 1. Write an eqaution as a system of the first order ODEs
	/// 2. Write the RHS as tmp[i] = RHS_i, where i is the number of the equation, and RHS_i is a ith RHS of the equation
	/// \warning The numbering starts form 1 to the rank of the equation
	
	//parameters of the equation
	double alpha = 2.0; 
	int p = 5;
	
	
	//Equation y''(x)+(alpha/x)*y'(x)+y(x)^p = 0
	tmp[1] = y[2];
	tmp[2] = - alpha * y[2]/x -  pow( y[1], p );
	
	
	//END of USER SECTION
	
	return( tmp );	
}
