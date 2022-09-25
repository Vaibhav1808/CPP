#include <iostream>
using namespace std;

int main(){
    
    int s,e,w;
    cin >> s;
    cin >> e;
    cin >> w;

    for(int i = s; i <= e; i=i+w){
        
        float c = (5*(i-32))/9;
        cout << i << '\t' << c << endl ;
    }
    return 0;
}