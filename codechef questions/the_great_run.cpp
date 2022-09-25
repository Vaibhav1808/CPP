#include <bits/stdc++.h>
using namespace std;

int main(){
    int tstcse;
    cin >> tstcse;
    for(int z = 0; z < tstcse; z++){
    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int sum = 0;
    int ans = 0;
    for(int i = 0; i < n-k+1; i++){
        sum = 0;
        for(int j = i; j < i+k; j++){
            sum = sum + arr[j];
        }
        if(sum > ans){
            ans = sum;
        }
    }
    cout << ans << endl;
    }
    return 0;
}