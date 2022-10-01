#include <bits/stdc++.h>
using namespace std;

int c = 0;

int stringToNumber(char input[]){
    int n = strlen(input);

    if(input[0] == '\0'){
        return 0;
    }
     
    else{
        int a = input[0] - 48;
        c = a*pow(10, n-1) + c;
        stringToNumber(input+1);
        
        return c;
    }
    
    
}

int main()
{
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
    
    return 0;
}