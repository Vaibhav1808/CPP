#include <bits/stdc++.h>
using namespace std;

void pairStar(char input[]){
    
    int len = strlen(input);
    
    if(input[0] == '\0' || input[1] == '\0'){
       return;
    }

    if(input[0] == input[1]){
        len = len++;
        for(int i = len + 1; i > 1; i--){
            input[i] = input[i-1];
        }
        input[1] = '*';
    }
    pairStar(input + 1);
}

int main()
{
    char input[100];
    cin.getline(input, 100);
    pairStar(input);
    cout << input << endl;
    return 0;
}