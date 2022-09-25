#include <bits/stdc++.h>
using namespace std;

int multiply(int n, int m){
    if(n == 0 || m == 0){
        return 0;
    }
    int small_output = multiply(n, m-1);
    return n + small_output;
}

int main()
{
    int n, m;
    cin >> n >> m;

    cout << multiply(n, m) << endl;
    
    return 0;
}