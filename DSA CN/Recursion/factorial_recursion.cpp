#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        long long arr[n];
        for(int i = 0 ; i < n; i++){
            cin >> arr[i];
        }
        
        int arr1[n];
        int count = 1;
        int index = 0;
        sort(arr, arr+n);
        
        for(int i = 0; i < n-1; i++){
            if(arr[i] == arr[i+1]){
                count++;
            }
            else{
                arr1[index] = count;
                count = 1;
                index++;
            }
        }
        
        arr1[index] = count;
        int ans = 0;
        for(int i = 0; i <= index; i++){
            if(arr1[i] > 1){
                ans += int(arr1[i]*(arr1[i]-1)/float(2));
            }
        }
        cout << ans << endl;
    }
    return 0;
}