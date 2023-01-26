#include <bits/stdc++.h>
using namespace std;

// recursion
int maxMoneyLooted_1(int *arr, int n){
    // base case
    if(n == 0){
        return 0;
    }

    if(n == 1){
        return arr[0];
    }
    else{
        int a = maxMoneyLooted_1(arr+1, n-1);
        int b = maxMoneyLooted_1(arr+2, n-2) + arr[0];
        return max(a,b);
    }
}

// memoisation
int maxMoneyLootedHelper(int *arr, int n, int *ans){
    // base case
    if(n == 0){
        return 0;
    }

    if(n == 1){
        ans[n] = arr[0];
    }

    else{
        int a = maxMoneyLootedHelper(arr+1, n-1, ans);
        int b = maxMoneyLootedHelper(arr+2, n-2, ans) + arr[0];
        ans[n] = max(a,b);
    }
    return ans[n];
}

int maxMoneyLooted_2(int *arr, int n){
    int *ans = new int[n+1];

    // initialise with -1
    for(int i = 0; i <= n; i++){
        ans[i] = -1;
    }

    return maxMoneyLootedHelper(arr, n, ans);
}

// dp
int maxMoneyLooted_3(int *arr, int n){
    int *ans = new int[n+1];

    ans[0] = arr[0];
    ans[1] = max(arr[0], arr[1]);

    for(int i = 2; i <= n; i++){
        int a = ans[i-1];
        int b = ans[i-2] + arr[i];
        ans[i] = max(a,b);
    }
    return ans[n];
}