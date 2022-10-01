#include <bits/stdc++.h>
using namespace std;

void removeX(char input[]){
    if(input[0] == '\0'){
        return;
    }
    
    removeX(input + 1);

    if(input[0] == 'x'){
        strcpy(input, input+1);
        removeX(input);
    }
}

int main()
{
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
    
    return 0;
}
