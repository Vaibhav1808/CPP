#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans[n];
    int index = 0;
    
    for(int i = 0; i < n; i++){
       int k = 1;
       for(int j = 0; j < n; j++){
        if(arr[j] == arr[i] && j != i){
            k++;
        }
       }
        ans[index] = k;
        index++;
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] <<" ";
    }

    return 0;
}