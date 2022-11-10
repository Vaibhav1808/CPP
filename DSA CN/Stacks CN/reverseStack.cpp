#include <bits/stdc++.h>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
	if(input.empty() or input.size() == 1){
        return;
    }
    
    while(input.empty() == false){
        int a = input.top();
        extra.push(a);
        input.pop(); 
    }
    input = extra;
}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}