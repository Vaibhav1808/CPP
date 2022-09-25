#include <iostream>
using namespace std;

int main(){
    int x ;
    cin >> x;
    int ap;
    int count = 0;
    for(int i = 1; count < x; i++){
        ap = 3*i + 2;
        if(ap % 4 != 0){
            cout << ap << " ";
            count++;
        }
    }
    return 0;
}