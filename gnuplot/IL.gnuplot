reset
set key on
set terminal png size 1280,960 enhanced font 'Helvetica,12'
set output './images/IL.png'
set title 'Inserir na Lista'
set grid
set xrange[10000:100000]
set xtics 4500
set xlabel 'Tamanho do vetor'
set ylabel 'Número de passos'
set xtic rotate by -90 scale 0
set yrange[0:3933]
plot './data/IL.dat' using 1:2 title 'Inserir no Início' lw 2 with lines, './data/IL.dat' using 1:3 title 'Inserir no Fim' lw 2 with lines, './data/IL.dat' using 1:4 title 'Inserir Aleatório' lw 2 with lines
