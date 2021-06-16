#gnuplot file for plotting abs of the solution on the complex plane

set dgrid3d 100, 100
set style data lines
set ticslevel 0
set xlabel "Re"
set ylabel "Im"
set zlabel "|solution|"


splot 'abs.out' u 1:2:3 t "|solution|" with pm3d
pause -1 "Press Enter to continue..."

set terminal postscript eps color enhanced
#set terminal postscript eps  enhanced

set out "AbsSolution.eps"
replot
set terminal x11 enhanced"

print "Figure AbsSolution.eps saved"
