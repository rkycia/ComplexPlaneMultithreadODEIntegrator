#include "SpiralPath.h"



////////////////////////////////////////////////////////////////////////
SpiralPath::SpiralPath( cmplx xbegin, double h, double phi, double a, double b, double dir ) : xbegin(xbegin), h(h), _phi(phi), _a(a), _b(b), _dir(dir), theta( 0.0 )
{};

////////////////////////////////////////////////////////////////////////
cmplx SpiralPath::getNext( void ) 
{
	theta = theta + h;
	return( spiral( theta ) );
};

////////////////////////////////////////////////////////////////////////
cmplx SpiralPath::spiral( double theta )
{	

	cmplx x = (xbegin + (_a * theta + _b) * exp( IU * _dir * theta) ) * exp( IU * _phi) ;
	 
	return( x );
	
}
