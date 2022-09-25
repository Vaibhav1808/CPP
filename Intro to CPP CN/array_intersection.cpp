#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int i , j;

    int arr[n];
    for( i = 0; i < n; i++){
        cin >> arr[i];
    }

    int m;
    cin >> m;
    int arr_1[m];
    for(j = 0; j < m; j++){
        cin >> arr_1[j];
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(arr[i] == arr_1[j]){
                cout << arr[i] << " ";
                arr_1[j] = INT_MIN;
            }
        }
    }

    return 0;
}