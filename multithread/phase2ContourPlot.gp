#gnuplot file to plot abs of complex solution and contour plot 

set dgrid3d 100, 100
set style data lines
set ticslevel 0
set xlabel "Re"
set ylabel "Im"
set zlabel "phase"


set ticslevel -2

#set contour base

set contour both

#unset pm3d
set pm3d at bst

set cntrparam levels incremental 0, 0.2, 5

unset key

splot 'abs.out' u 1:2:4 t "phase" with pm3d
pause -1 "Press Enter to continue..."

set terminal postscript eps color enhanced
#set terminal postscript eps  enhanced

set out "PhaseContour2Solution.eps"  
replot
set terminal x11 enhanced"


print "Figure PhaseContour2Solution.eps saved"
