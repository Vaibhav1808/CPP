#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string, int> m;
    m["abc"] = 1;
    m["abc1"] = 2;
    m["abc2"] = 3;
    m["abc3"] = 4;
    m["abc4"] = 5;
    m["abc5"] = 6;

    unordered_map<string,int> :: iterator it = m.begin();

    while(it != m.end()){
        cout << "Key: " << it->first << " Value: " << it->second << endl;
        it++;
    }
}