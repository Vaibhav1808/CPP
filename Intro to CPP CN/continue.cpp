#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int i = 1;
    while(i < n){
        if(i == 8){
            i++;
            continue;
        }
        cout << i << endl;
        i++;
    }
    
    for(int j = 1; j < n; j++){
        if(j == 6){
            continue;
        }
        cout << j << endl;
    }
    return 0;
}