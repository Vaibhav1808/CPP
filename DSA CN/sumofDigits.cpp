#include <bits/stdc++.h>
using namespace std;

int digitSum(int n){
    if(n == 0){
        return 0;
    }
    
    int small_output = digitSum(n/10);
    int ans = (n%10) + small_output;
    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << digitSum(n) << endl;
    return 0;
}