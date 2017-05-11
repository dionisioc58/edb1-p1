reset
set key on
set terminal png size 1280,960 enhanced font 'Helvetica,12'
set output './images/MSR.png'
set title 'Merge Sort Recursivo'
set grid
set xrange[1:2]
set xtics 0
set xlabel 'Tamanho do vetor'
set ylabel 'Número de passos'
set xtic rotate by -90 scale 0
set yrange[0:37]
plot './data/MSR.dat' using 1:2 title 'Melhor Caso' lw 2 with lines, './data/MSR.dat' using 1:3 title 'Médio Caso' lw 2 with lines, './data/MSR.dat' using 1:4 title 'Pior Caso' lw 2 with lines
