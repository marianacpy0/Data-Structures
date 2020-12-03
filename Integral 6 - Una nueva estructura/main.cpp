#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// Estructura del nodo
struct Node {

    char data;
    unsigned end: 1;
    struct Node* left, * ig, * right;
};

// Crear nuevo nodo de busqueda terciario
struct Node* newNode(char data) {

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->end = 0;
    temp->left = temp->ig = temp->right = NULL;
    return temp;

}

// Función recursiva para recorrer el árbol
void recorreUntil(struct Node* root, char* band, int an) {

    if (root) {
        // Recorrido hacia la izquierda
        recorreUntil(root->left, band, an);

        // Guarda el caracter en el nodo
        band[an] = root->data;
        if (root->end) {

            band[an + 1] = '\0';
            printf("%s\n", band);

        }

        // Recorre el arbol utilizando un apuntador de igualdad
        recorreUntil(root->ig, band, an + 1);

        // Recorrido final hacia la derecha
        recorreUntil(root->right, band, an);
    }
}


// Función del recorrido que incluye la función recursiva
void recorreTST(struct Node* root) {
    char value[100];
    recorreUntil(root, value, 0);
}

// Agregar una nueva palabra al árbol
void add(struct Node** root, char* var) {
    if (!(*root))
        *root = newNode(*var);

    if ((*var) < (*root)->data)
        add(&((*root)->left), var);

    else if ((*var) > (*root)->data)
        add(&((*root)->right), var);

    else {

        if (*(var + 1))
            add(&((*root)->ig), var + 1);

        else
            (*root)->end = 1;
    }
}

// Función de búsqueda
int busquedaTST(struct Node* root, char* busq) {
    if (!root)
        return 0;

    if (*busq < (root)->data)
        return busquedaTST(root->left, busq);

    else if (*busq > (root)->data)
        return busquedaTST(root->right, busq);

    else {

        if (*(busq + 1) == '\0')
            return root->end;

        return busquedaTST(root->ig, busq + 1);
    }
}


int main() {
  struct Node* root = NULL;

      FILE *pFile;
      char var1[500];
      int var2;

      pFile=fopen("dictionary.txt","r");
      if(pFile==NULL){
        printf("Not possible to open file");
      }

      while(fscanf(pFile, "%s",var1)!=EOF){
        add(&root, var1);
      }

      int option;
      cout<<"The following program includes a file with a series of words"<<endl;
      cout<<"they form part of a dictionary."<<endl;
      cout<<"------MENU--------"<<endl;
      cout<<"1.Sort words"<<endl;
      cout<<"2.Search for an specific word"<<endl;
      cin>>option;
      switch (option) {

        case 1:{

          recorreTST(root);
        }
        break;

        case 2:{
          char string[20];
          cout<<"Word to find: "<<endl;
          cin>>string;
          cout<<"Search results for "<<string<<" :";
          busquedaTST(root, string) ? printf(" Found\n") : printf(" Not Found\n");

        }
        break;

        }

    }
