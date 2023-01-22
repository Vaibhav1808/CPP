#include <bits/stdc++.h>
using namespace std;


// brute force
int countStepsToOne(int n) {
	// Write your code here.
    if(n <= 1){
        return 0;
    }

    int a = countStepsToOne(n-1);
    int b = INT_MAX;
    int c = INT_MAX;

    if(n%2 == 0){
        b = countStepsToOne(n/2);
    }
    if(n%3 == 0){
        c = countStepsToOne(n/3);
    }

    return min(a, min(b,c)) + 1;
}

// memoisation

int minstepsHelper(int n, int *ans){
    // base case
    if(n <= 1){
        return 0;
    }

    // check if answer exists
    if(ans[n] != -1){
        return ans[n];
    }

    // calculate output
    int x = minstepsHelper(n-1, ans);
    int y = INT_MAX;
    int z = INT_MAX;

    if(n%2 == 0){
        y = minstepsHelper(n/2, ans);
    }

    if(n%3 == 0){
        z = minstepsHelper(n/3, ans);
    }

    int output = min(x, min(y,z)) + 1;

    // save output for future
    ans[n] = output;
    return ans[n];
}

int countStepsToOne_2(int n){
    int *ans = new int[n+1];

    for(int i = 0; i < n; i++){
        ans[i] = -1;  // initialise array with -1
    }

    return minstepsHelper(n, ans);
}

// dynamic programming
int countStepsToOne_3(int n){
    int *ans = new int[n+1];

    ans[0] = 0;
    ans[1] = 0;

    for(int i = 2; i <= n; i++){
        int a = ans[i-1];
      int b = INT_MAX;
      int c = INT_MAX;
      if (i% 2 == 0) {
        b = ans[i / 2];
		}
	    if(i% 3 == 0){
		c = ans[i/3];
	    }
	    ans[i] = min(a,min(b,c)) + 1;
        }
	return ans[n];
}
