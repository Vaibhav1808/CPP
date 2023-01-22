#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string,int> ourmap;
    // insert
    pair<string, int> p("abc", 1);
    ourmap.insert(p);

    ourmap["def"] = 2;    //another way to insert

    // find or access
    cout << ourmap["abc"] << endl;
    cout << ourmap.at("abc") << endl;

    // check presence
    if(ourmap.count("ghi") > 0){
        cout << "ghi is present" << endl;
    }

    // size function
    cout << ourmap.size() << endl;

    // erase
    ourmap.erase("abc");
}