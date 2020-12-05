# README

La estrucuta utilizada para esta actividad integradora fue Ternary Search Tree o TST.

Esta es un tipo de estructura especial de tipo Trie, en donde los child nodes de un trie

estándar se ordenan primero. 

A diferencia de una estrucuta de datos trie en donde cada nodo tiene apuntadores 

para sus hiijps, aquí cada nodo de un TST contiene solo tres apuntadores:

1.El puntero izquierdo (izq) apunta al nodo cuyo valor es inferior al valor del 

nodo actual

2.El puntero igual (ig) apunta al nodo cuyo valor es igual al nodo actual

3.El puntero derecho (der) apunta al nodo cuyo valor es mayor que el valor

en el nodo actual.

Cada nodo tiene un campo para indicar datos.

Es similar al BST pero en este caso los tados se distibuyen en nodos, con la 

ventaja de que guarda más espacios

Este tipo de estructuras tiene dos aplicaciones principales:

1. Para realizar búsquedas específicas 

2. Buscar palabras en un diccionario o para comprobar ortografía así como

funciones de autorelleno. 

En este caso el programa es un diccionario de diferentes palabras, en donde 

se emplean las funciones de insertar, recorrer y buscar.

En cuanto a su analisis de complejidad, en las operaciones de TST toman 

un tiempo proporcional a la altura de dicho árbol. 

La función de búsqueda tiene una complejidad de O(log3n)

Ejemplo e información tomados de:

Geeks for geeks (2017). Ternary Search Tree recuperado del sitio: 

https://www.geeksforgeeks.org/ternary-search-tree/?ref=rp, el 3 de diciembre de 2020
