#include <bits/stdc++.h>
using namespace std;

int main() {
	int tstcse;
	cin>>tstcse;
	for(int i = 0; i < tstcse; i++){
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	   sort(arr,arr+n);
	   int count = 0;
	   for(int i = 0; i < n-1; i++){
	       if(arr[i] != arr[i+1] && arr[i] != 0) {
	           count++;
	       }
	   }
	   if(arr[n-1] != 0) {
	       cout << count+1 << endl;
	   }
	   else {
	       cout << "0" << endl;
	   }
	}
	return 0;
}
