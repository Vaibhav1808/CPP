#include <vector>
using namespace std;

class PriorityQueue {
    // Declare the data members here
    vector<int> pq;


   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);

        int childIndex = pq.size()-1;
        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;

            if(pq[childIndex] > pq[parentIndex]){
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(isEmpty()){
            return 0;
        }

        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(isEmpty()){
            return 0;
        }

        int ans = pq[0];
        int lastIndex = pq.size() - 1 ;

        pq[0] = pq[lastIndex];
        pq[lastIndex] = ans;
        pq.pop_back();

        int pi = 0;
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;

        while(lci < pq.size()){
            int maxIndex = pi;
            if(pq[lci] > pq[maxIndex]){
                maxIndex = lci;
            }

            if(rci < pq.size() and pq[rci] > pq[pi]){
                maxIndex = rci;
            }

            if(pi == maxIndex){
                break;
            }

            int temp = pq[maxIndex];
            pq[maxIndex] = pq[pi];
            pq[pi] = temp;

            // pi = maxIndex;
            // lci = 2*pi+1;
            // rci = 2*pi+2;

        }
        return ans;
    }

    int getSize() {
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size() == 0;
    }
};