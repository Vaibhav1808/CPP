#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    int maxT, maxN, sumN;
	    cin >> maxT >> maxN >> sumN;
	    
	    int x = sumN/maxN;
	    if(x >= maxT){
	        cout << maxT*maxN*maxN << endl;
	    }
	    else{
	        if(x*maxN == sumN){
	            cout << (x*maxN*maxN) << endl;
	        }
	        else if(x*maxN<sumN){
	            int y = sumN-(x*maxN);
	            cout << (x*maxN*maxN)+(y*y) << endl;
	        }
	    }
	}
	return 0;
}
