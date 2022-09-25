#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> vec1;
    int i = 1;

    for(i = 1; i <= n; i++ ){
        if(i%2 != 0){
            vec1.push_back(i);
        }
    }
    vector<int> vec2;
    int count = 0;
    for(int j = 1; j <= n; j++){
        if(j%2 == 0){
            vec2.push_back(j);
        }
    }
    
    
    return 0;
}