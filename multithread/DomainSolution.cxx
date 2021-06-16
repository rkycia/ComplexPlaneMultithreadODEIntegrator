#include "DomainSolution.h"


////////////////////////////////////////////////////////////////////////
void DomainSolution::saveToFile( string filename )
{
	 
	 for( unsigned long int i = 0; i < _domainSolution.size(); i++ )
		_domainSolution[i]->saveToFile( filename );	
	
};


////////////////////////////////////////////////////////////////////////
DomainSolution::~DomainSolution()
{
	for( unsigned long int i = 0; i < _domainSolution.size(); i++ )
		delete _domainSolution[i];	
	
};
