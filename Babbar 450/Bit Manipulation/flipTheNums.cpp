#include <bits/stdc++.h>
using namespace std;

int countBitsFlip(int a, int b){
    int temp = a^b;
    int count = 0;
    while(temp > 0){
        if((temp & 1) == 1){
            count++;
        }
        temp = temp >> 1;
    }
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << countBitsFlip(a,b) << endl;
    }
}