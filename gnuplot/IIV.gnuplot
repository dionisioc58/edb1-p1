reset
set key on
set terminal png size 1280,960 enhanced font 'Helvetica,12'
set output './images/IIV.png'
set title 'Inserir no Início - Vetor'
set grid
set xrange[10000:100000]
set xtics 4500
set xlabel 'Tamanho do vetor'
set ylabel 'Número de passos'
set xtic rotate by -90 scale 0
set yrange[0:100011]
plot './data/IIV.dat' using 1:2 title '' lw 2 with lines, 