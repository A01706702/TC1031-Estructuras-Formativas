#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

template <class T>
class Heap {
private:
	T *data; //dato de tipo Template
	unsigned int tam;
	unsigned int count;
	unsigned int parent(unsigned int) const;
	unsigned int left(unsigned int) const;
	unsigned int right(unsigned int) const;
	void heapify(unsigned int);
	void swap(unsigned int, unsigned int);
public:
	Heap(unsigned int);
	~Heap();
    void push(T);
	void pop();
    T top();
    bool empty() const;
	void clear();
	string toString() const;
    int size() const;
};

///////////////constructor///////////////
template <class T>
Heap<T>::Heap(unsigned int sze){
	tam = sze;
	data = new T[tam];
	count = 0;
}

///////////destructor/////////////////
template <class T>
Heap<T>::~Heap() {
	delete [] data; data = 0;
	tam = 0; count = 0;
}

////////////////////parent/////////////////////
template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const {
	return (pos - 1) / 2;
}

////////////////////////left////////////////////////
template <class T>
unsigned int Heap<T>::left(unsigned int pos) const {
	return ((2 * pos) + 1);
}

////////////////////////right/////////////////
template <class T>
unsigned int Heap<T>::right(unsigned int pos) const {
	return ((2 * pos) + 2);
}

//////////////////////////swap///////////////////
template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

////////////////////////heapify////////////////
template <class T>
void Heap<T>::heapify(unsigned int pos) {
	unsigned int le = left(pos);
	unsigned int ri = right(pos);
	unsigned int min = pos;
	if (le <= count && data[le] < data[min]) {
		min = le;
	}
	if (ri <= count && data[ri] < data[min]) {
		min = ri;
	}
	if (min != pos) {
		swap(pos, min);
		heapify(min);
	}
}

//////////////////////push///////////////////////
template <class T>
void Heap<T>::push(T val){
	unsigned int pos;

	pos = count;
	count++;
	while (pos > 0 && val < data[parent(pos)]) {
		data[pos] = data[parent(pos)];
		pos = parent(pos);
	}
	data[pos] = val;
}

///////////////////////pop////////////////////////
template <class T>
void Heap<T>::pop(){
	T aux = data[0];

	data[0] = data[--count];
	heapify(0);
}
template <class T>
void Heap<T>::clear() {
	count = 0;
}

////////////////////top///////////////////
template <class T>
T Heap<T>::top(){
    T aux = data[0];
    return aux;
}

////////////////////size//////////////////
template <class T>
int Heap<T>::size() const {
	return (count);
}

///////////////////////empty///////////////////
template <class T>
bool Heap<T>::empty() const {
	return (count == 0);
}

///////////////////tostring/////////////////////////
template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;
	aux << "[";	for (unsigned int i = 0; i < count; i++) {
		if (i != 0) {
			aux << " ";
		} aux << data[i];
	} aux << "]";
	return aux.str();
}

#endif
