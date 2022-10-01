#include <iostream>
using namespace std;

class Fraction{
    private :
    int numerator;
    int denominator;

    public : 
    Fraction(int numerator, int denominator){
        this -> numerator = numerator;
        this -> denominator = denominator;
    }

    void Print() const{
        cout << this -> numerator << "/" << denominator << endl; 
    }

    void Simplify(){
        int gcd = 1;
        int m = min(this -> numerator, this -> denominator);

        for(int i = 1; i <= m; i++){
            if(this -> numerator % i == 0 and this -> denominator % i == 0){
                gcd = i;
            }
        }
        this -> numerator = this -> numerator / gcd;
        this -> denominator = this -> denominator / gcd;
    }

    // Operator Overloading
    Fraction operator+(Fraction const &f2) const {
        int lcm = denominator*f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = x*numerator + (y * f2.numerator);

        Fraction fNew(num, lcm);
        fNew.Simplify();
        return fNew;
    }

    void Add(Fraction const &f2){
        int lcm = denominator*f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = x*numerator + (y * f2.numerator);

        numerator = num;
        denominator = lcm;
        Simplify();
    }

    //Operator Overloading
    Fraction operator*(Fraction const &f2) const {
        int n = numerator*f2.numerator;
        int d = denominator*f2.denominator;
        Fraction fNew(n,d);
        fNew.Simplify();
        return fNew;
    }

    // Operator Overloading
    bool operator==(Fraction const &f2) const {
        return (numerator == f2.numerator and denominator == f2.denominator);
    }

    void Multiply(Fraction const &f2){
        numerator = numerator*f2.numerator;
        denominator = denominator*f2.denominator;
        Simplify();
    }

    // pre increment operator overloading
    Fraction& operator++(){
        numerator = numerator + denominator;
        Simplify();
        return *this;
    }

    // post increment operator overloading
    Fraction operator++(int){
        Fraction fNew(numerator, denominator);
        numerator = numerator + denominator;
        Simplify();
        fNew.Simplify();
        return fNew;
    }

    Fraction& operator+=(Fraction const &f2){
        int lcm = denominator * f2.denominator;
        int x = lcm/denominator;
        int y = lcm/f2.denominator;

        int num = x*numerator + (y*f2.denominator);
        numerator = num;
        denominator = lcm;
        Simplify();

        return *this;
    }
};