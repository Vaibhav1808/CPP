#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector <int>& prices){
    int max = INT_MIN;
    int min = INT_MAX;
    int i = 0;
    for(i = 0; i < prices.size(); i++){
        if(prices[i] < min){
            min = prices[i];
        }
    }
    int j = i + 1;
    for(j = i+1; j < prices.size() && j > i; j++){
        if(prices[j] > max){
            max = prices[j];
        }
    }
    if(prices[i] > prices[j]){
        return 0;
    }
    else{
        return max - min;
    }
    
}


int main()
{
    return 0;
}