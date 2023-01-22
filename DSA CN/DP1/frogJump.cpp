#include <bits/stdc++.h>
using namespace std;

//recursion
int frogJump_1(int n, vector<int> &height){
    // base case
    if(n == 0){
        return 0;
    }
    int a = frogJump_1(n-1, height) +abs(height[n] - height[n-1]);
    int b = INT_MAX;
    if(n >= 2){
        b = frogJump_1(n-2, height) + abs(height[n] - height[n-2]);
    }
    return min(a,b);
}

// dp solution
int frogJump_2(int n, vector<int> &height){
    vector<int> dp(n+1, -1);

    //base case
    if(n == 0){
        return 0;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int a = frogJump_1(n-1, height) +abs(height[n] - height[n-1]);
    int b = INT_MAX;
    if(n >= 2){
        b = frogJump_1(n-2, height) + abs(height[n] - height[n-2]);
    }

    return dp[n] = min(a, b);

}