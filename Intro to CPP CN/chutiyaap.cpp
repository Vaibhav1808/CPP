#include <bits/stdc++.h>
using namespace std;

#define l long
#define fl float
#define du double
#define ll long long int

#define si set<int>
#define sll set<ll>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vpi vector<pi>
#define pll pair<ll, ll>
#define pi pair<int, int>
#define mii map<int, int>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf pop_front
#define cnt(a) while(a--)
#define sortv(a) sort(all(a))
#define uniqv(a) unique(all(a))
#define type(a) typeid(a).name()
#define all(a) a.begin(), a.end()
#define tov(a, b) a.assign(all(b))
#define minv(a) *min_element(all(a))
#define maxv(a) *max_element(all(a))
#define ub(a, b) upper_bound(all(a), b)
#define lb(a, b) lower_bound(all(a), b)
#define rsortv(a) sort(all(a), greater<int>())
#define rep(a, b, c) for(int(a) = (b); (a) < (c); (a)++)

const ll INF = 1e18;
const int32_t M = 1e9 + 7;
const double PI = acos(-1);
const int32_t MM = 998244353;
const ll INFF = 1000000000000000005ll;

#include <ext/pb_ds/tree_policy.hpp>

// -------------------------------------------------------------------------------------------------------------------------------

int main() {
	ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);


	ll t;
	cin >> t;
	
	cnt(t){
	    ll n;
	    cin >> n;
        
        ll arr[n];
        
        rep(i,0,n){
            cin >> arr[i];
        }
        
         ll ans[n] = {0};
         rep(i,0,n){
             ans[arr[i]]++;
        }
        rep(i,0,n){
            cout << ans[arr[i]] << " ";
        }
    //     int ans[n];
    //     int index = 0;
    
    //     for(int i = 0; i < n; i++){
    //         int k = 1;
    //         for(int j = 0; j < n; j++){
    //             if(arr[j] == arr[i] && j != i){
    //             k++;
    //             }
    //         }
    //     ans[index] = k;
    //     index++;
    // }
        
        
        sort(ans, ans + n);
        
        cout << n-ans[n-1] << endl;
        
        
	}
	return 0;
}
