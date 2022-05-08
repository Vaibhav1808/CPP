#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n; // n input
    int arr[n]; // static
    for(int i = 0;i < n;i++) {
        cin >> arr[i];  //input of array
    }
    int sum = 0;
    for(int i =0;i < n;i++){
        sum += arr[i];
        cout << arr[i] << " "; //output of array
    }
    cout <<endl << sum;
}