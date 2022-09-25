#include <iostream>
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
    bool find = true;
    for(int i = 0; i < n; i++){
        if(arr[i] == x){
            cout << i;
            find = true;
            break;
        }
        else{
            find = false;
        }
    }
    if(!find){
        cout << -1;
    }
    return 0;
}