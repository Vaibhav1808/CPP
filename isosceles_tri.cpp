#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int i = 1;
    while (i <= n){
        int j = 1;
        while(j <= n-i){
            cout << ' ';
            j++;
        }
        int k = 1;
        while(k <= i){
            cout << k;
            k++;
        }
        k = i-1;
        while(k >= 1){
            cout << k;
            k--;
        }
        cout << endl;
        i++;
    }
    return 0;
}