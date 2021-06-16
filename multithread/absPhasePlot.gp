set xlabel "Re"
set ylabel "Im"
set zlabel "|solution|"
set cblabel "phase"

set hidden3d

unset key


#set dgrid3d 100,100
#set ticslevel -2
#set contour both
#set cntrparam levels incremental 0, 0.2, 5


set ticslevel 0

set pointsize 0.5


set palette model RGB defined (-2 "red",0 "blue", 2 "green")

splot 'abs.out' u 1:2:3:4 with points pointtype 5 palette
#splot 'abs.out' u ($1):2:3:4 with points pointtype 5 palette

pause -1 "Press Enter to continue..."


set terminal postscript eps color enhanced
#set terminal postscript eps  enhanced

set out "absPhaseSolution.eps"
replot
set terminal x11 enhanced"


print "Figure absPhaseSolution.eps saved"

