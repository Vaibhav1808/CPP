#include <bits/stdc++.h>
using namespace std;
#include "shallow&deepCopy.cpp"

int main(){
    char name[] = "abcd";
    Student s1(20, name);
    s1.Display();

    name[3] = 'e';
    Student s2(24, name);
    s2.Display();

    s1.Display();

}