#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int arr[n];
        int max = arr[0];

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        for(int i = 1; i < n; i++){
            if(arr[i] > max){
                max = arr[i];
            }
        }
        int min = arr[0];
        for(int i = 1; i < n; i++){
            if(arr[i] < min){
                min = arr[i];
            }
        }

        int gcd;
        for(int i = 1; i <=  max; i++){
            if(min % i == 0 && max % i == 0){
                gcd = i;
            }
        }

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum = sum + arr[i];
        }

        int ans = sum - max + gcd;
        cout << ans << endl;
    }
    return 0;
}