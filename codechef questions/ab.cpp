#include <iostream>
using namespace std;

int main() {
    int x;
        cin >> x;
        
        while(x > 0){
            if(x%10 == 7){
                cout << "Yes" << endl;
                break;
            }
            x = x/10;
        }
        cout << "No" << endl;
	return 0;
}
