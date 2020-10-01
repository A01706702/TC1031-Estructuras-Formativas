#Actividad 2.1

Implementar las operaciones CRUD para un ADT de estructura de datos doblemente ligada

#Add

Análisis de complejidad temporal

El algoritmo compara entradas con los head y tail de la lista, si la lista está vacía, el elemento a agregar será head y tail al mismo tiempo. Su complejidad es de O(n) porque no necesita recorrer la lista, solamente cambia el tail hacia newlist porque se agregará al final.

#find

Análisis de complejidad temporal

El algoritmo recorre una lista siempre y cuando no esté vacía, compara el valor de cada elemento con el introducido por el usuario y devuelve el índice, sin no se encuentra devuelve -1. Su complejidad es de O(n) porque recorre cada elemento uno por uno con un apuntadores.

#Update

Análisis de complejidad temporal

El algoritmo consta de un ciclo que va comparando una entrada index con un contador, y recorriendo la posicion en la lista mediante apuntadores, al encontrar el índice correcto, se sale del ciclo y reemplaza el valor que tiene esa posición por la entrada val. Su complejidad es de O(n) porque va comparando uno con uno, cada posición de la lista con la entrada.

#Remove

Análisis de complejidad temporal

Consta de un ciclo que recorre la lista hasta encontrar el índice de entrada mediante apuntadores auxiliares, después le saca el valor, se cambian los apuntadores diciendo que el next de p->previous será p->next, pues se borrará p y se borrará el objeto al que está apuntando (el que se encuentra entre el siguiente de p->previous y p->next) en ese índice. Si el indice a buscar es el 0, se manda a llamar removeFirst, que sisplemente apunta head y tail a null si se cumple que solo hay un elemento, si no, apuntará head hacia el siguiente del primero y declara que el anterior de p->next apuntará a null, porque ya no habrá un elemento antes, finalmente se borra p y se decrementa el tamaño de la lista en 1. Es de O(n) porque va recorriendo la lista de 1 en 1 comparando la entrada con un contador.
