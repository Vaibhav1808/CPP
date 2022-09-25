#include <bits/stdc++.h>
using namespace std;
int gap(vector<int> &v)
{
    int ele;
    int n;
    int e, d;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        v.push_back(ele);
    }
    sort(v.begin(), v.end());
    for (auto x : v)
    {
        for (int i = 0; i < n; i++)
        {
             d = v.front()++;
        }
        for (int i = 0; i < n; i++)
        {
             e = v.back()--;
           
        }
    }
    return e - d;
}
