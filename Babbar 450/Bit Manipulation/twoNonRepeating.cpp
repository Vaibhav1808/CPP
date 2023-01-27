/************************************ Contributed by Vaibhav ***************************************************************/
#include <bits/stdc++.h>
using namespace std;

vector<int> NumbersOccurringOnce(vector<int> nums){

        // creating a vector which will store the desired elements
        vector<int> ans;

        // calculating the number which will be XOR of desired numbers
        int a = nums[0];
        for(int i = 1; i < nums.size(); i++){
            a = a ^ nums[i];
        }

        // finding rightMost Set Bit
        int rightMostSetBit = a & ~(a-1);

        // seperating out the two numbers
        int x = 0;
        int y = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & rightMostSetBit){
                x = x ^ nums[i];
            }
            else{
                y = y ^ nums[i];
            }
        }

        ans.push_back(x);
        ans.push_back(y);
        // returning required nums in sorted order
        sort(ans.begin(), ans.end());
        return ans;
    }
