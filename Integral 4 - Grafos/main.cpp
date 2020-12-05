#include <iostream>
#include <fstream>
#include "graph.h"

using namespace std;

int main() {
  Graph destinations;
  int option;
  cout<<"Welcome"<<endl;
  cout<<"The following program contains an itinerary with distance between 2 places"<<endl;
  cout<<"Select '1' before anything"<<endl;
  loop:
    cout<<"==== Menú ====="<<endl;
    cout<<"Select an option:"<<endl;
    cout<<"1. Charge File"<<endl;
    cout<<"2. Remove Edge"<<endl;
    cout<<"3. Print destinations"<<endl;
    cout<<"4. Shortest path in two destinations"<<endl;
  cin>>option;
      if(option == 1){
      string from;
      string to;
      string distance;
      int dist;

      ifstream in("places.txt");
      //ent.open("places.txt");
      while(!in.eof()){
        in>>from>>to>>dist;
        destinations.addEdge(from , to , dist);

      }
        
        goto loop;
    }

        else if(option == 2){
        cout<<"Enter source's name: "<<endl;
        string from;
        cin>>from;
        cout<<"Enter destination's name:\n>> ";
        string to;
        cin>>to;
        destinations.removeEdge(from , to);
        goto loop;
    }

        else if(option == 3){
        destinations.printMap();
        goto loop;
    }
        else if(option == 4){
        cout<<"Enter source's name"<<endl;
        string from;
        cin>>from;
        cout<<"Enter destination's name:"<<endl;
        string to;
        cin>>to;
        destinations.shortestPath(from , to);
        goto loop;
    }
    else if(option == 0){
        return 0;
    }
    else{
        goto loop;
    }
}
