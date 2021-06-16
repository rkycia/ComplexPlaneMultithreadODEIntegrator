#include "fixedRK4Stepper.h"


////////////////////////////////////////////////////////////////////////
cvector fixedRK4Stepper::RK4( cmplx x, cvector y, cmplx h)
{
	
	assert( y.size() == eq->getRank() + 1);
	
	
	cvector k1( eq->getRank() + 1 ); 
	cvector k2( eq->getRank() + 1 );
	cvector k3( eq->getRank() + 1 );
	cvector k4( eq->getRank() + 1 );
	
	cmplx xtmp;
	cvector ytmp( eq->getRank() + 1 );
	
	
	k1 = eq->derivs( x, y );
	
	for( int i = 1; i < eq->getRank() + 1; i++ )
	{
		xtmp = x + 0.5 * h;
		ytmp[i] = y[i] + 0.5 * h * k1[i];
	}

	k2 = eq->derivs( xtmp, ytmp );
	
	for( int i = 1; i < eq->getRank() + 1; i++ )
	{
		xtmp = x + 0.5 * h;
		ytmp[i] = y[i] + 0.5 * h * k2[i];
	}

	k3 = eq->derivs( xtmp, ytmp );
	
	for( int i = 1; i < eq->getRank() + 1; i++ )
	{
		xtmp = x + h;
		ytmp[i] = y[i] + h * k3[i];
	}

	k4 = eq->derivs( xtmp, ytmp );

	//calculate new value
	for( int i = 1; i < eq->getRank() + 1; i++ )
	{
		ytmp[i] = y[i] + h * ( k1[i] + 2.0 * k2[i] + 2.0 * k3[i] + k4[i] ) / 6.0;
	}


	return( ytmp );
	
};


////////////////////////////////////////////////////////////////////////
bool fixedRK4Stepper::makeStep( cmplx x, cvector y, cmplx h )
{
	assert( abs( h ) > 0 );
	
	cvector ytmp( eq->getRank() + 1 );
	

	long int count = 0;
	
	//backup initial values
	bool isOk = false;
	currY = y;
	currX = x;
	
	
	if( (abs( h ) <= hmax) &&  (abs( h ) >= hmin) )
	{
		ytmp = RK4( x, y, h );
		
		if( isSolutionBoundedMax( ytmp, eq->getRank() ) )
		{
			currX = x + h;
			currY = ytmp;
			isOk = true;
		}
		
	}
	else if( abs( h ) < hmin ) 
	{
		cerr << "Too small step - continuing with the same value" << endl;
		
		currX = x;
		currY = y;
		isOk = true;
	}	
	else
	{
		long int Nsteps = (long int) (abs( h ) / hmax );
		
		cmplx xstep = h / double( Nsteps );
		
		cmplx xtmp = x;
		
		ytmp = y;
		
		for( int i = 1; i < Nsteps + 1; i++ ) 
		{
			
			ytmp = RK4( xtmp, ytmp, xstep );
			
			//detect singularity
			if( isSolutionBoundedMax( ytmp, eq->getRank() ) )
			{
				currX = xtmp + xstep;
				currY = ytmp;
				isOk = true;
			}
			else
			{
				isOk = false;
				break;
			}
			
			
			xtmp = xtmp + xstep;
			
			count++;
				
		}
		
		if( isOk == true )
		{
			//final correction step
			ytmp = RK4( xtmp, ytmp, x + h - xtmp );
		
			//detect singularity
			if( isSolutionBoundedMax( ytmp, eq->getRank() ) )
			{
				currX = x + h;
				currY = ytmp;
				isOk = true;
			}
			else
			{
				isOk = false;
			}
		
		
			count++;
		}
		
	}
	
	//cout << "count = " << count << endl;
	
	return( isOk );
	
	
};
