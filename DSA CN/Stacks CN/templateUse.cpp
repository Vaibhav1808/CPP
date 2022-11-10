#include <bits/stdc++.h>
using namespace std;
#include "templates.cpp"

int main(){
    /*Pair <int> p1; 
    Pair <double> p2;

    p1.setX(10);
    p1.setY(20);

    cout << p1.getX() << " " << p1.getY() << endl;

    p2.setX(100.23);
    p2.setY(90.62);

    cout << p2.getX() << " " << p2.getY() << endl;*/

    Pair<int, double> p1;
    p1.setX(100.34);
    p1.setY(100.34);

    cout << p1.getX() << " " << p1.getY() << endl;


    // Creating triplet using the same pair class
    Pair<Pair<int,int>, int> p2;
    Pair<int,int> p3;
    p3.setX(10);
    p3.setY(16);

    p2.setX(p3);
    p2.setY(18);

    cout << p2.getX().getX() << " " << p2.getX().getY() << " " << p2.getY() << endl;
    return 0;
}