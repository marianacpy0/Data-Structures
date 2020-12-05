#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_map>
#include <vector>
#include <set>
#include <utility>
#include <iostream>

using namespace std;

class node{
public:
  string destination;
  int n;
};

class Graph{
public:
    unordered_map < string , vector < node > > map;
    void addEdge(string loc, string dest, int dist);
    void removeEdge(string loc,string dest);
    void printMap();
    void shortestPath(string loc, string dest);
};

void Graph::addEdge(string loc , string dest , int dist){
    node tmp;
    //desde locacion hasta destino
    tmp.destination=dest;
    tmp.n=dist;
    map[loc].push_back(tmp);
    //from destino hasta locacion
    tmp.destination=loc;
    tmp.n=dist;
    map[dest].push_back(tmp);
};

void Graph::removeEdge(string loc, string dest){
  //Entre locacion y destination
    for(int i = 0 ; i<map[loc].size() ; i++){
        if(map[loc][i].destination == dest){
            map[loc].erase(map[loc].begin() + i);
        }
    }
    //entre destination y locacion
    for(int i = 0 ; i<map[dest].size() ; i++){
        if(map[dest][i].destination == loc){
            map[dest].erase(map[dest].begin() + i);
        }
    }
};

void Graph::printMap(){
    for (unordered_map< string , vector < node > >::iterator map_it = map.begin() ; map_it != map.end() ; map_it++){
        for(int i=0 ; i<map_it->second.size() ; i++){
            cout<<map_it->first<<" has "<<map_it->second[i].n<<" miles distance to "<<map_it->second[i].destination<<endl;
        }
    }
};

void Graph::shortestPath(string src , string dst){
      if(src == dst){
        cout<<"You are there."<<endl<<endl;
    }
    else if(map[dst].empty()){
        cout<<"No possible path"<<endl<<endl;
    }
    else if(map[src].empty()){
        cout<<"No matching destinations."<<endl<<endl;
    }
    else{
        unordered_map <string , pair<int, string> > distances;//Carga todas las distancias de todos los nodos
        for(auto it = map.begin() ; it != map.end() ; it++){
            distances[it->first].first = 99999;//Inicializa en infinito
            distances[it->first].second = "None";//No se encontro ninguno
        }
        distances[src].first = 0;//La distancia de locación es igual a 0
        set < pair < int , string > > neighbors;//arrastra a todos los nodos 
        neighbors.insert(make_pair(0,src));//Primer paso, pasa por locación
        while (!neighbors.empty()){//Termina de calcular el camino mas corto
            node tmp;
            tmp.destination=neighbors.begin()->second;//guarda el top node en el get del nodo
            tmp.n=neighbors.begin()->first;//guarda el top node como sel set del noto actual
            neighbors.erase(neighbors.begin());//Elimina los nodos que fueron gurdados
            for(auto it=map[tmp.destination].begin() ; it != map[tmp.destination].end() ; it++){//loop en el nodo actual
                if(tmp.n + it->n <= distances[it->destination].first){//Suma de los nodos de hacer varios recorridos del path
                    auto old_pair = make_pair(distances[it->destination].first , it->destination);
                    auto find_old_pair = neighbors.find(old_pair);
                    if(find_old_pair!=neighbors.end()){
                        neighbors.erase(find_old_pair);
                    }
                    auto new_pair = make_pair( (tmp.n + it->n) , it->destination );
                    neighbors.insert(new_pair);
                    distances[it->destination].first = tmp.n + it->n;
                    distances[it->destination].second = tmp.destination;
                }
            }
        }
        cout<<"The total distance: "<<distances[dst].first<<endl<<endl;
        cout<<"The shortest path is through locations: ";
        vector <string> locations;//guarda el camino
        string loc = dst;//inicia desde destination
        while(loc != "None"){
            locations.push_back(loc);//Guarda el nodo hasta location
            loc = distances[loc].second;
        }
        for(int i=locations.size()-1 ; i>-1 ; i--){//El nodo se guarda en reversa, se cambia
            cout<<locations[i]<<"  ";
        }
        cout<<endl<<endl;
    }
}

#endif
