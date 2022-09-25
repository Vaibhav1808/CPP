#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int w, x, y, z;
	    cin >> w >> x >> y >> z;
	    int d = x+y;
	    int e = y+z;
	    int f = x+z;
	    int g = x+y+z;
	    if(w == x || w == y || w == z || w == d || w == e || w == f || w == g){
	        cout << "yes" << endl;
	    }
	    else{
	        cout << "no" << endl;
	    }
	}
	return 0;
}
