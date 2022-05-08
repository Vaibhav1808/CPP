// Pointers 

#include <iostream>
using namespace std;

int main(){
    // A pointer is a data type which holds the address of other data types.
    int a;
    int* b =&a;

    // & is (address of) operator
    cout<< "The address of a is: "<<&a<< endl;
    cout<< "The address of a is: "<<b;

    // * is (value at) dereferece operator
    cout<< "The value at address b is: "<<b<<endl;

    // Pointer to Pointer
    int** c =&b;
    cout<< "The address of b is: "<<&b<<endl;
    cout<< "The address of b is: "<<c<<endl;
    cout<< "The value at address c is: "<<*c<<endl;
    cout<< "The value at address value_at(value_at(c)) is: "<<**c<<endl;
    
    return 0;
}

