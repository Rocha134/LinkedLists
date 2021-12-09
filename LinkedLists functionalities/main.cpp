//Iker Guerrero Gonzalez. A00830026.
//Aldo Mauricio Cruz Lozada. A01732372
//Francisco Rocha Juárez. A01730560
#include <iostream>
using namespace std;

//Creamos los nodos
struct Node{
  int data;
  struct Node *next;
};

struct Node2{
  int data2;
  struct Node2 *next2;
};

//Creacion de nuestra funcion push
void push(struct Node** pthead, int node_data){
   struct Node* newNode = new Node;

   newNode->data = node_data;

   newNode->next = (*pthead);

   (*pthead) = newNode;
}

void push2(struct Node2** pthead2, int node_data2){
   struct Node2* newNode2 = new Node2;

   newNode2->data2 = node_data2;

   newNode2->next2 = (*pthead2);

   (*pthead2) = newNode2;
}


//Creacion de nuestra funcion append para agregar datos
//Complejidad O(n)
void append(struct Node** pthead, int node_data){

  struct Node* newNode = new Node;

  struct Node *last = *pthead;

  newNode->data = node_data;

  newNode->next = NULL;

  if (*pthead == NULL){
    *pthead = newNode;
    return;
  }

  while (last->next != NULL)
    last = last->next;
    last->next = newNode;
    return;
}
void append2(struct Node2** pthead2, int node_data2){

  struct Node2* newNode2 = new Node2;

  struct Node2 *last2 = *pthead2;

  newNode2->data2 = node_data2;

  newNode2->next2 = NULL;

  if (*pthead2 == NULL){
    *pthead2 = newNode2;
    return;
  }

  while (last2->next2 != NULL)
    last2 = last2->next2;
    last2->next2 = newNode2;
    return;
}

//Funcion para mostrar nuestras listas
//Complejidad O(n)
void displaylist(struct Node *node){
   while (node != NULL){
     cout<<node->data<<endl;
     node = node->next;
   }
   // if(node==NULL)
   // cout<<"null";
}
void displaylist2(struct Node2 *node2){
   while (node2 != NULL){
     cout<<node2->data2<<endl;
     node2 = node2->next2;
   }
   // if(node2==NULL)
   // cout<<"null";
}

//Creacion de nuestra funcion de reversa, invierte los datos de la lista ligada
//Complejidad O(n)
void reverse1(struct Node **head){
  Node *current = *head;
  if(!current || !current->next) return;
  Node *high = current;
  Node *low = NULL;
  while(current){
    high = current->next;
    current->next = low;
    low = current;
    current = high;
  }
  *head = low;
}


//Creacion de la funcion equals, compara si las listas ligadas son iguales
//Complejidad O(n)
bool equals(Node* node1, Node* node2){
  while(node1 || node2){
    if(node1->data != node2->data) return false;
    node1 = node1->next;
    node2 = node2->next;
  }
  if(!node1 && !node2) return true;
  return false;
}

//Creacion de la funcion concat, concatena nuestras listas ligadas
//Complejidad O(n)
void concat(Node** node1, Node** node2){
  Node* h = *node2;
  while(h->next){
    h = h->next;
  }
  h->next = *node1;
}

int main(){

struct Node* head =NULL;
int numero;
cin>>numero;
int i;
for(i=1; i<=numero;i++){
   int node_data;
   cin>>node_data;
   append(&head,node_data);
}


struct Node* head2 =NULL;
int numero2;
cin>>numero2;
int i2;
for(i2=1; i2<=numero2;i2++){
     int node_data2;
     cin>>node_data2;
     append(&head2,node_data2);
  }

    reverse1(&head);
    displaylist(head);

    reverse1(&head2);
    displaylist(head2);

    int iguales;
    iguales = equals(head,head2);

    concat(&head, &head2);

    displaylist(head2);

    if (iguales == 0) {
      std::cout << "false" << '\n';
    } else {
      std::cout << "true" << '\n';
    }


  return 0;
}
