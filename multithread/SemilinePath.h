#ifndef SemilinePath_H
#define SemilinePath_H


/*! \file SemilinePath.h
\brief Defines semilie path that which consists of line segments
*/


#include "GeneralDefinitions.h"
#include "Path.h"



///Semiline path
class SemilinePath : public Path
{

public:
	
	///Constructor. Initializes path form xbegin along the direction given by phi angle (radians), with h step
	///\param [in] xbegin beggining point of the path
	///\param [in] phi  angle of the semiline with respect to the positive real direction; in radians
	///\param [in] h length of the line segment
	SemilinePath( cmplx xbegin, double phi, double h, double shift = 0.0 );
	
	///Destructor
	virtual ~SemilinePath(){};
	
	///\returns beginning point of the path
	cmplx getBeginning( void ) { xprev = xbegin + shift * exp( IU * phi ); return xbegin;};
	
	///Check if next point on the path exists
	///Path is semiline so method returns true
	/// \returns true
	bool  hasNext( void ) {return true;};
	
	///\returns next path point
	cmplx getNext( void );
	
private:

	cmplx xbegin;
	cmplx xprev;
	double phi;
	double h;
	double shift;
};



#endif
