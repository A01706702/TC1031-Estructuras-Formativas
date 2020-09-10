#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <list>

using namespace std;

template <class T>
class Sorts{
private:
    void swap(vector<T>&, int, int);
	void copyArray(vector<T>&, vector<T>&, int, int);
	void mergeArray(vector<T>&, vector<T>&, int, int, int);
	void mergeSplit(vector<T>&, vector<T>&, int, int);
    int bs_aux(vector<T>&, int, int, int);
public:
    vector<T> ordenaSeleccion(vector<T>&);
    vector<T> ordenaBurbuja(vector<T>&);
    vector<T> ordenaMerge(vector<T>&);
    int busqSecuencial(vector<T>&, int);
    int busqBinaria(vector<T>&, int);//devuelve la posicion en la que deberia estar si no se encuentra el numero

};
//swap
template <class T>
void Sorts<T>::swap(vector<T> &prueba, int i, int j) {
	T aux = prueba[i];
	prueba[i] = prueba[j];
	prueba[j] = aux;
}
//copyarray aux1
template <class T>
void Sorts<T>::copyArray(vector<T> &A, vector<T> &B, int low, int high) {

	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}
//mergearray aux2
template <class T>
void Sorts<T>::mergeArray(vector<T> &A, vector<T> &B, int low, int mid, int high) {
	int i, j, k;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid &&j <= high) {
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++) {
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) {
			B[k++] = A[i];
		}
	}
}
//mergesplit aux3
template <class T>
void Sorts<T>::mergeSplit(vector<T> &A, vector<T> &B, int low, int high) {
	int mid;

	if ( (high - low) < 1 ) {
		return;
	}
	mid = (high + low) / 2;
	mergeSplit(A, B, low, mid);
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);
	copyArray(A, B, low, high);
}

//ordenaBurbuja
template <class T>
vector<T> Sorts<T>::ordenaBurbuja(vector<T> &prueba) {
	for (int i = prueba.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (prueba[j] > prueba[j + 1]) {
				swap(prueba, j, j + 1);
			}
		}
	}
	return prueba;
}

//ordenaSeleccion
template <class T>
vector<T> Sorts<T>::ordenaSeleccion(vector<T> &prueba) {
	int pos;

	for (int i = prueba.size() - 1; i > 0; i--) {
		pos = 0;
		for (int j = 1; j <= i; j++) {
			if (prueba[j] > prueba[pos]) {
				pos = j;
			}
		}

		if (pos != i) {
			swap(prueba, i, pos);
		}
	}
	return prueba;
}

//ordenaMerge
template <class T>
vector<T> Sorts<T>::ordenaMerge(vector<T> &prueba) {
	vector<T> tmp(prueba.size());
	mergeSplit(prueba, tmp, 0, prueba.size() - 1);
	return prueba;
}

template <class T>
int Sorts<T>::busqSecuencial(vector<T>&prueba, int val) {
    	for (int i = 0; i < prueba.size(); i++) {
    		if (val == prueba[i]) {
    			return i; //regresa posicion
    		}
    	}
    	return -1; //no existe el numero a buscar en el arreglo
    }
//busqBinaria RECURSIVA
/*
template <class T>
int Sorts<T>::bs_aux(vector<T>&prueba, int low, int high, int val) {

    int mid;
	if (low <= high) {
		mid = (high + low) / 2;
		if (val == prueba[mid]) {
			return mid;
		} else if (val < prueba[mid]) {
			return bs_aux(prueba, low, mid - 1, val);
		} else if (val > prueba[mid]) {
			return bs_aux(prueba, mid + 1, high, val);
		}
	}
	return low;
}

template <class T>
int Sorts<T>::busqBinaria(vector<T>&prueba,  int val) {
    int size=prueba.size();
	return bs_aux(prueba, 0, size - 1, val);
}
*/
//busquedabinaria SECUENCIAL
template <class T>
int Sorts<T>::busqBinaria(vector<T>&prueba, int val) {
	int mid;
	int low = 0;
	int high = (prueba.size()) - 1;

	while (low < high) {
		mid = (high + low) / 2;
		if (val == prueba[mid]) {
			return mid;
		} else if (val < prueba[mid]) {
			high = mid - 1;
		} else if (val > prueba[mid]) {
			low = mid + 1;
		}
	}
	return low;
}
#endif
