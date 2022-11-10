#include <bits/stdc++.h> 
using namespace std;

void solve(stack<int>&st, int N, int count){
    if(count == N/2){
        st.pop();
        return;
    }
    int ans = st.top();
    st.pop();
    solve(st, N, count + 1);
    st.push(ans);
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   int count = 0;
   solve(inputStack, N, count);
}