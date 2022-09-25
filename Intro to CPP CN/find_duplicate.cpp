#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int j = 0; j < n; j++){
            int count = 1;
            for(int k = j+1; k < n; k++){
                if(arr[j] == arr[k]){
                    count++;
                    arr[k] = 1;
                }
            }
            if(count != 1){
                cout << arr[j] << " ";
            }
        
    }
    return 0;
}