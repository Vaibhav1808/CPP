#include <bits/stdc++.h>
using namespace std;


void heapSort(int arr[], int n) {
    // Write your code

    // build heap 
    for(int i = 1; i < n; i++){
        // up heapify
        int childIndex = i;
        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;
            
            if(arr[parentIndex] > arr[childIndex]){
                //swap
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
            }
            else{
                break;
            }

            childIndex = parentIndex;
        }
    }

    // Remove elements
    int size = n;
    while(size > 1){
      int temp = arr[0];
      arr[0] = arr[size - 1];
      arr[size - 1] = temp;

      size--;

      int pi = 0;
      int lci = 2 * pi + 1;
      int rci = 2 * pi + 2;

      while (lci < size) {
        int minIndex = pi;
        if (arr[pi] > arr[lci]) {
          minIndex = lci;
        }
        if (rci < size and arr[rci] < arr[minIndex]) {
          minIndex = rci;
        }
        if (minIndex == pi) {
          break;
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[pi];
        arr[pi] = temp;

        pi = minIndex;
        lci = 2 * pi + 1;
        rci = 2 * pi + 2;
      }
    }
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}