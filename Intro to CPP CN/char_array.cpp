#include <bits/stdc++.h>
using namespace std;

char ToLower(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}


void Reverse(char name[], int n){
    int s =0;
    int e = n-1;

    while(s < e){
        swap(name[s++], name[e--]);
    }
}


int getlength(char name[]){
    int count = 0;
    for(int i = 0; name[i] != '\0'; i++){
        count++;
    }
    return count;
}

int main(){
    char name[100];
    cin >> name;

    cout << getlength(name) << endl;
    int len = getlength(name);
    Reverse(name, len);
    cout << name;

    return 0;
}