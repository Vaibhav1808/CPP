#include <bits/stdc++.h>
using namespace std;

void printNum(int n){
    if(n >= 1){
        printNum(n-1);
        cout << n << " ";
    }
}


int main()
{
    int n;
    cin >> n;

    printNum(n);
    return 0;
}