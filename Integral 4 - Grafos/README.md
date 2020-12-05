# README

Implentación de grafos por medio de un archivo que contiene dos ciudades y la distancia entre ellas 

el programa cuenta con las siguientes funciones:

- ChargeFile:

Esta función tiene un análisis de complejidad de O(n), debido a que recorre

el archivo de manera lineal.

- AddEdge:

Los edges se agregan a una lista de adjacencia por lo que su complejidad 

es de O(1)

- RemoveEdge:

Esta función elimina el camino entre dos ciudades

analisis de complejidad de esta función es de O(V)

- Printdestination:

Esta funcion imprime todos los destinos posibles y su respectiva 

distancia, al ser una lista de adjacencia su complejidad es de O(|V|+|E|)

-Shortest Path:

Esta función hace uso del algoritmo de Dijkstra para encontrar el camino mas corto entre dos destinos

por lo que su análisis de complejidad

es de O(|V|^2)
