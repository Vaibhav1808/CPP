#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin >> t;
    
    while(t--){
        ll n;
        cin >> n;
        ll arr[n];
        
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        ll mx = *max_element(arr, arr + n);
        ll mn = *min_element(arr, arr + n);
        
        //ll neg[n], pos[n];
		vector<ll> neg(n);
		vector<ll> pos(n);
        
        for(int i = 0; i < n; i++){
            if(arr[i] < 0){
                cin >> neg[i];
            }
        }
        // int ap = sizeof(neg) / sizeof(neg[0]);
        for(int i = 0; i < n; i++){
            if(arr[i] >= 0){
                cin >> pos[i];
            }
        }
        // int aptk = sizeof(pos) / sizeof(pos[0]);
        
        ll a = *max_element(pos.begin(), pos.end());
        ll b = *min_element(neg.begin(), neg.end());
        
        if(mx >= 0 && mn >= 0){
            cout << mn*mn << " " << mx*mx;
        }
        else if(mx >= 0 && mn < 0){
            if(mx >= abs(mn)){
                
                cout << a*b << " " << mx*mx;
            }
            else if(mx < abs(mn)){
                cout << a*b << " " << mn*mn;
            }
        }
        if(mx < 0 && mn < 0){
            cout << mx*mx << " " << mn*mn;
        }
        cout << endl;
    }
    
    return 0;
}