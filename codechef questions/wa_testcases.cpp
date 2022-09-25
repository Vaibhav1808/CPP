#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> vec;
        int ele;
        for(int i = 0; i < n; i++){
            cin >> ele;
            vec.push_back(ele);
        }

        string v;
        cin >> v;

        vector<int> vec2;

        for(int i = 0; i < v.size(); i++){
            if(v[i] == 48){
                vec2.push_back(vec[i]);
            }
        }
        
        int min = *min_element(vec2.begin(), vec2.end());

        cout << min << endl;
        }
        return 0;
    }
    

