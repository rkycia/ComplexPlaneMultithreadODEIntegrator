#include "Mapper.h"



////////////////////////////////////////////////////////////////////////
Mapper::Mapper(Equation * equation, Initializer * IC, Domain * domain, Stepper * stepper ) : _stepper(stepper), _IC(IC), _equation(equation), _domain(domain)
{};

Mapper:: ~Mapper()
{
	delete  _stepper;
	delete  _equation;
	delete  _IC;
	delete _domain;
	
};

PathSolution * Mapper::mapPath( Path * path )
{
	PathSolution * pathSolution = new PathSolution();
	
	cmplx x( 0.0 );
	cmplx h( 0.0 );
	
	cvector y( _equation->getRank() + 1 );	
	
	x = path->getBeginning(); 
		
	y = _IC->initialize( x, _equation );
		
	h = path->getNext() - x;
	path->getNext();
		
		
	while( _domain->isInDomain( x ) && path->hasNext() )
	{
		
		if( _stepper->makeStep( x, y, h ) )
		{
			y = _stepper->getCurrentY();
			h = path->getNext() - x;
			x = x + h;
				
			pathSolution->fill( x, y );
				
		}
		else
		{
			cout << endl << "Singularity encountered at " << x << endl;
		
			x = _stepper->getCurrentX();
			y = _stepper->getCurrentY();
			
			pathSolution->fill( x, y );								
				
			break;
				
				
		}
		
		
	}
	
	
	return( pathSolution );	
	
};
