#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int s = 0, e = n;
    int ans;
    cin >> ans;

    while(s <= e){
        int mid = (s+e)/2;

        if(arr[mid] == ans){
            cout << mid;
            break;
        }
        else if(arr[mid] > ans){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    if(s > e){
        cout << -1;
    }
    return 0;
}