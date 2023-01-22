#include <iostream>
#include <unordered_map>
using namespace std;

void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    unordered_map<int,int> ap;    
    for(int i = 0; i < n; i++){
        ap[arr1[i]]++;
    }

    for(int i = 0; i < m; i++){
        if(ap[arr2[i]] > 0){
            ap[arr2[i]]--;
            cout << arr2[i] << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}