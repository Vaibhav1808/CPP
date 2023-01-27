#include <bits/stdc++.h>
using namespace std;

// first method
bool isPowerofTwo_1(long long n){
        long long count = 0;
        while(n > 0){
            if((n & 1) == 1){
                count++;
            }
            n= n >> 1;
        }
        if(count == 1){
            return true;
        }
        else{
            return false;
        }
    }

// second method
bool isPowerofTwo(long long n){
    if(n == 0){
        return false;
    }
    if((n & (n-1)) == 0){
        return true;
    }
    return false;
}