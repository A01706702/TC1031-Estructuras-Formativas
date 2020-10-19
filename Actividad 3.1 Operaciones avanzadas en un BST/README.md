Implementar las Funciones avanzadas de un BST

#Visit

Análisis de complejidad temporal

La función manda a llamar a todas laz formas de ordenar el arbo, separando las formas de ordenación con un salto de linea que contiene la variable aux. Los algoritmos inorder, preorder, post order y levelorder comparan entradas mediante condicionales, a excepcion del último que cuenta con un ciclo for que va desde 0 hasta height recorriendo de uno en uno, por lo que la complejidad es de O(n) para el peor de los casos

#Height

Análisis de complejidad temporal

La función compara cada nodo con su respectivo left y right y dependiendo la condición que se cumpla será lo que correrá. Va haciendo comparaciones con condicionales y recursión por lo que la complejidad es de O(n) para el peor de los casos

#Ancestors

Análisis de complejidad temporal

La funcion recibe un valor y un stringstream auxiliar. Va comparando condiciones que devuelven valores true o false, pero cambia los valores de las variables y va comparando con ifs por lo que la complejidad es de O(n) para el peor de los casos

#Whatlevelami

Análisis de complejidad temporal

Recibe un valor para el que se quiera saber el nivel en el arbol, consta de un condicional y de recursion que se guarda en la variable num. Va recorriendo el arbol nodo por nodo por lo que la complejidad es de O(n) para el peor de los casos.
