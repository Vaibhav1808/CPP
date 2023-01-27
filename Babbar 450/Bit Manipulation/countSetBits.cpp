#include <bits/stdc++.h>
using namespace std;

int setBits(int N) {
        // Write Your Code here
        int count = 0;
        while(N > 0){
            if((N & 1) == 1){
                count++;
            }
            N = N >> 1;
        }
        return count;
    }

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << setBits(n) << endl;
    }
    return 0;
}