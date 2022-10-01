#include <iostream>
using namespace std;
#include "fractionClass.cpp"

int main(){
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    f1.Add(f2);
    f1.Print();
    f2.Print();

    f1.Multiply(f2);
    f1.Print();
    f2.Print();
}