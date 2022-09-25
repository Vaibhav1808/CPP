#include <bits/stdc++.h>
using namespace std;

// int partition(int input[], int n){
//     int s = 0;
//     int e = n-1;
//     int count = 0;
//     int pivot = input[s];

//     for(int i = s+1; i <= e; i++){
//         if(input[i] <= pivot){
//             count++;
//         }
//     }
//     int index = s + count;
//     swap(input[index], input[s]);

//     int i = s, j = e;
//     while(i < index && j > index){
//         while(input[i] <= pivot){
//             i++;
//         }
//         while(input[j] > pivot){
//             j--;
//         }
//         if(i < index && j > index){
//             swap(input[i++], input[j--]);
//         }
//     }
//     return index;
// }


void quickSort(int input[], int n){
    // int s = 0;
    // int e = n-1;

    if(n < 2){
        return;
    }

    // if(s < e){
        //int pivot = partition(input, n);

    int count = 0;
    for(int i = 1; i < n; i++){
        if(input[0] >= input[i]){
            count++;
        }
    }
    swap(input[0] , input[count]);

    int i = 0, j = n-1;
    while(i < count && j > count){
        while(input[i] <= input[count]){
            i++;
        }
        while(input[j] > input[count]){
            j--;
        }
        if(input[i] > input[count] && input[j] <= input[count]){
            swap(input[i++], input[j--]);
        }
    }
    quickSort(input, count);
    quickSort(input+count+1, n-count-1);
    // quickSort(input, pivot);
    // quickSort(input+pivot+1, n-pivot-1);
    }
// }


int main(){

    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

    return 0;
}
