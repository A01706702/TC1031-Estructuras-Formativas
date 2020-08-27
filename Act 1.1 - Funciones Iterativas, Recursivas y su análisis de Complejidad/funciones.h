
#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
using namespace std;

class Funciones{
public:
    Funciones(){}
    long sumaIterativa (int n);
    long sumaRecursiva (int m);
    long sumaDirecta (int p);
};
long Funciones::sumaIterativa (int n){
    long aux=0;
    for (int i=1; i<=n; i++){
        aux+=i;
    }
    return aux;
}

long Funciones::sumaRecursiva (int n){
    if (n==1){
        return 1;
    }
    if (n<1){
        return 0;

    }
    else{
        return n+sumaRecursiva(n-1);
    }
}
long Funciones::sumaDirecta (int n){
    return ((n+1)*n)/2;
}

#endif
