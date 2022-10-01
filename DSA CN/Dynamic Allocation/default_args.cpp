#include <bits/stdc++.h>
using namespace std;

int sum(int a[], int size, int s = 0){
    int ans = 0;
    for(int i = s; i < size; i++){
        ans += a[i];
    }
    return ans;
}


int main()
{
    int n;
    cin >> n;
    
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << sum(a, n);



    return 0;
}