#include <bits/stdc++.h>
using namespace std;

class Student{
    int age;
    char *name;

    public:
        Student(int age, char* name){
            this -> age = age;
            // Shallow copy
            // this -> name = name; name mai koi changes kiye toh original pe bhi impact hoga\

            // Deep Copy
            this -> name = new char[strlen(name) + 1];
            strcpy(this -> name, name);
        }

        // Copy Constructor
        Student(Student const &s){
            this -> age = s.age;

            //Shallow copy
            // this -> name = s.name;

            //Deep copy
            this -> name = new char[strlen(name) + 1];
            strcpy(this -> name, name);
        }

        void Display(){
            cout << name << " " << age << endl;
        }
};