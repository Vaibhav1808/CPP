#include <bits/stdc++.h> 
using namespace std;
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    if(myStack.empty()){
        myStack.push(x);
        return myStack;
    }
    int ans = myStack.top();
    myStack.pop();
    
    pushAtBottom(myStack,x);
    myStack.push(ans);
    return myStack;
}
