#include <bits/stdc++.h>
using namespace std;

void removeConsecutiveDuplicates(char s[]){
    if(s[0] == '\0' || s[1] == '\0'){
        return;
    }

    if(s[0] == s[1]){
        int i = 0;
        for(int i = 0; s[i] != '\0'; i++){
            s[i] = s[i + 1];
        }
        removeConsecutiveDuplicates(s);
    }
    removeConsecutiveDuplicates(s+1);
}

int main(){
    
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;

    return 0;
}