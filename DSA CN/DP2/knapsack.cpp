#include <bits/stdc++.h>
using namespace std;

// recursion
int knapsack_1(int *weights, int *values, int n, int maxWeight){
    // base case
    if(n == 0 or maxWeight == 0){
        return 0;
    }

    // recursive calls
    if(maxWeight < weights[0]){
        return knapsack_1(weights+1, values+1, n-1, maxWeight);
    }

    else{
        int a = knapsack_1(weights+1, values+1,n-1,maxWeight);
        int b = knapsack_1(weights+1, values+1, n-1, maxWeight - weights[0]) + values[0];
        return max(a,b);
    }
}

// memoisation
int knapsackHelper(int *weights, int *values, int n, int maxWeight, int *ans){
    // base case
    if(n == 0 or maxWeight == 0){
        return 0;
    }

    // recursive calls
    if(maxWeight < weights[0]){
        ans[n] = knapsackHelper(weights+1, values+1, n-1, maxWeight,ans);
    }

    else{
        int a = knapsackHelper(weights+1, values+1,n-1,maxWeight,ans);
        int b = knapsackHelper(weights+1, values+1, n-1, maxWeight - weights[0], ans) + values[0];
        ans[n] = max(a,b);
    }
    return ans[n];
}

int knapsack_2(int *weights, int *values, int n, int maxWeight){
    int *ans = new int[n+1];

    for(int i = 0; i < n; i++){
        ans[i] = -1;  // initialise array with -1
    }

    return knapsackHelper(weights, values, n, maxWeight, ans);
}

// dp
int knapsack_3(int *weights, int *values, int n, int maxWeight){
    int **output = new int*[n+1];
    for(int i = 0; i <= n; i++){
        output[i] = new int[maxWeight + 1];
    }

    for(int i = 0; i <= n; i++){
        output[i][0] = 0;
    }

    for(int j = 0; j <= maxWeight; j++){
        output[0][j] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= maxWeight; j++){
            if(j < weights[n - i]){
                output[i][j] = output[i - 1][j];
            }
            else{
                int a = output[i-1][j];
                int b = output[i-1][j-weights[n-i]] + values[n-i];
                output[i][j] = max(a,b);
            }
        }
    }
    return output[n][maxWeight];
}