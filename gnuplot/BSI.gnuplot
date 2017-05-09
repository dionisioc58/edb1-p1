reset
set key on
set terminal png size 1280,960 enhanced font 'Helvetica,12'
set output './images/BSI.png'
set title 'Busca Sequencial Iterativa'
set grid
set xrange[10000:200000]
set xtics 9500
set xlabel 'Tamanho do vetor'
set ylabel 'Número de passos'
set xtic rotate by -90 scale 0
set yrange[0:199012]
plot './data/BSI.dat' using 1:2 title 'Melhor Caso' lw 2 with lines, './data/BSI.dat' using 1:3 title 'Médio Caso' lw 2 with lines, './data/BSI.dat' using 1:4 title 'Pior Caso' lw 2 with lines
