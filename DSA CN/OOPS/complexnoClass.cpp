#include <iostream>
using namespace std;

class ComplexNumbers{
    private :
    int real, imaginary;

    public : 
    ComplexNumbers(int real, int imaginary){
        this -> real = real;
        this -> imaginary = imaginary;
    }
    void print(){
        cout << this -> real << " " << "+" << " " << "i" << imaginary << endl;
    }

    void plus(ComplexNumbers c2){
        real = real + c2.real;
        imaginary = imaginary + c2.imaginary;
    }

    void multiply(ComplexNumbers c2){
        int x = (real*c2.real) - (imaginary*c2.imaginary);
        int y = (real*c2.imaginary) + (imaginary*c2.real);

        real = x;
        imaginary = y;
    }
};