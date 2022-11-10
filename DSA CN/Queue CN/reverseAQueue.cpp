#include <bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int> &input) {
	// Write your code here
    if(input.empty()){
        return;
    }
    int ans = input.front();
    input.pop();
    reverseQueue(input);
    input.push(ans);
}