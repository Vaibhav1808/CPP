#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int * arr;
        int size;
        int top;

    Stack(int size){ 
        this -> size = size;
        arr = new int[size];
        top = -1;
    }
    
    void Push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack OverFlow" << endl;
        }
    }
    void Pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout << "Stack UnderFlow" << endl;
        }                                
    }
    int peek(){
        if(top >= 0 and top < size){
            return arr[top];
        }
        else{
            cout << "Stack is empty" << endl;
            return -1;
        }
    }
    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
    
};

int main(){

    Stack st(5);
    
    st.Push(22);
    st.Push(42);
    st.Push(50);

    cout << st.peek() << endl;
    st.Pop();
    cout << st.peek() << endl;
    st.Pop();
    cout << st.peek() << endl;
    if(st.isEmpty()){
        cout << "Khaali hai" << endl;
    }
    else{
        cout << "Khaali nhi hai" << endl;
    }

    st.Pop();
    cout << st.peek() << endl;

    if(st.isEmpty()){
        cout << "Khaali hai" << endl;
    }
    else{
        cout << "Khaali nhi hai" << endl;
    }

    st.Push(100);
    st.Push(16);
    st.Push(18);
    st.Push(7);
    st.Push(17);
    st.Push(11);
    
    cout << st.peek() << endl;
    return 0;
}
