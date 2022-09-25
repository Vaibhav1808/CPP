#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    
    int** p = new int*[10];
    for(int i = 0; i < 10; i++){
        p[i] = new int[20];
        for(int j = 0; j < n; j++){
            cin >> p[i][j];
        }
    }
    
    for(int i = 0; i < m; i++){
        delete [] p[i];
    }
    delete [] p;
    
    return 0;
}