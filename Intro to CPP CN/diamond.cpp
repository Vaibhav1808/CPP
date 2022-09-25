#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int space = n-1;
    int i = 0;
    while(i < n){
        int j = 0;
        while(j < space){
            cout << " ";
            j++;
        }
 
        while(j <= i){
            cout << "*";
            j++;
        }
        cout << endl;
        space--;
        i++;
    }
}
