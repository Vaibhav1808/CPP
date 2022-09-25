#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
	cin >> t;
	for (int i=1; i<=t; i++){
	    int a, b, c;
	    cin >> a >> b >> c;
	    if((a==b && c>=a) || (b==c && a>=c) || (a==c && b>=a)){
	        cout << "Yes" << endl;
	    }
	    else{
	        cout << "No" << endl;
	    }
	}
    return 0;
}