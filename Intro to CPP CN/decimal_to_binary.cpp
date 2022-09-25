#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;

    int i = 1, bin = 0, rem;

    while(n != 0){
        rem = n % 2;
        n = n / 2;
        bin = bin + rem*i;
        i = i*10;
    }
    cout << bin;
    return 0;
}
