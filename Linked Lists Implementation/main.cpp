#include "node.h"
using namespace std;


void Inserta_al_inicio(Node** he, Node** ta, int num){
    Node* head = *he;
    Node* tail = *ta;
    Node* t;
    t = (Node *)malloc(sizeof(Node));
    if (head != NULL){
        *t = Node(num, head);
        head = t;
    }
    else{
        *t = Node(num, NULL);
        head = t;
        tail = head;
    }
    *he = head;
    *ta = tail;
}

void Inserta_al_final(Node** he, Node** ta, int num){
    Node* head = *he;
    Node* tail = *ta;
    Node* t;
    t = (Node *)malloc(sizeof(Node));
    if (tail != NULL){
        *t = Node(num, NULL);
        tail->SetAfter(t);
        tail = t;
    }
    else{
        *t = Node(num, NULL);
        head = t;
        tail = head;
    }
    *he = head;
    *ta = tail;
}

void Elimina_al_inicio(Node** he, Node** ta){
    Node* head = *he;
    Node* tail = *ta;
    if (head != NULL){
        Node* t = head;
        if (head == tail){
            head = NULL;
            tail = NULL;
        }
        else {
           head = head->GetAfter();
        }
        delete [] t;
    }
    else {
        cout << "ERROR" << endl;
    }
    *he = head;
    *ta = tail;
}

void Elimina_al_final(Node** he, Node** ta){
    Node* head = *he;
    Node* tail = *ta;
    if (tail != NULL){
        Node* t = tail;
        if (head == tail){
            head = NULL;
            tail = NULL;
        }
        else {
            Node* x = head;
            while (x != NULL){
                if (x->GetAfter() == tail){
                    tail = x;
                }
                x = x->GetAfter();
            }
           tail->SetAfter(NULL); 
        }
        delete [] t;
    }
    else {
        cout << "ERROR" << endl;
    }
    *he = head;
    *ta = tail;
}

void Imprime(Node** he, Node** ta){
    Node* head = *he;
    Node* tail = *ta;
    Node* t = head;
    while (t != NULL){
        cout << t->GetNum() << endl;
        t = t->GetAfter();
    }
}



int main() {
    Node* head = NULL;
    Node* tail = NULL;
    Node** h = &head;
    Node** t = &tail;


    int opcion = 5;
    int temp;

    while (opcion != 0){
        cin >> opcion;
        if (opcion == 1){
            cin >> temp;
            Inserta_al_inicio(h, t, temp);
        }
        else if (opcion == 2){
            cin >> temp;
            Inserta_al_final(h, t,temp);
        }
        else if (opcion == 3){
            Elimina_al_inicio(h, t);
        }
        else if (opcion == 4){
            Elimina_al_final(h, t);
        }
        else if (opcion == 5){
            Imprime(h, t);
        }
    }

    return 0;
}