#----------------------------------------------------------------------
#       make run
#----------------------------------------------------------------------
.SUFFIXES:  .o .c .cxx .f .l  .s  .sh  .h  .a
#======================================================================
# ROOT:
# -flags
 
# -includes 

#GSL:

 GSLLDFLAGS      := $(shell gsl-config --libs)

#valgrin suppresion
VALGRINDSUPP = 

#======================================================================
#####  GNU c++ compiler
CXXFLAGS    = -g  -ansi -Wall  -I.  -pthread -std=c++11
LDFLAGS     = $(GSLLDFLAGS)   -pthread
CXX         =  g++
CLD         =  g++
#-----------------------------
# Compile all c++ files
%.o : %.cxx
	$(CXX) $(CXXFLAGS) -c $<
#======================================================================


#------------------------------------------------------------------------------
HEADERS = GeneralDefinitions.h Path.h Domain.h SimplyConnectedDomain.h PathSolution.h DomainSolution.h Equation.h Initializer.h SemilinePath.h SpiralPath.h Stepper.h fixedRK4Stepper.h Mapper.h

OBJECTS = Domain.o Equation.o Initializer.o SemilinePath.o SpiralPath.o SimplyConnectedDomain.o PathSolution.o DomainSolution.o Stepper.o fixedRK4Stepper.o Mapper.o

#------------------------------------------------------------------------------
main.x: main.o $(OBJECTS) 
	$(CLD) -o main.x $^ $(LDFLAGS)
#------------------------------------------------------------------------------
run: main.x
	(time ./main.x)
#------------------------------------------------------------------------------
absPlot: 
	gnuplot absPlot.gp

#------------------------------------------------------------------------------
absContourPlot: 
	gnuplot absContourPlot.gp

#------------------------------------------------------------------------------
abs2ContourPlot:
	gnuplot abs2ContourPlot.gp
#------------------------------------------------------------------------------
areaOfConvergence:
	gnuplot areaOfConvergence.gp
#------------------------------------------------------------------------------
phasePlot:
	gnuplot phasePlot.gp
#------------------------------------------------------------------------------
phaseConturPlot:
	gnuplot phaseContourPlot.gp
#------------------------------------------------------------------------------
phase2ContourPlot:
	gnuplot phase2ContourPlot.gp
#------------------------------------------------------------------------------
absPhasePlot:
	gnuplot absPhasePlot.gp
#------------------------------------------------------------------------------
run-full: run absPhasePlot
#------------------------------------------------------------------------------
animate:
	gnuplot animate.gp
	xdg-open animate.gif
#------------------------------------------------------------------------------
Generate-doc:	
	
	-doxygen -g 
	-echo 'PROJECT_NAME = "Complex plane integrator"' >> Doxyfile
	-doxygen Doxyfile
	-firefox ./html/index.html
#-------------------------------------------------------------------------------
check-memleak: clean main.x
	 valgrind --leak-check=yes --show-reachable=yes --suppressions=$(VALGRINDSUPP) --log-file=valgrin.log ./main.x
#-------------------------------------------------------------------------------
check-memleakfull: clean main.x
	 valgrind --leak-check=full --show-reachable=yes --suppressions=$(VALGRINDSUPP) --log-file=valgrin.log ./main.x
#-------------------------------------------------------------------------------
check-prof: clean main.x 
	 valgrind --tool=cachegrind --suppressions=$(VALGRINDSUPP) --log-file=valgrin.log ./main.x
	 cg_annotate cachegrind.out.*
#-------------------------------------------------------------------------------
check-call: clean main.x
	valgrind --tool=callgrind --suppressions=$(VALGRINDSUPP) --log-file=valgrin.log ./main.x
	callgrind_annotate callgrind.out.*
#-------------------------------------------------------------------------------
check-alloc: clean main.x
	valgrind  --tool=exp-dhat --suppressions=$(VALGRINDSUPP) --log-file=valgrin.log ./main.x
#-------------------------------------------------------------------------------
check-heap: clean main.x
	valgrind  --tool=massif --suppressions=$(VALGRINDSUPP)--log-file=valgrin.log ./main.x
	ms_print massif.out.*
#-------------------------------------------------------------------------------
line_count:
	(cat *.cxx *.h | wc -l )
#==============================================================================

#==============================================================================
clean:
	(rm -f *.o *.a *~ *.x core *.gz lmap *.out *.dvi *.aux *.log )
#------------------------------------------------------------------------------
