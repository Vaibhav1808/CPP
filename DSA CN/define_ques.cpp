#include <iostream>
using namespace std;

#define SQUARE(x) x*x

int main(){
    int x = 36 / SQUARE(6);  // 36/6*6 likha h ab ye math h phle divide hoga basic rule h 
    // 36 divide 6 equal to 6 hota h fir aage multiply 6 h toh answer 36 aaega. 
    cout << x;

    return 0;
}