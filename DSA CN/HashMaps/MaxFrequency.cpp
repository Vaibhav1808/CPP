#include <iostream>
#include <unordered_map>
using namespace std;

int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int,int> ourmap;
    for(int i = 0; i < n; i++){
        if(ourmap.count(arr[i]) == 0){
            ourmap[arr[i]] == 1;
        }   
        else{
            ourmap[arr[i]]++;
        }
    }

    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(ourmap[max] < ourmap[arr[i]]){
            max = arr[i];
        } 
    }
    return max;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}