#include <bits/stdc++.h>
using namespace std;

class stackUsingArray{
    int* data;
    int nextIndex;
    int capacity;

    public:
        stackUsingArray(){
            data = new int [4];
            nextIndex = 0;
            capacity = 4;
        }
        int size(){ //return number of elements in a stack
            return nextIndex;
        }
        // check if stack is empty
        bool IsEmpty(){
            if(nextIndex == 0){
                return true;
            }
            return false;
        }

        // insert element in stack
        void push(int element){
            if(nextIndex == capacity){
                int *newData = new int[2*capacity];
                for(int i = 0; i < capacity; i++){
                    newData[i] = data[i];
                }
                capacity = 2*capacity;
            }

            data[nextIndex] = element;
            nextIndex++;
        }

        // delete element
        int pop(){
            if(IsEmpty()){
                cout << "Stack is empty" << endl;
                return -1;
            }
            nextIndex--;
            return data[nextIndex];
        }

        // top element
        int top(){
            if(IsEmpty()){
                cout << "Stack is empty" << endl;
                return -1;
            }
            return data[nextIndex - 1];
        }



};

