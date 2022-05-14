#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int n_1 = (n+1)/2;
    int n_2 = n_1-1;

    int i = 1;
    while(i <= n_1){
        int spaces = 1;
        while (spaces <= n_1-i){
            cout << ' ';
            spaces++;
        }
        int star = 1;
        while(star <= 2*i-1){
            cout << '*';
            star++;
        }
    int i = n_2;
    while(i >= 1){
        while(spaces <= n_2){
            cout << ' ';
            spaces++;
        }
        while(star <= 2*i-1){
            cout << '*';
            star++;
        }
        i--;
    }
        cout << endl;
        i++;
    }
    return 0;
}