#ifndef Mapper_H
#define Mapper_H


/*! \file Mapper.h
\brief /Maps path onto solution.
*/


#include "GeneralDefinitions.h"
#include "Equation.h"
#include "Initializer.h"
#include "Domain.h"
#include "Stepper.h"
#include "PathSolution.h"
#include "Path.h"


///Maps path onto solution
class Mapper
{
public:
	
	///Creates mapper for given equation and initial conditions IC in given domain with prescribed stepping method
	///\param [in] equation pointer to an equation object
	///\param [in] IC initial condition object
	///\param [in] domain domain of integration object
	///\param [in] stepper numerical integrator
	Mapper(Equation * equation, Initializer * IC, Domain * domain, Stepper * stepper );
	///Destructor
	virtual ~Mapper();
	
	///Solve equation along the path
	///\param [in] path path along which equation should be intergated
	///\warning path should begin at the point at which initial conditions are prescribed
	///\returns solution along path
	PathSolution * mapPath( Path * path );

protected:

	Stepper     * _stepper;
	
	Equation    * _equation;
	Initializer * _IC;
	
	Domain      * _domain;

};

#endif
