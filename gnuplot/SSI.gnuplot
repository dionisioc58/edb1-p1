reset
set key on
set terminal png size 1280,960 enhanced font 'Helvetica,12'
set output './images/SSI.png'
set title 'Selection Sort Iterativa'
set grid
set xrange[1000:10000]
set xtics 450
set xlabel 'Tamanho do vetor'
set ylabel 'Número de passos'
set xtic rotate by -90 scale 0
set yrange[0:501426]
plot './data/SSI.dat' using 1:2 title 'Melhor Caso' lw 2 with lines, './data/SSI.dat' using 1:3 title 'Médio Caso' lw 2 with lines, './data/SSI.dat' using 1:4 title 'Pior Caso' lw 2 with lines
