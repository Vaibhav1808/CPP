#include <iostream>
using namespace std;

int main(){
    int bin;
    cin >> bin;
    int rem , d = 0 , b = 1;

    while(bin > 0){
        rem = bin % 10;
        d = d + (rem*b);
        b *= 2;
        bin /= 10;
    }
    cout << d;
    
    return 0;
}