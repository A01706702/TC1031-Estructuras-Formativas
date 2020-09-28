#Actividad 2.1

Implementar las operaciones CRUD para un ADT de estructura de datos 

#Add

Análisis de complejidad temporal

El algoritmo consta de un ciclo que recorre una lista mediante apuntadores, si la lista está vacía, manda a llamar addfirst, el cual, agrega un objeto con un vlaor al principio. Su complejidad es de O(n) porque recorre la lista de manera lineal y solo una vez, de uno en uno. 

#find

Análisis de complejidad temporal

El algoritmo recorre una lista siempre y cuando no esté vacía, compara el valor de cada elemento con el introducido por el usuario y devuelve el índice, sin no se encuentra devuelve -1. Su complejidad es de O(n) porque recorre cada elemento uno por uno con un apuntadores.

#Update

Análisis de complejidad temporal

El algoritmo consta de un ciclo que va comparando una entrada index con un contador, y recorriendo la posicion en la lista mediante apuntadores, al encontrar el índice correcto, se sale del ciclo y reemplaza el valor que tiene esa posición por la entrada val. Su complejidad es de O(n) porque va comparando uno con uno, cada posición de la lista con la entrada.

#Remove

Análisis de complejidad temporal

Consta de un ciclo que recorre la lista hasta encontrar el índice de entrada mediante apuntadores auxiliares, después le saca el valor, se cambian los apuntadores y se borra el apuntador que quedó apuntando en ese índice. Es de O(n) porque va recorriendo la lista de 1 en 1 comparando la entrada con un contador.
