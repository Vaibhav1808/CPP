#include <bits/stdc++.h>
using namespace std;

int length(char input[]){
    int count = 0;
    for(int i = 0; input[i] != '\0'; i++){
        count++;
    }
    return count;
}

void trim(char input[]){
    int len = length(input);

    for(int i = 0; i < len; i++){
        if(input[i] == ' '){
            for(int j = i; j < len; j++){
                input[j] = input[j+1];
                
            }
            len--;
        }
    }

}

int main(){
    char input[100];
    cin.getline(input, 100);
    trim(input);
    cout << input;
    return 0;
}
