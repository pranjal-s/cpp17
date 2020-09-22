# GNUPLOT INPUT FILE
# 08/30/2020, Pranjal Singh (pranjal.officemail@gmail.com)

set term svg size 500,500
set output "../build/plt.svg"
set encoding utf8

set key box opaque
#set key off
set style textbox opaque
set grid ytics lt 0 lw 1 lc rgb "#bbbbbb"
set grid xtics lt 0 lw 1 lc rgb "#bbbbbb"

file = "../build/plt.dat"

set ylabel 'y' 
set xlabel 'x'
# set xrange [-1.0:1.0]
# set yrange [0.5:1.5]
plot file u ($1):($2) w l title 'function', file u ($1):($3) w l lw 2 lc rgb 'green' title 'function\_newton'
unset label
unset yrange

quit
