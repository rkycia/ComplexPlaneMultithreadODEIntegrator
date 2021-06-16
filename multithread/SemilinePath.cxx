#include "SemilinePath.h"



////////////////////////////////////////////////////////////////////////
SemilinePath::SemilinePath( cmplx xbegin, double phi, double h, double shift ) : xbegin(xbegin), phi(phi), h(h), xprev(xbegin), shift(shift)
{};

////////////////////////////////////////////////////////////////////////
cmplx SemilinePath::getNext( void ) 
{
	xprev = xprev + (h + shift) * exp( IU * phi );
	return( xprev );
};
