#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <sys/time.h>     /* gettimeofday() */



#include "GeneralDefinitions.h"

#include "Domain.h"
#include "Equation.h"
#include "Initializer.h"

#include "Path.h"
#include "SemilinePath.h"
#include "SpiralPath.h"
#include "SimplyConnectedDomain.h"

#include "PathSolution.h"
#include "DomainSolution.h"


#include "Stepper.h"
#include "fixedRK4Stepper.h"
#include "Mapper.h"





#include <pthread.h>
 
/// number of threads
#define NUM_THREADS    10

///Path type
/// 1 - semiline
/// 2 - spiral
const int  pathType = 1;

/// Domain of integration

const cmplx xLeftUp( -1.5, 1.5 );
const cmplx xRightDown( 1.5, -1.5 );

/*
const cmplx xLeftUp( -6.0, 6.0 );
const cmplx xRightDown( 6.0, -6.0 );
 */
////////////////////////////////////////////////////////////////////////

typedef struct {
    int     secs;
    int     usecs;
} TIME_DIFF;
 
TIME_DIFF * my_difftime (struct timeval *, struct timeval *);

struct timeval myTVstart, myTVend;
    time_t clock_start, clock_end;
    TIME_DIFF * difference;


TIME_DIFF * my_difftime (struct timeval * start, struct timeval * end)
{
    TIME_DIFF * diff = (TIME_DIFF *) malloc ( sizeof (TIME_DIFF) );
 
    if (start->tv_sec == end->tv_sec) {
        diff->secs = 0;
        diff->usecs = end->tv_usec - start->tv_usec;
    }
    else {
        diff->usecs = 1000000 - start->tv_usec;
        diff->secs = end->tv_sec - (start->tv_sec + 1);
        diff->usecs += end->tv_usec;
        if (diff->usecs >= 1000000) {
            diff->usecs -= 1000000;
            diff->secs += 1;
        }
    }
     
    return diff;
}

////////////////////////////////////////////////////////////////////////


///Data structure for threads
struct ThreadArgument
{
	///Pointer to the mapper for thread
	Mapper * mapper;
	
	///Pointer to the Domain Solution. 
	///\warning Acces must be synchronized by mutexWrite
	DomainSolution * domainSolution;
	
	///Pointer to the SimplyConnectedDomain. Keeps paths of integration.
	///\warning Access have to be synchronized by mutexRead
	SimplyConnectedDomain< Path > * paths;
	
	
	///Pointer to read mutex for paths.
	pthread_mutex_t * mutexRead;
	
	///Pointer to write mutex for domainSolution.
	pthread_mutex_t * mutexWrite;
	
	///Thread number for identification.
	int threadNr;
	
};

////////////////////////////////////////////////////////////////////////
 
 
///Thread function
///\arg argument pointer to ThreadArgument structure
void *TaskCode(void *argument)
{
 
	//unpacking argument
	struct ThreadArgument * arg = (struct ThreadArgument *) argument;
 
 
	//cout << "Hello - thread " <<  arg->threadNr << endl;
	
	//local variable for path 
	//SemilinePath * path;
	Path * path;
	
	//local variable for path solution
	PathSolution * pathSolution;
	
	//integrating loop over paths
	while( true )
	{		
		
		//get path
			//lock acces to the paths
			pthread_mutex_lock( arg->mutexRead );
		
			//cout << "reading"  << arg->threadNr << endl;
		
			
			if( arg->paths->hasNext() )
			{
				//take path if there is any and unlock paths
				path = arg->paths->getNextPath();
				pthread_mutex_unlock( arg->mutexRead );
			}
			else
			{
				//unlock paths and break form the integration loop
				pthread_mutex_unlock( arg->mutexRead );
				break;
			}
		

		//integrate along path
		
			//cout << "Start integrating" << arg->threadNr << endl;

			pathSolution = arg->mapper->mapPath( path );
		
			//cout <<" stop integrating " << arg->threadNr << endl;
		
		//save path solution
		
			//lock writing
			pthread_mutex_lock( arg->mutexWrite );
		
			//write path solution
			arg->domainSolution->fill( pathSolution );
		
			//cout << "writing" << arg->threadNr <<  endl;
		
			//unlock writing
			pthread_mutex_unlock( arg->mutexWrite );
	
	}
 
 
   return (0);
}


////////////////////////////////////////////////////////////////////////
 
int main(void)
{
	
	cout << "Hello" << endl;

	
	DomainSolution  domainSolution;
	//SimplyConnectedDomain< SemilinePath > paths; 
	SimplyConnectedDomain< Path > paths; 
	
	
	cout << "Creating paths ..." << endl;
	
	const int NDir = 2000;
	const double r0 = 0.0;
	const double rint = 0.00001;
	const double rstep = 0.01;
	
	double phase = 0.0;
	
	cmplx x( 0.0 );
	
	Path * path;
	
	for( unsigned long int dir = 0; dir < NDir + 1; dir++ )
	{
		
		phase = double(dir)/double(NDir) * 2.0 * M_PI;
		x = rint * exp( IU * phase );
		
		if( pathType == 1 )
		{
			path = new SemilinePath( x, phase, rstep );
		}
		else if( pathType == 2 )
		{
			path = new SpiralPath( 0.0, rstep, phase , 0.5, rint, 1.0 );
		} 
		
		paths.fill( path );
	}	
		
	cout << "...DONE" << endl;	
		
		
		
		
	
	cout << "Start scanning ... " << endl;
	
	cout << "...creating threads..." << endl;
	
	clock_start = clock ();
    gettimeofday (&myTVstart, NULL);

	
	//pool of threads
	pthread_t threads[NUM_THREADS];
	//pool of threads arguments
	struct ThreadArgument thread_args[NUM_THREADS];
	//code of thread creation/join
	int retCode;
 
	//set recursive mutex
	pthread_mutexattr_t Attr;
	pthread_mutexattr_init(&Attr);
	pthread_mutexattr_settype(&Attr, PTHREAD_MUTEX_RECURSIVE);
	
 
	//read mutex 
	pthread_mutex_t * mutexReadTmp = new pthread_mutex_t;
	pthread_mutex_init(mutexReadTmp, &Attr);
	//write mutex
	pthread_mutex_t * mutexWriteTmp =new pthread_mutex_t;
	pthread_mutex_init(mutexWriteTmp, &Attr);
 
   // create all threads one by one
   for(int i=0; i<NUM_THREADS; ++i ) 
   {
	  //preparing arguments for threads
		
		//Mapper - every thread has its own 
		thread_args[i].mapper = new Mapper( new Equation(), new Initializer(), new Domain ( xLeftUp, xRightDown ), new fixedRK4Stepper( new Equation(), 1000.0, 0.000001, 0.0001 ) );
		//paths - same for all threads
		thread_args[i].paths = & paths;
		//domain solution - same for all threads
		thread_args[i].domainSolution = & domainSolution;
		//reaing mutex - same for all threads
		thread_args[i].mutexRead  = mutexReadTmp;
		//writing mutex - same for all threads
		thread_args[i].mutexWrite = mutexWriteTmp;
		//thread index - unique for every thread
		thread_args[i].threadNr = i;  
      
      //creating thread
		//cout << "MAIN :: creating thread " << i << endl; 
      
		retCode = pthread_create(&threads[i], NULL, TaskCode, (void *) &thread_args[i]);
      
		//checking if the thread was created
		assert(0 == retCode);
   }
   
   
 
   // Waiting for threads to stop
   for(int i=0; i<NUM_THREADS; ++i) 
   {
      // block until thread i completes
      retCode = pthread_join(threads[i], NULL);

	  //delete mapper for the thread that joined
      delete thread_args[i].mapper;
      
      //cout << "MAIN :: join of thread " << i << endl;
     
	  //Check if the joining was succesfull
      assert(0 == retCode);
   }

	//delete mutexes
	
		delete mutexReadTmp;
		delete mutexWriteTmp;
   
   clock_end = clock ();
    gettimeofday (&myTVend, NULL);
    
    difference = my_difftime (&myTVstart, &myTVend);
    printf ("Time difference due to gettimeofday: %3d.%6d secs.\n", difference->secs, difference->usecs);

	free (difference);

 
	cout << "MAIN :: all threads ended sucessfully" << endl;
   
   cout << endl << "... DONE" << endl;
	

	
	
	cout << endl <<"Saving results..." << endl;
	
		domainSolution.saveToFile( string( "abs.out" ) );
	
	cout << "...DONE" << endl;
	
	
	
	cout << endl;
   
   
   return(0);
}
