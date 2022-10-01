#include <bits/stdc++.h>
using namespace std;

int main(){
    int tstcse;
    cin >> tstcse;

    for(int i = 0; i < tstcse; i++){
        int n;
        cin >> n;

        string s;
        cin >> s;

        int count_0 = 0, count_1 = 0, ans;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                count_1++;
            }
            else{
                count_0++;
            }
        }

        if(count_0 == count_1){
            ans = 2*count_0;
        }
        else if(count_0 < count_1){
            ans = 2*count_0 + 1;
        }
        else{
            ans = 2*count_1 + 1;
        }

        cout << ans << endl;
    }

    return 0;
}