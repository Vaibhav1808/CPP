#include <bits/stdc++.h>
using namespace std;

int countZero(int n){
   static int count = 0;
   if(n > 0){
    if(n % 10 == 0){
        count++;
    }
    countZero(n/10);
   }
   return count;
}

int main()
{
    int n;
    cin >> n;

    cout << countZero(n) << endl;
    return 0;
}