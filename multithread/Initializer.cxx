#include "Initializer.h"


////////////////////////////////////////////////////////////////////////
cvector Initializer::initialize( cmplx x0, Equation * eq )
{
	
	
	cvector ytmp( eq->getRank() + 1 );
	
	
	//USER SECTION:
	
	//define parameters
	double alpha = 2.0; 
	int p = 5;
	double c = 1.5;
	
	double c0 = pow( c, p);
	
	//define solutions for y[1], y[2],.... vector of y(x0)
	
	ytmp[1] =  c- x0*x0*c0/(2.0*(1.0+alpha));
	ytmp[2] =  -x0*c0/(1.0+alpha);
	
	
	//END of USER SECTION
	
	
	return( ytmp );
	
};
