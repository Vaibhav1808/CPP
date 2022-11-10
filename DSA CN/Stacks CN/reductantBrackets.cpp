#include<bits/stdc++.h>
using namespace std;

bool checkRedundantBrackets(string expression){
	// Write your code here
    stack<char> stk;
    
    int i = 0;
    int count = 0;
    
    for(int i = 0; i < expression.size(); i++){
        if(expression[i] != ')'){
            stk.push(expression[i]);
        }
        
        else{
            while(!stk.empty() && stk.top() != '('){
                stk.pop();
                count++;
            }
            
            if(stk.empty()){
                return true;
            }
            
            stk.pop();
            
            if(count <= 1){
           	  return true;
        	}
        }
        count = 0;
    }
    return false;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}