#include <bits/stdc++.h>
using namespace std;

int sum(int a[], int size){
    if(size <= 0){
        return 0;
    }

    int small_Sum = sum(a, size - 1);
    return small_Sum + a[size-1];
}


int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << sum(arr, n);
    return 0;
}