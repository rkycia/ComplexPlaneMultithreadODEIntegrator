#ifndef SimplyConnectedDomain_H
#define SimplyConnectedDomain_H


/*! \file SimplyConnectedDomain.h
\brief Defines the set of the paths of integration that defines domain.
*/


#include "GeneralDefinitions.h"



///Contains all paths that defines given region
template <class pathType> 
class SimplyConnectedDomain
{
public:
	
	///Constructor
	SimplyConnectedDomain():_curr(0){};
	///Destructor
	virtual ~SimplyConnectedDomain();
	
	///Add path to internal structure
	///\param [in] path pointer to the path; The path object is destroyed in destructor.
	void fill( pathType * path ){ _paths.push_back( path ); };
	///\returns pointer to i-th path. 
	///\param [in] i the number of path.
	///\warning No checking of index boud is assumed
	pathType * getPath( unsigned long int i ){ return _paths[i]; };
	///\returns number of paths
	unsigned long int getNPaths( void ) {return _paths.size(); };
	
	///\returns true if there is next path
	bool hasNext( void ){ return( _curr < _paths.size() ); };
	
	///\returns next path
	///\warning no checking is done user should check it using hasNext()
	pathType * getNextPath( void ){ return _paths[_curr++]; };
	
	
protected:
	
	vector<pathType *> _paths; 
	
	//current path number
	unsigned long int _curr;
	
};

////////////////////////////////////////////////////////////////////////
template <class pathType> 
SimplyConnectedDomain<pathType>::~SimplyConnectedDomain()
{
	for( unsigned long int i = 0; i < _paths.size(); i++ )
		delete _paths[i];	
	
};


#endif
