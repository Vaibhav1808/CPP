#include <bits/stdc++.h>
using namespace std;

// recursively
int editDistance_1(string s1, string s2) {
	// base case
    if(s1.size() == 0 or s2.size() == 0){
        return max(s1.size(), s2.size());
    }

    // recursive calls
    int x, y, z, t;
    if(s1[0] == s2[0]){
        x = editDistance_1(s1.substr(1), s2.substr(1));
        return x;
    }

    else{
        // insert method
        y = 1 + editDistance_1(s1.substr(1), s2);

        // delete method
        z = 1 + editDistance_1(s1, s2.substr(1));

        //replace method
        t = 1 + editDistance_1(s1.substr(1), s2.substr(1));

        return min(y,min(z,t));
    }
}

//memoisation
int editDistanceHelper(string s1, string s2, int **output){
    int m = s1.size();
    int n = s2.size();

    // base case
    if(s1.size() == 0 or s2.size() == 0){
        return max(s1.size(), s2.size());
    }

    // check if ans already exists
    if(output[m][n] != -1){
        return output[m][n];
    }

    int ans;
    int t, y, z;

    if(s1[0] == s2[0]){
        ans = editDistanceHelper(s1.substr(1), s2.substr(1), output);
    }

    else{
        // insert method
        y = 1 + editDistanceHelper(s1.substr(1), s2, output);

        // delete method
        z = 1 + editDistanceHelper(s1, s2.substr(1), output);

        //replace method
        t = 1 + editDistanceHelper(s1.substr(1), s2.substr(1), output);

        ans = min(y,min(z,t));
    }

    output[m][n] = ans;
    return ans;
}

int editDistance_2(string s1, string s2){
    int m = s1.size();
    int n = s2.size();

    // initialise with -1
    int **output = new int*[m+1];
    for(int i = 0; i <= m; i++){
        output[i] = new int[n+1];
        for(int j = 0; j <= n; j++){
            output[i][j] = -1;
        }
    }
    return editDistanceHelper(s1, s2, output);
}

// dp
int editDistance_3(string s1, string s2){
    int m = s1.size();
    int n = s2.size();

    int **output = new int*[m+1];
    for(int i = 0; i <= m; i++){
        output[i] = new int[n+1];
    }

    // fill first row
    for(int j = 0; j <= n; j++){
        output[0][j] = j;
    }

    // fill first column
    for(int i = 0; i <= m; i++){
        output[i][0] = i;
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
             // check if first char matches
            if(s1[m-i] == s2[n-j]){
                output[i][j] = output[i-1][j-1];
            }
            else{
                int a = 1 + output[i-1][j];
                int b = 1 + output[i][j-1];
                int c = 1 + output[i-1][j-1];
                output[i][j] = min(a,min(b,c));
            }
        }
    }
    return output[m][n];
}