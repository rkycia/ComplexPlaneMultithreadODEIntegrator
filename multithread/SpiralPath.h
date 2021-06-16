#ifndef SpiralPath_H
#define SpiralPath_H


/*! \file SpiralPath.h
\brief Defines semilie path that which consists of line segments
*/


#include "GeneralDefinitions.h"
#include "Path.h"



///Semiline path
class SpiralPath : public Path
{

public:
	
	///Constructor. Initializes path form xbegin along the spiral path, in polar coordinate system r( \theta ) = a * \theta + b
	///\param [in] xbegin beggining point of the path
	///\param [in] h step along spiral [rad]
	///\param [in] phi spiral roation angle [rad]  xbegin + spiral(i dir (theta + phi ) )
	///\param [in] a parameter of spiral
	///\param [in] b parameter of spiral
	///\param [in] dir a direction of spiral +1 - anticlockwise; -1 - clockwise; 0 - line:  xbegin + spiral(i dir (theta + phi) )
	SpiralPath( cmplx xbegin, double h, double phi = 0.0 ,double a = 1.0, double b = 0.0, double dir = 1.0 );
	
	///Destructor
	virtual ~SpiralPath(){};
	
	///\returns beginning point of the path
	cmplx getBeginning( void ) { theta = 0.0; return spiral( theta );};
	
	///Check if next point on the path exists
	///Path is semiline so method returns true
	/// \returns true
	bool  hasNext( void ) {return true;};
	
	///\returns next path point
	cmplx getNext( void );
	
private:

	///Function that return point at theta on the spiral
	/// \returns spiral_point( theta )
	/// \param theta parameter along spiral (angle)
	cmplx spiral( double theta );

	cmplx xbegin;
	double theta;
	double h;
	double _phi;
	double _a;
	double _b;
	double _dir;	
	
};



#endif
