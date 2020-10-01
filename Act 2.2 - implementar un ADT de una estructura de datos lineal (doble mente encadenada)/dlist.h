#ifndef DLIST_H_
#define DLIST_H_

#include <string>
#include <sstream>

using namespace std;

template <class T> class DList;

template <class T>
class DLink {
private:
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&);

	T value;
	DLink<T> *next;
    DLink<T> *previous;

	friend class DList<T>;
};

//constructores:
template <class T>
DLink<T>::DLink(T val) : value(val), next(0), previous(0) {}

template <class T>
DLink<T>::DLink(T val, DLink* nxt, DLink* prev) : value(val), next(nxt), previous(prev) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) : value(source.value), next(source.next), previous(source.previous) {}

//clase DList
template <class T>
class DList {
public:
	DList();
	DList(const DList<T>&);
	~DList();

    void addFirst(T);
	void add(T);
    T find(T) const;
    bool update(int, T);
	T removeFirst();
    T remove(int);

	bool empty() const;
	std::string toStringForward() const;
    std::string toStringBackward() const;
    void operator= (const DList&);

private:
	DLink<T> *head;
    DLink<T> *tail;
	int size;
};

//constructor
template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}
//destructor
template <class T>
DList<T>::~DList() {}

//////////////////////empty///////////////////////
template <class T>
bool DList<T>::empty() const {
	return (head == 0);
}

/////////////////////tostrings////////////////////////
template <class T>
std::string DList<T>::toStringForward() const {
    std::stringstream aux;
    DLink<T> *p;

    p = head;
    aux << "[";
    while (p != 0) {
        aux << p->value;
        if (p->next != 0) {
            aux << ", ";
        }
        p = p->next;
    }
    aux << "]";
    return aux.str();
}

template <class T>
std::string DList<T>::toStringBackward() const {
    std::stringstream aux;
    DLink<T> *p;

    p = tail;
    aux << "[";
    while (p != 0) {
        aux << p->value;
        if (p->previous != 0) {
            aux << ", ";
        }
        p = p->previous;
    }
    aux << "]";
    return aux.str();
}

/////////////////////////add//////////////////////////////////
template <class T>
void DList<T>::addFirst(T val) {
    DLink<T> *newLink;//declaras objeto
    newLink = new DLink<T>(val);//creas objeto
    if (empty()){
        head=newLink;
        tail=newLink;
    }
    else{
        newLink->next = head;//el sig de newlink es head pq se agrega antes
        head->previous = newLink;//el previous de head es newlink (redundante)
        head = newLink;
    }
    size++;
}

template <class T>
void DList<T>::add(T val) {
    DLink<T> *newLink;
    newLink = new DLink<T>(val);

    if (empty()) {
		head = newLink;
		tail = newLink;
	}
	else {
		tail->next = newLink;//el que sigue de la cola de la lista es el newlink, pq se agrega al final
		newLink->previous = tail;//el anterio de newlink es el que era el ultimo antes, o sea la ex tail
		tail = newLink;// la nueva tail va a ser newlink pq se agrega al final
	}
	size++;
}

//////////////////////Remove/////////////////////
template <class T>
T DList<T>::removeFirst() {
    T val;
    DLink<T> *p;

    if (empty()){
        return -1;
    }

    p=head;
    val=p->value; //le sacas el valor pq lo borras despues


    if (head == tail) {
		head = 0;
        tail = 0;
	}
    else{
        head=p->next;// el p->next va a ser el primero o el head
        p->next->previous = 0;//antes del primero no va a haber nada o sea null (0)
    }

    delete p;
    size--;

    return val;
}

template <class T>
T DList<T>::remove(int index) {
    int pos;
    T val;
    DLink<T> *p;

    if (empty()){
        return -1;
    }

    if (index == 0) {
		return removeFirst();
	}

    p=head;
    pos=0;
    while (index != pos){
        p=p->next;
        pos++;
    }
    val=p->value;
    p->previous->next = p->next; //el que sigue de p previous es p next

    if (p->next != 0) { //si el que sigue no es un null,
		p->next->previous = p->previous;  //va a apuntar el siguiente de p hacia el anterior de p
	}

	size--;

	delete p;
	return val;
}

///////////////////////Update/////////////////////
template <class T>
bool DList<T>::update(int index, T val) {
	DLink<T> *p;
	DLink<T> *q;
	int pos;

	if (index<0 || index>=size){
        return -1;
    }
	p=head;
	pos=0;
	while (pos != index){
		p=p->next;
		pos++;
	}
	p->value = val;
	return true;
}

//////////////////////FInd/////////////////////////////
template <class T>
T DList<T>::find(T val) const{
	DLink<T> *p;

	p=head;
	T index = 0;
	while (p != 0){
		if (p->value == val){
			return index;
		}
		p=p->next;
		index++;
	}
	return -1;
}



#endif
