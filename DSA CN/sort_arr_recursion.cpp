#include <bits/stdc++.h>
using namespace std;

bool is_sorted(int a[], int size){
    if(size == 0 || size == 1){
        return true;
    }
    if(a[0] > a[1]){
        return false;
    }
     bool small_sorted = is_sorted(a + 1, size - 1);
     return small_sorted;
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << is_sorted(arr, n);
}
