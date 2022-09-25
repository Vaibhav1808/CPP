#include <bits/stdc++.h>
using namespace std;

int main(){
    char str[100];
    cin >> str;

    char a , b;
    cin >> a;  // jo replace hoga
    cin >> b;  // jisse relace hoga

    int len = strlen(str);

    for(int i = 0; i < len; i++){
        if(str[i] == a){
            str[i] = b;
        }
    }
    cout << str;
    return 0;
}

