#include <iostream>
using namespace std;

int main(){
    int n, n_1 = 0, n_2 = 1, n_3;
    cin >> n;

    cout << n_1 << ' ';
    cout << n_2 << ' ';
    
    for(int i = 0; i < n; i++){
        n_3 = n_1 + n_2;
        cout << n_3 << " ";
        n_1 = n_2;
        n_2 = n_3;

    }
    return 0;
}