/*!
 
 
\mainpage  Complex plane integrator - multithread version.



\authors 

Radoslaw A. Kycia

rkycia@mimuw.edu.pl

The Faculty of Mathematics, Informatics and Mechanics (MIM)

University of Warsaw

Warszawa, Poland


\brief

Program integrate Ordinary Differential Equation (ODE) with prescribed initial data along the paths on the complex plane in some domain. Then reconstruct plots of the solutions.


\warning
1. The programs can serve as an qualitative tools used to illustration of solutions or first step in examination of ODEs (Ordinary Differential Equations). Be warned if you want to use them in quantitative studies.
2. The programs were written by means of high standards, however, author is not responsible for any damages that result from the use of these program. Use them at your own risk.
3. If you have any comments, suggestions, questions please write. I will try to answer them in reasonable time.



Dependence:

- GNU C++ compiler - for compilation
- GNU Make - handling compilation, running visualization. Treat as interpreter.
- gnuplot  - plotting/visualization tool
- Doxygen  - generation of documentation
- Valgrind - for debugging
- pthreads library - for multithreading (for multithread program)




There are following options (type in terminal to see the output):

 - make run - compile and run program. Should be executed before generating plots.
 - make run-full - compile and run program and then generate plot.
 - make [absPlot, absContourPlot,abs2ContourPlot]  - every option creates an interactive plot of the absolute value of a solution in the complex plane and saves it to disk.
 - make [phasePlot, phaseContourPlot, phase2ContourPlot] - every option creates appropriate plot of the phase of the solution in the complex plane and saves it to disk.
 - make absPhasePlot - create the plot of the modulus of a solution with with colour map that reflects the phase of the solution and saves it to disk.
 - make areaOfConvergence - create the plot of the paths of integration in the complex plane and save it to disk.
 - make animate - create animated gif file and open it in a default browser.
 - make Generate-doc - generates documentation from the code in html and TeX formats using Doxygen.
 - make clean - clean the directory from compilation and output files.


License:

This file is part of Complex plane integrator.

    Complex plane integrator is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License any later version.

    Complex plane integrator is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Complex plane integrator. If not, see <http://www.gnu.org/licenses/>.


*/
