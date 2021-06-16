#File used in animate.gp for generation of frames

xrot =(xrot+xrot_delta)%360
zrot =(zrot+zrot_delta)%360

set view xview(xrot), zview(zrot), 1, 1

splot 'abs.out' u 1:2:3:4 with points pointtype 5 palette

iteration_count=iteration_count+1
if (iteration_count < limit_iterations) reread
