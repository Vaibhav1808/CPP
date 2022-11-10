#include <bits/stdc++.h>
using namespace std;

template <typename T>
class QueueUsingArray{
    T* data;
    int firstIndex;
    int nextIndex;
    int size;

    public:
    QueueUsingArray(int s){
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
    }
    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    // insert
    void enqueue(T ele){
        
    }
};