#include <bits/stdc++.h>
using namespace std;
class PriorityQueue{
    vector<int> pq;

    public:
    PriorityQueue(){
    }

    bool IsEmpty(){
        return pq.size() == 0;
    }

   int getSize(){
    return pq.size();
   }

   int getMin(){
    if(IsEmpty()){
        return 0;
    }
    return pq[0];
   }

   void insert(int element){
    pq.push_back(element);

    int childIndex = pq.size() - 1;
    while(childIndex > 0){
        int parentIndex = (childIndex - 1)/2;

        if(pq[childIndex] < pq[parentIndex]){
            int temp = pq[childIndex];
            pq[childIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
        }
        else{
            break;
        }
        childIndex = parentIndex;
        }
   }

    int removeMin(){
        if(IsEmpty()){
            return 0;
        }

        int ans  = pq[0];
        int lastIndex = pq.size()-1;

        pq[0] = pq[lastIndex];
        pq[lastIndex] = ans;
        pq.pop_back();

        int pi = 0;
        int lci = 2*pi+1;
        int rci = 2*pi+2;

        while(lci < pq.size()){
            int minIndex = pi;

            if(pq[lci] < pq[minIndex]){
                minIndex = lci;
            }

            if(rci < pq.size() and pq[rci] < pq[minIndex]){
                minIndex = rci;
            }

            if(pi == minIndex){
                break;
            }

            int temp = pq[minIndex];
            pq[minIndex] = pq[pi];
            pq[pi] = temp;

            pi = minIndex;
            lci = 2 * pi + 1;
            rci = 2 * pi + 2;
        }
        return ans;
    }
};
