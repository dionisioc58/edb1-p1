#ifndef VETORES_H
#define VETORES_H

#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

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
	long int menor, troca;
	int contagem = 1;
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

int insertionSort(long int *V, long int N) {
	int contagem = 1;
	for (int ii = 0; ii < N; ii++){
	// seleciona elemento dentre os não ordenados
		contagem++;
		long int elemento = V[ii];
		contagem++;
		// insere elemento na lista dos ordenados
		long int pInsercao = ii;
		contagem++;
		while(pInsercao > 0 && V[pInsercao - 1] > elemento){
			contagem++;
			V[pInsercao] = V[pInsercao - 1];
			contagem++;
			pInsercao--;
			contagem++;
		}
		V[pInsercao] = elemento;
		contagem++;
	}
	
	return contagem;
}

int quickSort(long int arr[], int left, int right) {
    int i = left, j = right, contagem = 1;
    int tmp;
	contagem++;
    int pivot = arr[(left + right) / 2];
	contagem++;
    while (i <= j) {
		contagem++;
        while (arr[i] < pivot) {
            i++;
			contagem++;
		}
        while (arr[j] > pivot) {
            j--;
			contagem++;
		}
        if (i <= j) {
			contagem++;
          	tmp = arr[i];
			contagem++;
            arr[i] = arr[j];
			contagem++;
            arr[j] = tmp;
			contagem++;
            i++;
			contagem++;
            j--;
			contagem++;
        }
    }
  	if (left < j)
        contagem += quickSort(arr, left, j);
    if (i < right)
        contagem += quickSort(arr, i, right);
	return contagem;
}

int merge(long int arr[], int l, int m, int r){
    int i, j, k, contagem = 1;
    int n1 = m - l + 1;
	contagem++;
    int n2 =  r - m;
	contagem++;
 
    /* create temp arrays */
    int L[n1], R[n2];
	contagem++;
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
		contagem++;
	}
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1+ j];
		contagem++;
	}
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
	contagem++;
    j = 0; // Initial index of second subarray
	contagem++;
    k = l; // Initial index of merged subarray
	contagem++;
    while (i < n1 && j < n2) {
		contagem++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
			contagem++;
            i++;
			contagem++;
        } else {
            arr[k] = R[j];
			contagem++;
            j++;
			contagem++;
        }
        k++;
		contagem++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
		contagem++;
        arr[k] = L[i];
		contagem++;
        i++;
		contagem++;
        k++;
		contagem++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
		contagem++;
        arr[k] = R[j];
		contagem++;
        j++;
		contagem++;
        k++;
		contagem++;
    }
	return contagem;
}

int mergeSort(long int arr[], int l, int r) {
	int contagem = 1;
    if (l < r) {
        contagem++;
        int m = l+(r-l)/2;
		contagem++;
 
        contagem += mergeSort(arr, l, m);
        contagem += mergeSort(arr, m+1, r);
 
        contagem += merge(arr, l, m, r);
    }
	return contagem;
}

#endif