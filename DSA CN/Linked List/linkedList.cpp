#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    // constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    // destructor
    ~Node(){
        int value = this -> data;

        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }

    }
};

void insertAtHead(Node* &head, int d){

    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
    }

    else{
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
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

    // if(temp -> next == NULL){
    //     insertAtTail(tail, d);
    //     return;
    // }

    // creating new node for d
    Node* NodeToInsert = new Node(d);
    NodeToInsert -> next = temp -> next;
     temp -> next = NodeToInsert;
}

void delNodebyPos(Node* &head, int pos){
    // deleting start node 
    if(pos == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }

    else{
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;

        while(count < pos){
            prev = curr;
            curr = curr -> next;
            count++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

// void delNodebyValue(Node* &head, Node* &curr){
//     if(head == NULL or curr == NULL){
//         return;
//     }
//     if(head == curr){
//         head -> next = curr -> next;
//     }
    
// }

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
    cout << endl;

    delNodebyPos(head, 1);
    print(head);
    
    return 0;
}