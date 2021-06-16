#ifndef Path_H
#define Path_H


/*! \file Equation.h
\brief Defines interfece for the classes that defines a path.
*/


///Interface for different paths
class Path
{

public:	
	
	///Constructor
	Path( void ){};
	///Desctructor
	virtual ~Path( void ){};
	
	///\returns beginning point of the path
	virtual cmplx getBeginning( void ) = 0;
	///\returns if the path has a next point
	virtual bool hasNext( void ) = 0;
	///\returns next path point
	virtual cmplx getNext( void ) = 0;
	
};

#endif
