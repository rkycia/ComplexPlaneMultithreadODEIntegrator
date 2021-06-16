#ifndef DomainSolution_H
#define DomainSolution_H

/*! \file DomainSolution.h
\brief Defines solution in domain
*/

#include "GeneralDefinitions.h"
#include "PathSolution.h"

///Contains solution in the domain
class DomainSolution
{
public: 

	///Constructor
	DomainSolution(){};
	///Destructor
	virtual ~DomainSolution();
	
	///Saves path solution in internal structure
	///\param [in] ps pointer to the path solution; The class destroy path solution in destructor.
	void fill(PathSolution * ps) { _domainSolution.push_back(ps); };
	
	///Saves solution to the file
	///\param [in] filename name of the file to save data.  The text file.
	void saveToFile( string filename );	
	
	
protected:
		
	vector< PathSolution * > _domainSolution;	
	
	
};


#endif
