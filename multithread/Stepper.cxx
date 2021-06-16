#include "Stepper.h"


////////////////////////////////////////////////////////////////////////
double Stepper::norm( cvector vect, int rank )
{
	
	assert( vect.size() == rank + 1 );
	
	double tmp  = 0.0;
	
	//calculate euclidean norm
	for( int i = 1; i < rank + 1; i++ )
	{
		tmp = tmp + abs( vect[i] ) * abs( vect[i] );
	}
	
	return( sqrt( tmp ) );
};

////////////////////////////////////////////////////////////////////////
bool Stepper::isSolutionBoundedNorm( cvector sol, int rank )
{
	
	assert( sol.size() == rank + 1 );
	
	double tmp = norm( sol, rank );
	
	if( tmp <= solAbsMax )
		return true;
	else
		return false;
};

////////////////////////////////////////////////////////////////////////
bool Stepper::isSolutionBoundedMax( cvector sol, int rank )
{
	
	assert( sol.size() == rank + 1 );
	
	double tmp = abs( sol[1] );
	
	for( int i = 2; i < rank + 1; i++ )
	{
		tmp = max( tmp, abs( sol[i] ) );
	}
	
	if( tmp <= solAbsMax )
		return true;
	else
		return false;
};
