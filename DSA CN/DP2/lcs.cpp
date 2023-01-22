#include <bits/stdc++.h>
using namespace std;


// recursively
int lcs_1(string s , string t){
    // base case
    if(s.size() == 0 or t.size() == 0){
        return 0;
    }
    // recursive calls
    if(s[0] == t[0]){
        return 1 + lcs_1(s.substr(1), t.substr(1));
    }

    else{
        int a = lcs_1(s.substr(1), t);
        int b = lcs_1(s, t.substr(1));
        int c = lcs_1(s.substr(1), t.substr(1));
        return max(a, max(b,c));
    }
}

//memoisation
int lcsHelper(string s, string t, int** output){

    int m = s.size();
    int n = t.size();

    // base case
    if(s.size() == 0 or t.size() == 0){
        return 0;
    }

    // check if ans already exists
    if(output[m][n] != -1){
        return output[m][n];
    }

    int ans;

    // recursive calls
    if(s[0] == t[0]){
        ans =  1 + lcsHelper(s.substr(1), t.substr(1), output);
    }

    else{
        int a = lcsHelper(s.substr(1), t, output);
        int b = lcsHelper(s, t.substr(1), output);
        int c = lcsHelper(s.substr(1), t.substr(1), output);
        ans = max(a, max(b,c));
    }

    output[m][n] = ans;
    return ans;
}

int lcs_2(string s, string t){
    int m = s.size();
    int n = t.size();

    // initialise with -1
    int **output = new int*[m+1];
    for(int i = 0; i <= m; i++){
        output[i] = new int[n+1];
        for(int j = 0; j <= n; j++){
            output[i][j] = -1;
        }
    }
    return lcsHelper(s,t,output);
}

//dp
int lcs_3(string s, string t){
    int m = s.size();
    int n = t.size();

    int **output = new int*[m+1];
    for(int i = 0; i <= m; i++){
        output[i] = new int[n+1];
    }

    // fill first row
    for(int j = 0; j <= n; j++){
        output[0][j] = 0;
    }

    // fill first column
    for(int i = 0; i <= m; i++){
        output[i][0] = 0;
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; i++){
            // check if first char matches
            if(s[m-i] == t[n-j]){
                output[i][j] = 1 + output[i-1][j-1];
            }
            else{
                int a = output[i-1][j];
                int b = output[i][j-1];
                int c = output[i-1][j-1];
                output[i][j] = max(a,max(b,c));
            }
        }
    }
    return output[m][n];
}

