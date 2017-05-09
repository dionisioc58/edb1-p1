reset
set key on
set terminal png size 1280,960 enhanced font 'Helvetica,12'
set output './images/BSR.png'
set title 'Busca Sequencial Recursiva'
set grid
set xrange[10000:100000]
set xtics 4500
set xlabel 'Tamanho do vetor'
set ylabel 'Número de passos'
set xtic rotate by -90 scale 0
set yrange[0:294015]
plot './data/BSR.dat' using 1:2 title 'Melhor Caso' lw 2 with lines, './data/BSR.dat' using 1:3 title 'Médio Caso' lw 2 with lines, './data/BSR.dat' using 1:4 title 'Pior Caso' lw 2 with lines
