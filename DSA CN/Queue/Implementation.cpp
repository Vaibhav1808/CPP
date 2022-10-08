#include <bits/stdc++.h>
using namespace std;

class Queue{
    int * arr;
    int front;
    int rear;
    int size;

    public: 
        Queue(){
            size = 100001;
            arr = new int[size];
            front = 0;
            rear = 0;
        }
};