reset
set key on
set terminal png size 1280,960 enhanced font 'Helvetica,12'
set output './images/BBR.png'
set title 'Busca Binária Recursiva'
set grid
set xrange[1000000:1100000]
set xtics 10000
set xlabel 'Tamanho do vetor'
set ylabel 'Número de passos'
set xtic rotate by -90 scale 0
set yrange[0:93]
plot './data/BBR.dat' using 1:2 title 'Melhor Caso' lw 2 with lines, './data/BBR.dat' using 1:3 title 'Médio Caso' lw 2 with lines, './data/BBR.dat' using 1:4 title 'Pior Caso' lw 2 with lines
