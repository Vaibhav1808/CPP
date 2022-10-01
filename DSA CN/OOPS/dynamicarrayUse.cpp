#include <iostream>
using namespace std;
#include "dynamicarrayClass.cpp"

int main(){
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    d1.Print();

    DynamicArray d2(d1);          // Copy Constructor  // shallow copy

    d1.add(0, 100);

    DynamicArray d3;
    d3 = d1;           // copy asignment operator // shallow copy

    d2.Print();
    d3.Print();
}