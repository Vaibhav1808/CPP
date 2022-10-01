#include <bits/stdc++.h>
using namespace std;

bool check_num(int a[], int n, int x){
    if(a[0] == x){
        return true;
    }
    return check_num(a+1, n-1,x);
}               

int main(){
    int n, x;
    cin >> n;

    int arr[n];
    for(int i =0; i < n; i++){
        cin >> arr[i];
    }

    cin >> x;
    cout << check_num(arr, n, x);
    return 0;
}