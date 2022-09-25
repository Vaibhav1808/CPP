#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int max = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    int sec_max = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > sec_max && arr[i] != max){
            sec_max = arr[i];
        }
    }
    cout << sec_max;
    return 0;
}