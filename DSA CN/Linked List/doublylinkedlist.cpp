#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

    // constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }

};

int getLength(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}

void insertAtHead(Node* &head, int d){

    if(head == NULL){

    }
    else{
        Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    }
    
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head, int pos, int d){
    if(pos == 1){
        insertAtHead(head, d);
    } 
    Node* temp = head;
    int count = 1;
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
    temp -> next -> prev = NodeToInsert;
    temp -> next = NodeToInsert;
    NodeToInsert -> prev = temp;
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);

    cout << getLength(head) << endl;

    insertAtHead(head, 11);
    print(head);
    cout << getLength(head) << endl;

    insertAtHead(head, 9);
    print(head);
    cout << getLength(head) << endl;

    insertAtTail(tail, 25);
    print(head);
    cout << getLength(head) << endl;

    insertAtPosition(head, 2, 101);
    print(head);
    cout << getLength(head) << endl;    

    return 0;
}