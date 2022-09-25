#include <iostream>
using namespace std;

void print_1_to_N(int n){
    for(int i = 1; i <= n; i++){
        cout << i << endl;
    }
}

// void functions are those functiuons which do not return any value

int main(){
    int n;
    cin >> n;

    print_1_to_N(n);
    return 0;
}