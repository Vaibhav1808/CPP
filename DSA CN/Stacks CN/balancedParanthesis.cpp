#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string expression)
{
    // Write your code here.
    stack<char> stk;
    for(int i = 0; i < expression.length(); i++){
        char ch = expression[i];
        if(ch == '(' || ch == '[' || ch == '{'){
            stk.push(ch);
        }
        else{
            if(!stk.empty()){
                char top = stk.top();
                if((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{')){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(stk.empty()){
        return true;
    }
    return false;
}