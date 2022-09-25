#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        int arr[n];
        for(int j =0; j < n; j++){
            cin >> j;
        }

        sort(arr, arr+n);
        int max_1 = 0 , max_2 = 0;
        for(int k = 0; k < n-1; k++){
            if(arr[k] == arr[k+1]){
                max_2++;
            }
            else{
                if(max_2 > max_1){
                    max_1 = max_2;
                }
                max_2 = 0;
            }
        }
        if(max_2 > max_1){
            max_1 = max_2;
        }
        int max_3 = 0, count = 0;

        for(int i = 0; i < n-1; i++){
            if(arr[i] == arr[i+1]){
                max_3++;
            }
            else{
                if(max_3 == max_1){
                    count++;
                }
                max_3 = 0;
            }
        }
        if(max_3 == max_1){
            count++;
        }
        
        if(count == 1){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
    return 0;
}