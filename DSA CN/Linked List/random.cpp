#include <bits/stdc++.h>
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
Node* takeInput(){
    int data;
    cin >> data;

    Node* head = NULL;
    while(data != -1){
        Node * newNode = new Node(data);
        if(head == NULL){
            head = newNode;
        }
        else{
            Node* temp = head;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
        cin >> data;
    }
    return head;
}

Node* takeInputBetter(){
    int data;
    cin >> data;

    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = tail -> next;
        }
        cin >> data;
        }
    return head;
}

void printLL(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int length(Node *head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head -> next;
    }
    return count;
}

void printIthNode(Node *head, int i)
{
    //Write your code here
    int count = 0;
    while(head != NULL){
        count++;
        if(count == i+1){
            cout << head -> data;
        }
        head = head -> next;
    }
}

int length(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}

Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
    if(head == NULL){
        return head;
    }

    if(pos == 0){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else if(pos >= length(head)){
        return head;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int count = 0;
        while(count < pos){
            count++;
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
    return head;
}

int lengthRec(Node *head) {
    // Write your code here
    if(head == NULL){
        return 0;
    }
	return length(head -> next) + 1;
}

Node* insertNode(Node *head, int i, int data) {
	// Write your code here
    if(head == NULL){
        if(i = 0){
            Node* newNode = new Node(data);
            return newNode;
        }
        return head;
    }
    Node* newNode = new Node(data);
    if(i == 0){
        newNode -> next = head;
        head = newNode;
        return head;
    }
    head -> next = insertNode(head-> next, i-1, data);
    return head;
}

Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
    if(head == NULL){
        return NULL;
    }
    if(pos == 0){
        head = head->next;
        return head;
    }
    head->next = deleteNodeRec(head->next,pos-1);
    return head;
}

int findNode(Node *head, int n){
    // Write your code here.
    int pos = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp -> data == n){
            return pos;
            break;
        }
        else{
            pos++;
            temp = temp -> next;
        }
    }
    return -1;
}

Node *removeDuplicates(Node *head)
{
    Node* temp = head;
	if(head == NULL){
        return head;
    }
    
    while(temp -> next != NULL){
        if(temp -> data == temp -> next -> data){
            temp -> next = temp -> next -> next;
        }
        else{
            temp = temp -> next;
        }
    }
    return head;
}

void printReverse(Node *head)
{
    if(head == NULL){
        return;
    }
    printReverse(head -> next);
    cout << head-> data << " ";
}

int main(){
    // Node* n1 = new Node(10);
    // Node* n2 = new Node(20);
    // Node* n3 = new Node(30);
    // Node* n4 = new Node(-12);
    // Node* head = n1;
    // printLL(head);
    Node* head = takeInputBetter();
    printLL(head);
    cout << endl;
    cout << length(head);
    return 0;
}