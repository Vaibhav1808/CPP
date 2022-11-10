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
        head = temp;
    }
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

Node* reveseLL(Node* head){

    if(head == NULL or head -> next == NULL){
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* fwd = NULL;

    while(curr != NULL){
        fwd = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = fwd; 
    }
    return prev;
}

void printReverse(Node *head){
    if(head == NULL){
        return;
    }
    printReverse(head -> next);
    cout << head-> data << " ";
}

Node* midpoint(Node* head){
    if(head == NULL or head -> next == NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head -> next;

    if(head != NULL){
        while(fast != NULL and fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
}

Node* kReverse(Node* head, int k){
    if(head == NULL){
        return head;
    }
    Node* curr = head;
    Node* prev = NULL;
    Node* fwd = NULL;
    int count = 0;

    while(curr != NULL and count < k){
        fwd = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = curr -> next;
        count++;
    }
    if(fwd != NULL){
        head -> next = kReverse(fwd, k);
    }
    return prev;
}

bool isCircular(Node* head){
    // Write your code here
    if(head == NULL){
        return NULL;
    }
    Node* temp = head -> next;
    while(temp != NULL && temp != head){
        temp = temp -> next;
    }
    
    if(temp == head){
        return true;
    }
    else{
        return false;
    }
}

Node* floyddetectLoop(Node* head){
    if(head == NULL){
        return false;
    }
    Node* slow = head;
    Node* fast = head;

    while(slow != NULL and fast != NULL and fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}

Node* getstartingNode(Node* head){
    if(head == NULL){
        return head;
    }
    Node* intersection = floyddetectLoop(head);
    Node* slow = head;

    while(slow != intersection){
        slow = slow -> next;
        intersection = intersection -> next;
    }
    return slow;
}

void removeLoop(Node* head){
    if(head == NULL){
        return;
    }
    Node* startofLoop = getstartingNode(head);
    Node* temp = startofLoop;

    while(temp -> next != startofLoop){
        temp = temp -> next;
    }
    temp -> next == NULL;
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