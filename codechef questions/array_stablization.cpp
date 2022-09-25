#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }    

    sort(arr, arr+n);

    int min = arr[0];
    
    for(int i = 0; i < n; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }

    int max, secmax;
   
    max = arr[0];
    for(int i = 0; i < n; i++){
        if(max < arr[i]){
            max = arr[i];
        }  
    }
    secmax = arr[0];
    for(int i = 0; i < n; i++)
    {
        if(secmax < arr[i]){
            if(arr[i] != max)
                secmax = arr[i];
        }
    }

    int ans = secmax - min;
    cout << ans;
    return 0;
}