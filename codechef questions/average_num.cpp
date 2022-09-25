#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int n , k , v;
        cin >> n >> k >> v;

        int arr[n];
        for(int j = 0; j < n; j++){
            cin >> arr[j];
        } 
        int sum = 0;
        for(int k = 0; k < n; k++){
            sum = sum + arr[k];
        }

        int x = v*(n+k);

        if(sum > x || (x - sum) % k != 0){
            cout << -1 << endl;            
        }
        else{
            int y = (x - sum)/k;
            cout << y << endl;
        }

    }

    return 0;
}