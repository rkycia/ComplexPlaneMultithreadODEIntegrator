set style data lines
set xlabel "Re"
set ylabel "Im"


plot 'abs.out' u 1:2  t "integration paths"
pause -1 "Press Enter to continue..."

set terminal postscript eps color enhanced
#set terminal postscript eps  enhanced

set out "AreaOfConvergence.eps"
replot
set terminal x11 enhanced


print "Figure AreaOfConvergence.eps saved"
