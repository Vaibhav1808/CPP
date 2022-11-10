#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node{
    public:
    T data;
    Node<T>* next;

    Node(T data){
        this -> data = data;
        next = NULL;
    }
};

template <typename T>
class Stack{
    Node<T>* head;
    int size;   // number of elements in stack
    
    public:
    Stack(){
        head = NULL;
        size = 0;
    }

    int getSize(){
        return size;
    }

    bool IsEmpty(){
        if(head == NULL){
            return 1;
        }
        return 0;
    }

    void push(T element){
        Node<T>* newnode = new Node(data);
        newnode -> next = head;
        head = newnode;
        size++;
    }

    T pop(){
        if(head == NULL){
            return -1;
        }
        Node*<T> ans = head;
        head = head -> next;
        size--;
        return ans -> data;
        delete ans;
    }
    T top(){
        if(head == NULL){
            return -1;
        }
        return head -> data;
    }
};