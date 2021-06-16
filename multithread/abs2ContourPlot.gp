set style data lines
set xlabel "Re"
set ylabel "Im"
#set isosample 100,100
set dgrid3d 100, 100


set pm3d map
splot 'abs.out' u 1:2:3 t "|solution|"
pause -1 "Press Enter to continue..."

set terminal postscript eps color enhanced
#set terminal postscript eps  enhanced

set out "ContourSolution.eps"
replot
set terminal x11 enhanced"


print "Figure ContourSolution.eps saved"
