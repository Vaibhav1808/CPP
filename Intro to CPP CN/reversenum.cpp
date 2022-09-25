#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    int res = 0;
    while(num != 0){
        int rev = num % 10;
        res = res*10+rev;
        num = num / 10;
    }
    cout << res;
    return 0;
}
