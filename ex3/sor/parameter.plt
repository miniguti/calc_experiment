#parameter
set term postscript color enhanced
set output "parameter.eps"
set multiplot

set xlabel "{w}"
set ylabel "iteration"

unset key

plot "parameter20.dat"


set size 0.45, 0.55
set origin 0.5, 0.35

set xtics 0.1
set ytics 10


plot "parameter20_ex.dat"


unset multiplot

pause -1
