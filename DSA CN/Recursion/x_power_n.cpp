#include <bits/stdc++.h>
using namespace std;

int func(int a, int b){
    if(b != 0){
        int smallOutput = func(a , b-1);
        int ans = a*smallOutput;
        return ans;
    }
    else{
        return 1;
    }
}

int main()
{
    int x, n;
    cin >> x >> n;
    
    int req = func(x, n);
    cout << req;
    return 0;
}