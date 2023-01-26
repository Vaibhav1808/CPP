#include <bits/stdc++.h>
using namespace std;

// recursion
int minCount_1(int n){
    if(n <=3){
        return n;
    }

	int ans = n;
	for(int i = 1; i <= sqrt(n); i++){
          ans = min(ans, 1 + minCount_1(n - i * i));
        }
	return ans;
}

// memoisation
int minCountHelper(int n, int *ans){
    if(n <= 3){
		ans[n] = n;
        return ans[n];
	}

    if(ans[n] != -1){
	  return ans[n];
    }

    int result = n;
    for(int i = 1; i <= sqrt(n); i++){
          ans[n] = result = min(result, 1 + minCountHelper(n - i * i, ans));
        }
    return ans[n];
}

int minCount_2(int n){
    int *ans = new int[n+1];
    for(int i = 0; i <= n; i++){
        ans[i] = -1;
    }

    return minCountHelper(n, ans);
}

// dp
int minCount_3(int n){
    int *ans = new int[n+1];

    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;

    for(int i = 4; i <= n; i++){
        ans[i] = i;
        for(int j = 1; j <= sqrt(i); j++){
            ans[i] = min(ans[i], 1+ans[i-j*j]);
        }
    }

    return ans[n];
}

