#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int x;
    	 cin >> x;
    	 
    	 if(x <= 300){
    	     cout << 3000 << endl;
    	 }
    	 else{
    	     cout << 10*x << endl;
    	 }
	}
	 
	return 0;
}