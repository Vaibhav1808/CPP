#include <bits/stdc++.h>
using namespace std;


bool isBalanced(string expression){

	stack<char> s;
    
    int i = 0;
	while(i < s.size()){
		if (expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
			s.push(expression[i]);
		} 
        else{
			if(s.empty()) {
				return false;
			}

			if(expression[i] == ')'){
				char ans = s.top();
				s.pop();

				if(ans != '('){
					return false;
				}
			}

			if(expression[i] == '}'){
				char ans = s.top();
				s.pop();
				if (ans != '{') {
					return false;
				}
			}

			if (expression[i] == ']'){
				char ans = s.top();
				s.pop();
				if (ans != '[') {
					return false;
				}
			}
		}
	}
	return s.empty();
}