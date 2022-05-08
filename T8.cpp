// if else in cpp


#include<iostream>
using namespace std;

int main(){
    int age;
    cout<< "Enter your age: ";
    cin>> age;

    if ((age<18) && (age>0)){
        cout<< "Ghar pe padhai karo"<< endl;
    }
    else if (age == 18){
        cout<< "Aajaana par daaru nhi milegi"<< endl;
    }
    else if (age<1){
        cout<<"Paida toh hoja phle";
    }
    else {
        cout<< "Lesgoooooo PARTY!!";
    }

return 0;
}