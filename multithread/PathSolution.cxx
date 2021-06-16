#include "PathSolution.h"

////////////////////////////////////////////////////////////////////////
void PathSolution::saveToFile( string filename )
{
	 ofstream absfile;
	 absfile.open ( filename.c_str(), std::fstream::app );
	 
	 //Format of writing data about solution:  Re(x) Im(x) Abs(y[1]) Abs(y[2])
	 for( unsigned long int i = 0; i < _x.size(); i++ )
		absfile << real( _x[i] ) << '\t' <<  imag( _x[i] ) <<  " \t " << abs(_y[i][1] ) << "\t" << arg( _y[i][1] ) << endl;
	
	absfile.close();
	
	
};
