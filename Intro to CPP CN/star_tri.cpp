#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int i = 1;
    while(i <= n){
        int spaces = 1;
        while (spaces <= n-i){
            cout << ' ';
            spaces++;
        }
        int star = 1;
        while(star <= 2*i-1){
            cout << '*';
            star++;
        }
        cout << endl;
        i++;
    }
    return 0;
}