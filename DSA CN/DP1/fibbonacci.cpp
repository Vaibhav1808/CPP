#include <bits/stdc++.h>
using namespace std;


// brute force
int fibo_1(int n){
    if(n <= 1){
        return n;
    }

    int a = fibo_1(n-1);
    int b = fibo_1(n-2);
    return a+b;
}

int fibo_helper(int n, int *ans){
    if(n <= 1){
        return n;
    }

    // check if answer exists
    if(ans[n] != -1){
        return ans[n];
    }

    int a = fibo_helper(n-1, ans);
    int b = fibo_helper(n-2, ans);

    ans[n] = a + b; // saving output for future use

    return ans[n];
}

// memoization (top-down)
int fibo_2(int n){
    int *ans = new int[n+1];

    for(int i = 0; i < n; i++){
        ans[i] = -1;  // initialise array with -1
    }

    return fibo_helper(n, ans);
}


// dynamic programming (bottom up)
int fibo_3(int n){
    int *ans = new int[n+1];

    ans[0] = 0;
    ans[1] = 1;

    for(int i = 2; i <= n; i++){
        ans[i] = ans[i-1] + ans[i-2];
    }

    return ans[n];
}