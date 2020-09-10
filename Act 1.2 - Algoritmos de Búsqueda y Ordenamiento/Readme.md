#**Actividad 1.2**

#Selection Sort

Análisis de complejidad temporal

El algoritmo consta de ciclos for anidados, en el primero recorre desde i=tamaño del arerglo, hasta 1 restando de uno en uno. En el segundo ciclo va de j=0 hasta i, sumando de 1 en uno por lo que su complejidad es de O(n^2).

#Bubble Sort

Análisis de complejidad temporal

El algoritmo consta de ciclos for anidados, en el primero recorre desde i=tamaño del arerglo, hasta 1 restando de uno en uno. En el segundo ciclo va de j=0 hasta i, sumando de 1 en uno por lo que su complejidad es de O(n^2).

#Merge Sort

Análisis de complejidad temporal

El algoritmo consta de tres funciones auxiliares que le permiten ir partiendo el arreglo a la mitad hasta quedar con un nivel de arreglos de tamaño 1, pues es más fácil comparar grupos pequeños que grandes, entonces compara el nivel de tamaño 1 y lo ordena, despues lo junta con los demás que fueron comparados y suben todos de nivel y así hasta juntar todos los arreglos partidos ya ordenados y crear uno combinado el cual estará ordenado. Su complejidad sería de O(n log(n)) porque lo va dividiendo en mitades (log(n)) y comparando y después los junta (merge) 

#Búsqueda Secuencial

Análisis de complejidad temporal

El algoritmo consta de un ciclo que recorre desde 0 hasta el tamaño del arreglo y compara la entrada con cada valor del arreglo, por lo que su complejidad es de O(n) para el peor de los casos.

#Búsqueda Binaria

Análisis de complejidad temporal

El algoritmo consta de un ciclo wwhile que tiene como condición que la posición de la izquierda sea menor que la última posición y si se cumple va partiendo el arreglo en 2, buscando de rama en rama hasta encontrar la entrada. Por lo que su complejidad es de log(n) para el peor de los casos
