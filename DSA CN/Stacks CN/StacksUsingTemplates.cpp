#include <bits/stdc++.h>
using namespace std;

template <typename T>

class stackUsingArray{
    T* data;
    int nextIndex;
    int capacity;

    public:
        stackUsingArray(){
            data = new T[4];
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
        void push(T element){
            if(nextIndex == capacity){
                T *newData = new T[2*capacity];
                for(int i = 0; i < capacity; i++){
                    newData[i] = data[i];
                }
                capacity = 2*capacity;
            }

            data[nextIndex] = element;
            nextIndex++;
        }

        // delete element
        T pop(){
            if(IsEmpty()){
                cout << "Stack is empty" << endl;
                return -1;
            }
            nextIndex--;
            return data[nextIndex];
        }

        // top element
        T top(){
            if(IsEmpty()){
                cout << "Stack is empty" << endl;
                return -1;
            }
            return data[nextIndex - 1];
        }
};


int main(){
    stackUsingArray <char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
     
    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.size() << endl;

    cout << s.IsEmpty() << endl;

    return 0;
}
