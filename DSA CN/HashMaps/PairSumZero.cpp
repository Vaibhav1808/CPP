#include <iostream>
using namespace std;

#include <unordered_map>

int pairSum(int *arr, int n) {
	// Write your code here
	unordered_map<int,int> m;
	int count = 0;
	for(int i = 0; i < n; i++){
		
		if(m.find(0-arr[i]) != m.end()){
			count += m[-arr[i]];
		}
		m[arr[i]]++;
	}
	return count;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}