reset
set key on
set terminal png size 1280,960 enhanced font 'Helvetica,12'
set output './images/BBI.png'
set title 'Busca Binária Iterativa'
set grid
set xrange[0:1000]
set xtics 100
set xlabel 'Tamanho do vetor'
set ylabel 'Número de passos'
set xtic rotate by -90 scale 0
set yrange[0:48]
plot './data/BBI.dat' using 1:2 title 'Melhor Caso' lw 2 with lines, './data/BBI.dat' using 1:3 title 'Médio Caso' lw 2 with lines, './data/BBI.dat' using 1:4 title 'Pior Caso' lw 2 with lines
