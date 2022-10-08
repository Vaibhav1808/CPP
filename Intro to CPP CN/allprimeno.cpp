#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= i; j++){
            if(j == i){
                cout << j << endl;
            }
            else if(i % j == 0){
                break;
            }          
            
        }
    }
    
    return 0;
}




