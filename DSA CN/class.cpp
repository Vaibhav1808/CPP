#include <bits/stdc++.h>
using namespace std;

class Student{
    public: // public class can be accessed but private can't be accessed

    int age;
    int rollno;
    static int totalStudents;   // access this by writing Student :: totalStudents
    
    private:
    int height;

    public:


    ~Student(){
        cout << "Desttructor Called! " << endl;
    }

    //Default constructor
    Student(){
        totalStudents++;
        //cout << "Constructor Called!" << endl;
    }

    //Parametrised constructor
    Student(int r){
        cout << "Constructor 1 called!" << endl;
        rollno = r;
    }

    //This Keyword
    // Student(int rollno){
    //     this -> rollno = rollno;  // when both variables are same
    // }
    void display(){
        cout << age << " " << rollno << " " << height << endl;
    }
    int getHeight() const{
        return height;
    }
    void setHeight(int a){
        height = a;
    }
};

int Student :: totalStudents = 0; // initializing static data members

int main(){
    Student s1, s2, s3, s5, s6; // Creating objects statically
    s1.age = 24;
    s1.rollno = 5;
    s1.setHeight(6);
    s1.display();

    Student *s4 = new Student;   // Creating objects dynamically

    // (*s4).age = 23;
    // (*s4).rollno = 9;   
    // another way to write this same is as follows

    s4 -> age = 23;
    s4 -> rollno = 9;
    s4 -> setHeight(7);
    // s4 -> getHeight();
    s4 -> display();

    Student s5(10);      // Constructor 1 called
    Student s6(s5);      // Copy Constructor

    s1 = s2;             // Copy asignment operator
    Student s7 = s6;     // Copy constructor
}
