#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int x;
    cin >> x;

    int count = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(arr[i] + arr[j] + arr[k] == x && i != j && j != k && i != k){
                count++;
                }
            }
        }
    }
    cout << count/6;

    return 0;
}