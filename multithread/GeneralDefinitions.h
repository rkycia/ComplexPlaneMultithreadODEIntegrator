#ifndef GeneralDefinition_H
#define GeneralDefinition_H


/*! \file GeneralDefinition.h
\brief Defines types and constants used in every class.
*/



#include <iostream>
#include <math.h>
#include <complex>
#include <cmath>
#include <vector>
#include <fstream>


#include <assert.h>


using namespace std;



/*! \var typedef complex< double >
* \brief A type of complex for numbers.
* Use:  cmplx complex_number1, complex_number2;
*/
typedef complex< double >  cmplx;


/*! \var typedef vector < cmplx >
* \brief A type of a vector of complex numbers.
* Use:  cvector comlex_vector( size );
*
* \warning It is assumed that vector starts from 1 to dim, i.e., there is no usage of 0th vector component,
*/
typedef vector < cmplx >  cvector;

///Imaginary unit
const cmplx IU( 0.0, 1.0 );

///Real unit
const cmplx RU( 1.0, 0.0 );


#endif
