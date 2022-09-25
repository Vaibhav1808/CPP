#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int m;
    cin >> m;

    int arr_1[m];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int sum[n];
    int k = n-1;
    int x = m-1;
    int y = n-1;
    int carry = 0, z = 0;

    while(x >= 0){
        z = arr[k] + arr[x] + carry;
        sum[y] = z % 10;
        carry = z / 10;

        y--;
        x--;
        k--;
    }
    while(k >= 0){
        z = arr[k] + carry;
        sum[y] = z % 10;
        carry = z / 10;

        k--;
        y--;
    }

    int ans = 0;
    if(carry){
        ans = 10;
    }
    for (int i = 0; i <= n - 1; i++){
        ans += sum[i];
        ans *= 10;
    }

    cout << ans / 10;

    return 0;
}