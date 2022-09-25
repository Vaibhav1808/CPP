#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    cout << ++a << endl; // preincrement: value +1 hojaegi aur cout bhi increased value hogi
     
    cout << a++ << endl; // postincrement: value +1 hojaegi but cout wahi puraani value hogi

    cout << a-- << endl;
    cout << --a << endl;
    
    return 0;
}

