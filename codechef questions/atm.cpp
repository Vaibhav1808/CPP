#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; 
	cin >> t;
	
	while(t--){
	    int n , k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    int money = k;
	    for(int i = 0; i < n; i++){
	        if(arr[i] <=money){
	            cout << 1;
	            money = money-arr[i];
	        }
	        else{
	            cout << 0;
	        }
	    }
	    cout << endl;
	}
	return 0;
}