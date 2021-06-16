#ifndef PathSolution_H
#define PathSolution_H

/*! \file PathSolution.h
\brief Defines solution along path
*/

#include "GeneralDefinitions.h"



///Keeeps solution along path 
class PathSolution
{
public: 
	
	///Constructor
	PathSolution(){};
	///Destructor
	virtual ~PathSolution(){};

	///Fills the solution with y(x) value
	///\param [in] x the value of x in y(x)
	///\param [in] y the value of y in y(x)
	void fill(cmplx x, cvector y) { _x.push_back(x); _y.push_back(y); };
	
	///Saves the path in file
	///\param [in] filename file to save the solution along path
	void saveToFile( string filename );	
	
	
	
protected:

		vector<cmplx> _x;
		vector<cvector> _y; 	
};


#endif
