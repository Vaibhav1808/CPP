#include <bits/stdc++.h>
using namespace std;


void Substring(char input[]){
    for(int i = 0; i < strlen(input); i++){
        for(int j = i; j < strlen(input); j++){
            
            for(int k = i; k <= j; k++){
                cout << input[k];
            }
            cout << endl;
        }
    }
}

int main(){
    char input[100];
    cin >> input;
    cout << endl;;
    Substring(input);

    return 0;
}