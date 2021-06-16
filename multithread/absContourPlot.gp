#gnuplot file to plot abs of complex solution and contour plot 

set dgrid3d 100, 100
set style data lines
set ticslevel 0
set xlabel "Re"
set ylabel "Im"
set zlabel "|solution|"


set ticslevel -2

#set contour base

set contour both

#unset pm3d
set pm3d at bst

set cntrparam levels incremental 0, 0.2, 5

unset key

splot 'abs.out' u 1:2:3 t "|solution|" with pm3d
pause -1 "Press Enter to continue..."

set terminal postscript eps color enhanced
#set terminal postscript eps  enhanced

set out "AbsContourSolution.eps"  
replot
set terminal x11 enhanced"


print "Figure AbsContourSolution.eps saved"
