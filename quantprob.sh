#! /usr/bin/bash

gnuplot << EOF
set terminal png 
set output "~/picture/Quantum.png"
set title "Spherical Bessel Function "
set xrange [0:20]
set yrange [-5:5]

plot sin(x)/x title "Spherical B l = 0"  lc 'red'
replot cos(x)/x title "Spherical N l = 0"  lc 'violet'
replot -cos(x)/x + sin(x)/x^2 title "Spherical B l = 1"  lc 'blue'
replot sin(x)/x + cos(x)/x^2 title "Spherical N l = 1"  lc 'green'

exit
EOF

eog ~/picture/Quantum.png

