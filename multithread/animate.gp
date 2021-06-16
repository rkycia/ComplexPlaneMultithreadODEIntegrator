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


set term gif animate
set output "animate.gif"

limit_iterations=72
xrot=30
xrot_delta = 0
zrot=136
zrot_delta = 355
xview(xrot)=xrot
zview(zrot)=zrot
set view xview(xrot), zview(zrot), 1, 1

iteration_count=0

load 'frames.gp'


set output

print "Figure animate.gif saved"
