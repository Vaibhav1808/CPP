#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            count_0++;
        }
        else if(arr[i] == 1){
            count_1++;
        }
        else{
            count_2++;
        }
    }

    for(int k = 0; k < count_0; k++){
        arr[k] = 0;
    }
    for(int k = count_0 ; k < count_0 + count_1; k++){
        arr[k] = 1;
    }
    for(int k = count_0 + count_1; k < count_0 + count_1 + count_2; k++){
        arr[k] = 2;
    }

    for(int k = 0; k < n; k++){
        cout << arr[k] << " ";
    }

    return 0;
}