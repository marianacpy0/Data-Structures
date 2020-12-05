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
        cout<<"You're on another planet."<<endl<<endl;
    }
    else{
        unordered_map <string , pair<int, string> > distances;//carries all distances to all the nodes from src and the previous node from the path
        for(auto it = map.begin() ; it != map.end() ; it++){
            distances[it->first].first = 99999;//intialize all the distances with "infinity"
            distances[it->first].second = "None";//and still you didn't reach any of them
        }
        distances[src].first = 0;//distance between src and src equals 0
        set < pair < int , string > > neighbors;//carries all the neighbors of the current node
        neighbors.insert(make_pair(0,src));//first step passing throgh src
        while (!neighbors.empty()){//finish calculating the shortest path from the current node to all it's neighbors
            node tmp;
            tmp.destination=neighbors.begin()->second;//store the top neighbor in the set as the current node
            tmp.n=neighbors.begin()->first;//store the top neighbor in the set as the current node
            neighbors.erase(neighbors.begin());//remove the neighbor that was just stored to empty the set from calculated neighbor's path
            for(auto it=map[tmp.destination].begin() ; it != map[tmp.destination].end() ; it++){//loop over all the current node's neighbors
                if(tmp.n + it->n <= distances[it->destination].first){// if the total cost(sum of weights) for getting to the current node + the weight of the neighbor's edge less than the stored cost in the ( unordered_map <string , pair<int, string> > distances; ) that carries all distances to all the nodes from src and the previous node from the path
                    //if true replace the current stored path in the ( unordered_map <string , pair<int, string> > distances; ) that carries all distances to all the nodes from src and the previous node from the path
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
        vector <string> locations;//stores the path
        string loc = dst;//starting from dst
        while(loc != "None"){
            locations.push_back(loc);//store the node that you came from all the way to src
            loc = distances[loc].second;
        }
        for(int i=locations.size()-1 ; i>-1 ; i--){//because the path stored in reverse in the ( vector <string> locations; ) 
            cout<<locations[i]<<"  ";
        }
        cout<<endl<<endl;
    }
}

#endif