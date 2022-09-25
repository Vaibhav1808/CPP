#include <iostream>
using namespace std;

/*int main(){
    char c;
    cin >> c;
    int count = 0;

    while(c != '$'){
        count++;
        cin >> c;
    }

    cout << count << endl;
    return 0;
} */

// we came to know that cin ignores spaces tabs etc.
// so if we want to count spaces , tabs as well we use cin.get(). It also counts enter.

int main(){
    char c;
    c = cin.get();
    int count = 0;

    while(c != '$'){
        count++;
        c = cin.get();
    }
    cout << count << endl;

    return 0;
}