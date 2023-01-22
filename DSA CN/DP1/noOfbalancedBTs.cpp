#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;

int balancedBTs(int h){
    if(h <= 1){
        return 1;
    }
    int a = balancedBTs(h-1);
    int b = balancedBTs(h-2);

    int temp1 = (int)(((long)(a)*a) % mod);
    int temp2 = (int)((2*(long)(a)*b) % mod);
    int ans = (temp1 + temp2) % mod;

    return ans;
}

// dp
int balancedBTs_DP(int n){
    int *ans = new int[n+1];
    ans[0] = 1;
    ans[1] = 1;

    for(int i = 2; i <= n; i++){
        int temp1 = (int)(((long)(ans[i-1])*ans[i-1]) % mod);
        int temp2 = (int)((2*(long)(ans[i-1])*ans[i-2]) % mod);
        ans[i] = (temp1 + temp2) % mod;
    }
    return ans[n];

}