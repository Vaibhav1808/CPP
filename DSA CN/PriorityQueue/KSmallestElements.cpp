#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    priority_queue<int> pq;

    // push k elements in pq
    for(int i = 0; i < k; i++){
        pq.push(arr[i]);
    }

    // add min elements in heap
    for(int i = k; i < n; i++){
        if(pq.top() > arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    // convert heap to vector
    vector<int> ans;
    while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
    }
    return ans;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    delete[] input;
}