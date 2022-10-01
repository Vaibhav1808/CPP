#include <bits/stdc++.h>
using namespace std;

char keys[10][5]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int keypad(int num, string output[]){
    if(num == 0){
        output[0] = "";
        return 1;
    }

    int n = num%10;
    num = num/10;

    int smallOutputSize = keypad(num, output);

    string s[smallOutputSize];
    for(int i = 0; i < smallOutputSize; i++){
        s[i] = output[i];
    }

    int j = 0, ans = 0;
    while(keys[n][j] != '\0'){
        for(int i = 0; i < smallOutputSize; i++){
            output[i+ans] = s[i] + keys[n][j];
        }
        ans = ans + smallOutputSize;
        j++;
    }
    return ans;
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}