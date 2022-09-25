#include <iostream> 
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];
    int val = 1, s = 0, e = n-1;

    for(int i = 0; i < (n+1)/2; i++){
        arr[s] = val;
        val++;
        arr[e] = val;
        val++;
        s++;
        e--;
        if(s==e){
            arr[s] = n;
            break;
        }
    }
    for(int j = 0; j < n; j++){
        cout << arr[j] << ' ';
    }
    
    return 0;
}