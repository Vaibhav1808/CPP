#include <bits/stdc++.h>
using namespace std;

double gpSum(int k){
    if(k == 0){
        return 1;
    } 
    
    double small_Output = gpSum(k-1);
    return small_Output + 1/(double)pow(2, k);

}

int main()
{
    int n;
    cin >> n;

    cout << gpSum(n) << endl;
    
    return 0;
}