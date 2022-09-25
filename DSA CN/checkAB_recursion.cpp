#include <bits/stdc++.h>
using namespace std;

bool checkAB(char input[]){
    if(input[0] == '\0'){
        return 0;
    }
    if(input[0] == 'b'){
        return false;
    }
    
    if(input[0] == 'a' and (input[1] == 'a' or (input[1] == 'b' and input[2] == 'b') or input[1] == '\0')){
        checkAB(input + 1);
        return true;
        
    }
    else if(input[0] == 'b' and input[1] == 'b' and (input[2] == 'a' or input[2] == '\0')){
        checkAB(input + 1);
        return true;
        
    }
    
    else{
        return false;
    }
}



int main(){
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}