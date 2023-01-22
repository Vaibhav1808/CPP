#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9+7;

// recursion
int staircase_1(int n){
    if(n == 1 or n == 0){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    else{
        return staircase_1(n-3) + staircase_1(n-2) + staircase_1(n-1);
    }
}


int staircaseHelper(int n, int *ans){
    if(n <= 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }

    if(ans[n] != -1){
        return ans[n];
    }

    int a = staircaseHelper(n-1, ans);
    int b = staircaseHelper(n-2, ans);
    int c = staircaseHelper(n-3, ans);

    ans[n] = a + b + c;
    return ans[n];
}

// memoisation
int staircase_2(int n){
    int *ans = new int[n+1];

    for(int i = 0; i < n; i++){
        ans[i] = -1;  // initialise array with -1
    }

    return staircaseHelper(n, ans);
}

// dynamic programming
ll staircase_3(int n){
    ll *ans = new ll[n+1];

    ans[0] = 1;
    ans[1] = 1;
    if(n >= 2){
        ans[2] = 2;
    }

    for(ll i = 3; i <= n; i++){
        ans[i] = ans[i-1]%mod + ans[i-2]%mod + ans[i-3]%mod;
        ans[i] = ans[i]%mod;
    }
    return ans[n]%mod;
}


int main(){

    // write your code here
    ll t;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      cout << staircase_1(n) << endl;
    }
    return 0;
}