#include <bits/stdc++.h>
using namespace std;

int main(){
    char str[100];
    int len;
    int flag = 0;

    cin >> str;

    len = strlen(str);
    for(int i = 0; i < len; i++){
        if(str[i] != str[len-i-1]){
            flag = 1;
            break;
        }
    }
    if(flag){
        cout << "False";
    }
    else{
        cout << "True";
    }
    return 0;
}