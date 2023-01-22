#include <bits/stdc++.h>
using namespace std;

// recursion
int minCostPathHelper_1(int **input, int n, int m, int x, int y){
     // base case
     if((x == m - 1) and (y == n - 1)){
        return input[x][y];
     }

     if(x >= m or y >= n){
        return INT_MAX;
     }

     int a = minCostPathHelper_1(input,n,m,x,y+1);
     int b = minCostPathHelper_1(input,n,m,x+1,y);
     int c = minCostPathHelper_1(input,n,m,x+1,y+1);

     return min(a,min(b,c)) + input[x][y];
}

int minCostPath_1(int **input, int n, int m){
    return minCostPathHelper_1(input,n,m,0,0);
}


// memoisation
int minCostPathHelper_2(int **input, int n, int m, int x, int y, int **ans){
    // base case
    if((x == m - 1) and (y == n - 1)){
        return input[x][y];
     }

     if(x >= m or y >= n){
        return INT_MAX;
     }

    if(ans[x][y] != -1){
        return ans[x][y];
    }

    int a = minCostPathHelper_2(input,n,m,x,y+1,ans);
    int b = minCostPathHelper_2(input,n,m,x+1,y,ans);
    int c = minCostPathHelper_2(input,n,m,x+1,y+1,ans);

    int output = min(a,min(b,c)) + input[x][y];
    ans[x][y] = output;
    return output;
}


int minCostPath_2(int **input, int n, int m){
    int **ans = new int*[m];
    for(int i = 0; i < m; i++){
        ans[i] = new int[n];
        for(int j = 0; j < n; j++){
            ans[i][j] == -1;
        }
    }

    return minCostPathHelper_2(input,n,m,0,0,ans);
}

// dynamic programming
int minCostPath_3(int **input, int n, int m){
    int **ans = new int*[m];
    for(int i = 0; i < m; i++){
        ans[i] = new int[n];
    }

    //last block
    ans[m-1][n-1] = input[m-1][n-1];

    for(int j = n - 2; j >= 0; j--){
        ans[m-1][j] = ans[m-1][j+1] + input[m-1][j];
    }

    for(int i = m - 2; i >= 0; i--){
        ans[i][n-1] = ans[i+1][n-1] + input[i][n-1];
    }

    for(int i = m-2; i >= 0; i--){
        for(int j = n-2; j >= 0; j--){
            ans[i][j] = min(ans[i][j+1] , min(ans[i+1][j+1] , ans[i+1][j])) + input[i][j];
        }
    }
    return ans[0][0];
}

int main(){
    int m, n;
    cin >> m >> n;

    int **input = new int*[m];
    for(int i = 0; i < m; i++){
        input[i] = new int[n];
        for(int j = 0; j < n; j++){
            cin >> input[i][j];
        }
    }
    cout << minCostPath_1(input,n,m) << endl;
    return 0;
}