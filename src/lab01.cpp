#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

long int passo = 1000;

long int linear_search(long int A[], long int size, long int k){

	long int i;
	int contagem = 1;

	for(i = 0; i < size; i++){
		contagem++;
		if(A[i] == k){
			contagem++;
			return contagem;
		}
	}
	contagem++;
	return contagem;

}
long int linear_search_recursive(long int A[], long int size, long int k){

	long int n = size;
	int contagem = 1;

	if(n < 0){
		contagem++;
		return contagem;
	}
	contagem++;
	if(A[n] == k){
		contagem++;
		return contagem;
	}else{
		contagem++;
		return contagem + linear_search_recursive(A, n-1, k);
	}

}

long int binary_search(long int A[], long int first, long int end, long int k){

	long int middle;
	int contagem = 1;

	while(first <= end){
		contagem++;
		middle = (first + end)/2;
		contagem++;
		if(A[middle] == k) {
			contagem++;
			return contagem;
		}
		contagem++;
		if(A[middle] < k) {
			contagem++;
			first = middle + 1;
		} else {
			end = middle - 1;
			contagem++;
		}
	}
	contagem++;
	return contagem;

}

long int binary_search_recursive(long int A[], long int first, long int end, long int k){

	long int middle = (first + end)/2;
	int contagem = 1;

	if(A[middle] == k){
		contagem++;
		return contagem;
	}
	contagem++;
	if(first >= end){
		contagem++;
		return contagem;
	} 
	contagem++;
	if(A[middle] < k){
		contagem++;
		return contagem + binary_search_recursive(A, middle+1, end, k);
	} else {
		contagem++;
		return contagem + binary_search_recursive(A, first, middle-1, k);
	}

}

int selectionSort(long int *V, long int N) {
	int menor, troca, contagem = 1;
	for(int i = 0; i < (N - 1); i++) {
		contagem++;
		menor = i;
		contagem++;
		for(int j = (i + 1); j < N; j++) {
			contagem++;
			if(V[j] < V[menor]) {
				menor = j;
				contagem++;
			}
		}
		contagem++;
		if(i != menor) {
			contagem++;
			troca = V[i];
			contagem++;
			V[i] = V[menor];
			contagem++;
			V[menor] = troca;
			contagem++;
		}
	}
	return contagem;
}

void quickSort(long int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
          	tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
  	if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

bool gerarGnuSet(string nome, string titulo, int min_x, int max_x, int max_y) {
	ofstream saida("./gnuplot/" + nome + ".gnuplot");
	if(!saida) return false;

	saida << "reset" << endl;
	saida << "set key on" << endl;
	saida << "set terminal png size 1280,960 enhanced font 'Helvetica,12'" << endl;
	saida << "set output './images/" + nome + ".png'" << endl;
	saida << "set title '" + titulo + "'" << endl;
	saida << "set grid" << endl;
	saida << "set xrange[";
	saida << min_x;
	saida << ":";
	saida << max_x;
	saida << "]" << endl;
	saida << "set xtics ";
	saida << (int)((max_x-min_x)/20);
	saida << endl;
	saida << "set xlabel 'Tamanho do vetor'" << endl;
	saida << "set ylabel 'Número de passos'" << endl;
	saida << "set xtic rotate by -90 scale 0" << endl;
	saida << "set yrange[0:";
	saida << (max_y+10);
	saida << "]" << endl;
	saida << "plot './data/" + nome + ".dat' using 1:2 title 'Melhor Caso' lw 2 with lines, ";
	saida <<      "'./data/" + nome + ".dat' using 1:3 title 'Médio Caso' lw 2 with lines, ";
	saida <<      "'./data/" + nome + ".dat' using 1:4 title 'Pior Caso' lw 2 with lines" << endl;
	saida.close();

	//Executar o gnuplot e gerar o arquivo de imagem
	string comando = "gnuplot -e '' ./gnuplot/" + nome + ".gnuplot";
	system(comando.c_str());

	return true;
}

int main(){

	//Variáveis
	long int i, melhorCaso, medioCaso, piorCaso, size, r1 = 0, r2 = 0, r3 = 0, maximo, opcao, inicial;
	long int max = 0;//Para o máximo de y no gnuplot
	ofstream saida;
	double mBSI1 = 0, mBSI2 = 0, mBSI3 = 0, mBSR1 = 0, mBSR2 = 0, mBSR3 = 0, mBBI1 = 0, mBBI2 = 0, mBBI3 = 0, mBBR1 = 0, mBBR2 = 0, mBBR3 = 0;
	double mSSI1 = 0, mSSI2 = 0, mSSI3 = 0;
	
	srand((unsigned)time(0));

	std::cout << "Entre com o método que deseja aplicar: " << std::endl;
	std::cout << "(1) Busca sequencial iterativa;" << std::endl;
	std::cout << "(2) Busca sequencial recursiva;" << std::endl;
	std::cout << "(3) Busca binária iterativa." << std::endl;
	std::cout << "(4) Busca binária recursiva." << std::endl;
	std::cout << "(5) Selection Sort Iterativa." << std::endl;

	std::cin >> opcao;

	long int *A = new long int[1];

	switch(opcao) {
		case 1:
		
		std::cout << "# Arquivo Gnuplot para busca sequencial iterativa" << std::endl;
		std::cout << "# N Melhor Caso Caso Médio Pior Caso It1 It2 It3" << std::endl;
		saida.open("./data/BSI.dat");

		//Inicializando tamanhos
		inicial =  10000; 
		size    = inicial;
		maximo  = 200000;
		passo   =  3000;

		while(size <= maximo){
			delete[] A;
			
			A = new long int[size];

			//Preenchendo o Array A
			for(i = 0; i < size; i++){
				A[i] = i+1;
			}

			//Verificando a média (100 repetições)
			for(i = 0; i < 100; i++){

				melhorCaso = 1;
				medioCaso = rand()%(size + size/2);
				piorCaso = size + 1;

				//Busca Sequencial Iterativa (melhorCaso)
				auto sBSI1 = std::chrono::steady_clock::now();
				//========================================================================================
				r1 += linear_search(A, size, melhorCaso);
				//========================================================================================
				auto eBSI1 = std::chrono::steady_clock::now();
				auto dBSI1 = eBSI1 - sBSI1;
				mBSI1 = mBSI1 + std::chrono::duration <double, std::milli> (dBSI1).count();

				//Busca Sequencial Iterativa (medioCaso)
				auto sBSI2 = std::chrono::steady_clock::now();
				//========================================================================================
				r2 += linear_search(A, size, medioCaso);
				//========================================================================================
				auto eBSI2 = std::chrono::steady_clock::now();
				auto dBSI2 = eBSI2 - sBSI2;
				mBSI2 = mBSI2 + std::chrono::duration <double, std::milli> (dBSI2).count();

				//Busca Sequencial Iterativa (piorCaso)
				auto sBSI3 = std::chrono::steady_clock::now();
				//========================================================================================
				r3 += linear_search(A, size, piorCaso);
				//========================================================================================
				auto eBSI3 = std::chrono::steady_clock::now();
				auto dBSI3 = eBSI3 - sBSI3;
				mBSI3 = mBSI3 + std::chrono::duration <double, std::milli> (dBSI3).count();

			}

				//Médias
			mBSI1 = mBSI1/100;
			mBSI2 = mBSI2/100;
			mBSI3 = mBSI3/100;
			r1   /= 100;
			r2   /= 100;
			r3   /= 100;
			if(r1 > max) max = r1;
			if(r2 > max) max = r2;
			if(r3 > max) max = r3; 

			std::cout.precision(4);
			std::cout << size << " " << mBSI1 << " " << mBSI2 << " " << mBSI3 << " " << r1 << " " << r2 << " " << r3 << std::endl;
			saida << size << " " << r1 << " " << r2 << " " << r3 << endl;
			r1 = 0;
			r2 = 0;
			r3 = 0;
			//Aumentando a amostra em Progressão Aritimética
			size = size + passo;

		}
		//Gerar o arquivo relatorio.gnuplot
		gerarGnuSet("BSI","Busca Sequencial Iterativa", inicial, maximo, max);
		break;

		case 2:

		std::cout << "# Arquivo Gnuplot para busca sequencial recursiva" << std::endl;
		std::cout << "# N Melhor Caso Caso Médio Pior Caso" << std::endl;
		saida.open("./data/BSR.dat");

		//Inicializando tamanhos
		inicial =  10000; 
		size    = inicial;
		maximo  = 100000;
		passo   =   8000;
		
		while(size <= maximo){
			delete[] A;
			A = new long int[size];

			//Preenchendo o Array A
			for(i = 0; i < size; i++){
				A[i] = i+1;
			}

				//Verificando a média (100 repetições)
			for(i = 0; i < 100; i++){

				melhorCaso = A[size-1];
				medioCaso = rand()%(size);
				piorCaso = size + 1;

				//Busca Sequencial Recursiva (melhorCaso)
				auto sBSR1 = std::chrono::steady_clock::now();
				//========================================================================================
				r1 += linear_search_recursive(A, size, melhorCaso);
				//========================================================================================
				auto eBSR1 = std::chrono::steady_clock::now();
				auto dBSR1 = eBSR1 - sBSR1;
				mBSR1 = mBSR1 + std::chrono::duration <double, std::milli> (dBSR1).count();

				//Busca Sequencial Recursiva (medioCaso)
				auto sBSR2 = std::chrono::steady_clock::now();
				//========================================================================================
				r2 += linear_search_recursive(A, size, medioCaso);
				//========================================================================================
				auto eBSR2 = std::chrono::steady_clock::now();
				auto dBSR2 = eBSR2 - sBSR2;
				mBSR2 = mBSR2 + std::chrono::duration <double, std::milli> (dBSR2).count();

				//Busca Sequencial Recursiva (piorCaso)
				auto sBSR3 = std::chrono::steady_clock::now();
				//========================================================================================
				r3 += linear_search_recursive(A, size, piorCaso);
				//========================================================================================
				auto eBSR3 = std::chrono::steady_clock::now();
				auto dBSR3 = eBSR3 - sBSR3;
				mBSR3 = mBSR3 + std::chrono::duration <double, std::milli> (dBSR3).count();

				}

			//Médias
			mBSR1 = mBSR1/100;
			mBSR2 = mBSR2/100;
			mBSR3 = mBSR3/100;
			r1   /= 100;
			r2   /= 100;
			r3   /= 100;
			if(r1 > max) max = r1;
			if(r2 > max) max = r2;
			if(r3 > max) max = r3; 

			std::cout.precision(4);
			std::cout << size << " " << mBSR1 << " " << mBSR2 << " " << mBSR3 << " " << r1 << " " << r2 << " " << r3 << std::endl;
			saida << size << " " << r1 << " " << r2 << " " << r3 << endl;
			r1 = 0;
			r2 = 0;
			r3 = 0;

			//Aumentando a amostra em Progressão Aritimética
			size = size + passo;

		}
		//Gerar o arquivo relatorio.gnuplot
		gerarGnuSet("BSR", "Busca Sequencial Recursiva", inicial, maximo, max);
		break;

		case 3:
		
		std::cout << "# Arquivo Gnuplot para busca binária iterativa" << std::endl;
		std::cout << "# N Melhor Caso Caso Médio Pior Caso It1 It2 It3" << std::endl;
		saida.open("./data/BBI.dat");
		
		//Inicializando tamanhos
		inicial =   10000; 
		size    = inicial;
		maximo  = 1100000;
		passo   =   50000;
		
		while(size <= maximo){
			delete[] A;
			A = new long int[size];

			//Preenchendo o Array A aleatório
			for(i = 0; i < size; i++){
				A[i] = rand()%(4*size);
			}
			// Ordenando o Array A aleatório
			quickSort(A, 0, size);

			//Verificando a média (100 repetições)
			for(i = 0; i < 100; i++){

				melhorCaso = A[size/2];
				medioCaso = A[(rand()%(size-1))];
				piorCaso = -1;

				//Busca Binária Iterativa (melhorCaso)
				auto sBBI1 = std::chrono::steady_clock::now();
				//========================================================================================
				r1 += binary_search(A, 0, size, melhorCaso);
				//========================================================================================
				auto eBBI1 = std::chrono::steady_clock::now();
				auto dBBI1 = eBBI1 - sBBI1;
				mBBI1 = mBBI1 + std::chrono::duration <double, std::milli> (dBBI1).count();

				//Busca Binária Iterativa (medioCaso)
				auto sBBI2 = std::chrono::steady_clock::now();
				//========================================================================================
				r2 += binary_search(A, 0, size, medioCaso);
				//========================================================================================
				auto eBBI2 = std::chrono::steady_clock::now();
				auto dBBI2 = eBBI2 - sBBI2;
				mBBI2 = mBBI2 + std::chrono::duration <double, std::milli> (dBBI2).count();

				//Busca Binária Iterativa (piorCaso)
				auto sBBI3 = std::chrono::steady_clock::now();
				//========================================================================================
				r3 += binary_search(A, 0, size, piorCaso);
				//========================================================================================
				auto eBBI3 = std::chrono::steady_clock::now();
				auto dBBI3 = eBBI3 - sBBI3;
				mBBI3 = mBBI3 + std::chrono::duration <double, std::milli> (dBBI3).count();

			}
			//Médias
			mBBI1 = mBBI1/100;
			mBBI2 = mBBI2/100;
			mBBI3 = mBBI3/100;
			r1   /= 100;
			r2   /= 100;
			r3   /= 100;
			if(r1 > max) max = r1;
			if(r2 > max) max = r2;
			if(r3 > max) max = r3; 

			std::cout.precision(4);
			std::cout << size << " " << mBBI1 << " " << mBBI2 << " " << mBBI3 << " " << r1 << " " << r2 << " " << r3 << std::endl;
			saida << size << " " << r1 << " " << r2 << " " << r3 << endl;
			r1 = 0;
			r2 = 0;
			r3 = 0;

			//Aumentando a amostra em Progressão Aritimética
			size = size + passo;

		}
		//Gerar o arquivo relatorio.gnuplot
		gerarGnuSet("BBI", "Busca Binária Iterativa", inicial, maximo, max);
		break;
		
		case 4:
		
		std::cout << "# Arquivo Gnuplot para busca binário recursiva" << std::endl;
		std::cout << "# N Melhor Caso Caso Médio Pior Caso" << std::endl;
		saida.open("./data/BBR.dat");

		//Inicializando tamanhos
		inicial =   10000; 
		size    = inicial;
		maximo  = 1100000;
		passo   =   50000;
		
		while(size <= maximo){
			delete[] A;
			A = new long int[size];

			//Preenchendo o Array A aleatório
			for(i = 0; i < size; i++){
				A[i] = rand()%(4*size);
			}
			// Ordenando o Array A aleatório
			quickSort(A, 0, size);

			//Verificando a média (100 repetições)
			for(i = 0; i < 100; i++){

				melhorCaso = A[size/2];
				medioCaso = A[(rand()%(size-1))];
				piorCaso = A[size-1] + 10;

				//Busca Binária Recursiva (melhorCaso)
				auto sBBR1 = std::chrono::steady_clock::now();
				//========================================================================================
				r1 += binary_search_recursive(A, 0, size, melhorCaso);
				//========================================================================================
				auto eBBR1 = std::chrono::steady_clock::now();
				auto dBBR1 = eBBR1 - sBBR1;
				mBBR1 = mBBR1 + std::chrono::duration <double, std::milli> (dBBR1).count();

				//Busca Binária Recursiva (medioCaso)
				auto sBBR2 = std::chrono::steady_clock::now();
				//========================================================================================
				r2 += binary_search_recursive(A, 0, size, medioCaso);
				//========================================================================================
				auto eBBR2 = std::chrono::steady_clock::now();
				auto dBBR2 = eBBR2 - sBBR2;
				mBBR2 = mBBR2 + std::chrono::duration <double, std::milli> (dBBR2).count();

				//Busca Binária Recursiva (piorCaso)
				auto sBBR3 = std::chrono::steady_clock::now();
				//========================================================================================
				r3 += binary_search_recursive(A, 0, size, piorCaso);
				//========================================================================================
				auto eBBR3 = std::chrono::steady_clock::now();
				auto dBBR3 = eBBR3 - sBBR3;
				mBBR3 = mBBR3 + std::chrono::duration <double, std::milli> (dBBR3).count();

			}

			//Médias
			mBBR1 = mBBR1/100;
			mBBR2 = mBBR2/100;
			mBBR3 = mBBR3/100;
			r1   /= 100;
			r2   /= 100;
			r3   /= 100;
			if(r1 > max) max = r1;
			if(r2 > max) max = r2;
			if(r3 > max) max = r3; 

			std::cout.precision(4);
			std::cout << size << " " << mBBR1 << " " << mBBR2 << " " << mBBR3 << " " << r1 << " " << r2 << " " << r3 << std::endl;
			saida << size << " " << r1 << " " << r2 << " " << r3 << endl;
			r1 = 0;
			r2 = 0;
			r3 = 0;

			//Aumentando a amostra em Progressão Aritimética
			size = size + passo;

		}
		//Gerar o arquivo relatorio.gnuplot
		gerarGnuSet("BBR", "Busca Binária Recursiva", inicial, maximo, max);
		break;

		case 5:
		
		std::cout << "# Arquivo Gnuplot para selectionSort iterativo" << std::endl;
		std::cout << "# N Melhor Caso Caso Médio Pior Caso" << std::endl;
		saida.open("./data/SSI.dat");

		//Inicializando tamanhos
		inicial =   1000; 
		size    = inicial;
		maximo  =   10000;
		passo   =    1000;

		while(size <= maximo){
			delete[] A;
			A = new long int[size];

			//Verificando a média (100 repetições)
			for(i = 0; i < 100; i++){

				//Selection Sort Iterativo (melhorCaso)
				
				//Preenchendo o Array A ordenado
				for(i = 0; i < size; i++){
					A[i] = i;
				}
				auto sSSI1 = std::chrono::steady_clock::now();
				//========================================================================================
				r1 += selectionSort(A, size);
				//========================================================================================
				auto eSSI1 = std::chrono::steady_clock::now();
				auto dSSI1 = eSSI1 - sSSI1;
				mSSI1 = mSSI1 + std::chrono::duration <double, std::milli> (dSSI1).count();

				//Selection Sort Iterativo (médioCaso)
				
				//Preenchendo o Array A pela metade
				for(i = 0; i < size; i++){
					if(i < (size / 2))
						A[i] = i;
					else
						A[i] = rand()%size;
				}
				auto sSSI2 = std::chrono::steady_clock::now();
				//========================================================================================
				r2 += selectionSort(A, size);
				//========================================================================================
				auto eSSI2 = std::chrono::steady_clock::now();
				auto dSSI2 = eSSI2 - sSSI2;
				mSSI2 = mSSI2 + std::chrono::duration <double, std::milli> (dSSI2).count();


				//Selection Sort Iterativo (piorCaso)
				
				//Preenchendo o Array A desordenado
				for(i = 0; i < size; i++){
					A[i] = rand()%size;
				}
				auto sSSI3 = std::chrono::steady_clock::now();
				//========================================================================================
				r3 += selectionSort(A, size);
				//========================================================================================
				auto eSSI3 = std::chrono::steady_clock::now();
				auto dSSI3 = eSSI3 - sSSI3;
				mSSI3 = mSSI3 + std::chrono::duration <double, std::milli> (dSSI3).count();

			}

			//Médias
			mSSI1 = mSSI1/100;
			mSSI2 = mSSI2/100;
			mSSI3 = mSSI3/100;
			r1   /= 100;
			r2   /= 100;
			r3   /= 100;
			if(r1 > max) max = r1;
			if(r2 > max) max = r2;
			if(r3 > max) max = r3; 

			std::cout.precision(4);
			std::cout << size << " " << mSSI1 << " " << mSSI2 << " " << mSSI3 << " " << r1 << " " << r2 << " " << r3 << std::endl;
			saida << size << " " << r1 << " " << r2 << " " << r3 << endl;
			r1 = 0;
			r2 = 0;
			r3 = 0;

			//Aumentando a amostra em Progressão Aritimética
			size = size + passo;

		}
		//Gerar o arquivo relatorio.gnuplot
		gerarGnuSet("SSI", "Selection Sort Iterativa", inicial, maximo, max);
		break;

		default:
			std::cout << "Entrada inválida" << std::endl;
	}
	
	if((opcao > 0) && (opcao < 5)) {
		delete[] A;
		saida.close();
	}

	return 0;
}
