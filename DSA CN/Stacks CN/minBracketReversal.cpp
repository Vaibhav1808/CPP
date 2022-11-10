#include <bits/stdc++.h>
using namespace std;

int countBracketReversals(string input) {
	// Write your code here

    // odd pe -1 
    if(input.length() % 2 != 0){
        return -1;
    }
    
    stack<char>stk;
    for(int i = 0; i < input.length(); i++){
        char ch = input[i];
        
        // open bracket push krte chalo  
        if(ch == '{'){
            stk.push(ch);
        }
        // saath saath close mile toh usko check krte chalo
        else{
            // agar uska pair saath pda top pe usse hataao
            if(!stk.empty() && stk.top() == '{'){
                stk.pop();
            }
            // nhi toh close waala push kro
            else{
                stk.push(ch);
            }
        }
    }
    // ab stack mai bss non valid bche unko valid krna hai
    int a = 0, b = 0;
    while(!stk.empty()){
        // a = count of {
        // b = count of }
        if(stk.top() == '{'){
            a++;
        }
        else{
            b++;
        }
        stk.pop();
    }
    // asapp answer nikalo
    int ans = (a+1)/2 + (b+1)/2;
    
    return ans;
}