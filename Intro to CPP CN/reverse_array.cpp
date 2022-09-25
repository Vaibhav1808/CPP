#include <iostream>
using namespace std;

void PrintArray(int input[], int n){
    for(int i = 0; i < n; i++){
        cout << input[i] << " ";
    }
    cout << endl;
}

void reverse(int input[], int n){
    int i = 0, j = n-1;
    while(i < j){
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        i++;
        j--;
    }
}

int main(){
        int a = 10;
        int b[5] = {1 , 2 , 3 , 4 , 5};
        reverse(b , 5);
        PrintArray(b , 5);
        return 0;
    }