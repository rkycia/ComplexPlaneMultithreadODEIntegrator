#ifndef Domain_H
#define Domain_H

/*! \file Domain.h
\brief Defines a regionin which the integration is performed.
*/


#include "GeneralDefinitions.h"


///Defines square region in which the solution is defined
class Domain
{

public:	
	
	///Constructor
	///\param [in] zleft  left upper corner of th rectangle 
	///\param [in] zright  right lowest corner of th rectangle 
	Domain( cmplx zleft, cmplx zright );
	///Destructor
	virtual ~Domain( void ){};
	
	///Chcek if z is in the region
	///\param z - coordinate to be checked if it is in the region
	///\returns true if z is in the region of false otherwise
	bool isInDomain( cmplx z );
	
	
private:	
	
	cmplx zleft;	/**< left upper corner of th rectangle */
	cmplx zright;   /**< right lowest corner of th rectangle  */

};


#endif
