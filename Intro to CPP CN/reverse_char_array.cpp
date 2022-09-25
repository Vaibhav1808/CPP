#include <bits/stdc++.h>
using namespace std;

int length(char input[]){
    int count = 0;
    for(int i = 0; input[i] != '\0'; i++){
        count++;
    }
    return count;
}

void reverse(char input[]){
    int len =length (input);
    int i = 0;
    int j = len - 1;

    while(i < j){
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        i++;
        j--;
    }
}

int main(){
    char input[100];
    cin.getline(input, 100);
    reverse(input);
    cout << input;
    return 0;
}