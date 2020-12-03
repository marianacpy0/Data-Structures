#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>
const int MAX=50;

using namespace std;

struct Video{
	string Title;
	string category;
	float Rating;
	int o;
};

bool storeVector(string fName, vector<string>& vect) {
	ifstream in("video.txt");

	if (!in)
	{
		cerr << "No es posible abrir el archivo : " << fName << endl;
		return false;
	}
	string str;

	while (getline(in, str))
	{
		if (str.size() > 0)
			vect.push_back(str);
	}
	in.close();
	return true;
}

void Swap(Video* *v, Video* *b){
	Video* temp=*v;
	*v=*b;
	*b=temp;
}

//Metodo Selection Sort en base al título
void titleSort(Video* b[], int n){
	int index;
	string small;

	for(int i=0; i<n-1; i++){
		index=i;
		small=b[index]->Title;

		for(int j=i+1; j<n; j++){
			if(b[j]->Title.compare(small)<0){
				index=j;
				small=b[index]->Title;
			}
		}
		if (index != i){
			Swap(&b[index], &b[i]);;
		}
	}
}

void categorySort(Video* b[], int n){
	int index;
	string small;

	for(int i=0; i<n-1; i++){
		index=i;
		small=b[index]->category;

		for(int j=i+1; j<n; j++){
			if(b[j]->category.compare(small)<0){
				index=j;
				small=b[index]->category;
			}
		}
		if (index != i){
			Swap(&b[index], &b[i]);;
		}
	}
}

int main(int argc, char* argv[]) {
	int option;
	Video video;
	Video vid[20];
	cout << "----- MENU ------" << endl;
	cout << "1. Read File" << endl;
	cout << "2. Sort by category" << endl;
	cout << "3. Sort by title" << endl;
	cout << "4. Search for a video or category"<<endl;
	cout << "Introduzca la opcion: " << endl;;
	cin >> option;

	switch (option) {

	case 1: {
		vector<string> ve;
		bool result = storeVector("content.cpp", ve);
		if (result) {
			for (string& line : ve)
				cout << line << endl;
		}
	}
		  break;

	case 2: {
		//Abrir el archivo y usar apuntadores para crear una nueva
		//estructura y logragr una escritura correcta
		ifstream File;
		File.open("video.txt");

		if(File){
			Video* Pointer[MAX];
			string T,C;
			float R;
			int o=0;

			while(!File.eof()){
				File>>T>>C>>R;

				Pointer[o]=new Video;

				Pointer[o]->Title=T;

				(*Pointer[o]).category=C;

				Pointer[o]->Rating=R;

				Pointer[o]->o=o+1;

				o++;
			}

		--o;

		//Menu para imprimir o crear un nuevo archivo
		cout<<"Select an option: "<<endl;
		cout<<"Print Result - P"<<endl;
		cout<<"Save to File - S"<<endl;
		char choice;
		cin>>choice;

		if(choice=='P'){

			titleSort(Pointer, o);
			cout<<"Categry A-Z"<<"  	"<<"Title"<<" 	 "<<"Duration "<< "  "<<endl;
				for(int i=0; i<o; i++)
					//Metodo de escritura por apuntadores
					cout<<Pointer[i]->Title<<"		"<<Pointer[i]->category<<"   "<<Pointer[i]->Rating<<"   "<<endl;
		}
		else if (choice=='S'){
			//Crear nuevo archivo y definir la estructura de lectura
			ofstream ts("SortedT.txt");
			cout<<"Sorted data in file SortedT.txt"<<endl;

			titleSort(Pointer, o);
			ts<<"Category A-Z"<<"  "<<"Title "<<" 	 "<<"Duration "<< "  "<<endl;
				for(int i=0; i<o; i++)
					ts<<Pointer[i]->Title<<"		"<<Pointer[i]->category<<"   "<<Pointer[i]->Rating<<"   "<<endl;

		}
		else{
			cout<<"Exit Invalid Option"<<endl;
		}
		}
		}

		break;
			case 3: {
				//Abrir el archivo y usar apuntadores para crear una nueva
				//estructura y logragr una escritura correcta
				ifstream File;
				File.open("video.txt");

				if(File){
					Video* Pointer[MAX];
					string T,C;
					float R;
					int o=0;

					while(!File.eof()){
						File>>T>>C>>R;

						Pointer[o]=new Video;

						Pointer[o]->Title=T;

						(*Pointer[o]).category=C;

						Pointer[o]->Rating=R;

						Pointer[o]->o=o+1;

						o++;
					}

				--o;

				//Menu para imprimir o crear un nuevo archivo
				cout<<"Select an option: "<<endl;
				cout<<"Print Result - P"<<endl;
				cout<<"Save to File - S"<<endl;
				char choice;
				cin>>choice;

				if(choice=='P'){

					categorySort(Pointer, o);
					cout<<"Category"<<"  	"<<"Title A-Z"<<" 	 "<<"Duration "<< "  "<<endl;
						for(int i=0; i<o; i++)
							//Metodo de escritura por apuntadores
							cout<<Pointer[i]->Title<<"		"<<Pointer[i]->category<<"   "<<Pointer[i]->Rating<<"   "<<endl;
				}
				else if (choice=='S'){
					//Crear nuevo archivo y definir la estructura de lectura
					ofstream ts("SortedT.txt");
					cout<<"Sorted data in file SortedT.txt"<<endl;

					categorySort(Pointer, o);
					ts<<"Category"<<"  "<<"Title A-Z "<<" 	 "<<"Duration "<< "  "<<endl;
						for(int i=0; i<o; i++)
							ts<<Pointer[i]->Title<<"		"<<Pointer[i]->category<<"   "<<Pointer[i]->Rating<<"   "<<endl;

				}
				else{
					cout<<"Exit Invalid Option"<<endl;
				}
				}
				}
		break;

		case 4:{
			string search;
			cin>>search;
			ifstream s("video.txt");
			if(!s.is_open())
			cout << "No es posible abrir el archivo"<<endl;

			string word;
			while(getline(s, word)){
				if(word.find(search) != string::npos){
					cout<<"Categry		"<<"Title	"<<"Duration	"<<endl;
					cout<<word<<endl;
				}

			}
		}break;
		}

	}
