#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, int d){

    // create new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    // create new node
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

void insertAtPosition(Node* &head, Node* &tail,  int pos, int d){
    Node* temp = head;
    int count = 1;

    if(pos == 1){
        insertAtHead(head, d);
        return;
    }

    if(temp -> next == NULL){
        insertAtTail(head, d);
    }

    while(count < pos - 1){
        temp = temp -> next;
        count++;
    }

    // creating new node for d
    Node* NodeToInsert = new Node(d);
    NodeToInsert -> next = temp -> next;
     temp -> next = NodeToInsert;
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " "; 
        temp = temp -> next;
    }
}

int main(){

    Node* node1 = new Node(10);
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;

    // head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    
    print(head);
    cout << endl;

    insertAtTail(tail, 12);

    print(head);
    cout << endl;

    insertAtHead(head, 15);

    print(head);
    cout << endl;

    insertAtPosition(head, tail, 3, 22);
    print(head);
    return 0;
}