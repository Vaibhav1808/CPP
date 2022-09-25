#include <iostream>
using namespace std;

bool IsPrime(int n){
    int d = 2;
    while(d < n){
        if(n % d == 0){
            return false;
        }
        d++;
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    bool ans = IsPrime(n);
    cout << ans << endl;
    
    return 0;
}