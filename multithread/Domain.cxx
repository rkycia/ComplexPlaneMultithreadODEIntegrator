#include "Domain.h"

////////////////////////////////////////////////////////////////////////

Domain::Domain( cmplx zleft, cmplx zright ) : zleft( zleft ), zright( zright )
{};
	
	
////////////////////////////////////////////////////////////////////////	
bool Domain::isInDomain( cmplx z )
{
	if( ( real( z ) <= real( zright ) ) && ( real( z ) >= real( zleft ) ) && ( imag( z ) >= imag( zright ) && ( imag( z ) <= imag( zleft ) ) ) ) 
		return true;
	else
		return false;
	
};
