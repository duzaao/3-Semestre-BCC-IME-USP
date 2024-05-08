#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll weights[101], values[101];
const ll max_val = 1e5;
ll inf = 1e15;

ll dp[101][max_val+1];

int main() {
    ll n, W;
    cin >> n >> W;
    ll weights[n], values[n];
    for(ll i=0;i<n;i++){
        cin >> weights[i] >> values[i];
    }

    for(int items = 0; items <= n; items ++){
        for(int tot_val = 0; tot_val <= max_val; tot_val++){
            if(items == 0){
                if(tot_val > 0){
                    dp[items][tot_val] = inf;
                } else{
                    dp[items][tot_val] = 0;
                }
            } else {
                ll take = inf;
                if(values[items-1] <= tot_val){
                    take = dp[items-1][tot_val-values[items-1]] + weights[items-1];
                }
                ll dont_take = dp[items-1][tot_val];
                dp[items][tot_val] = min(take,dont_take);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= max_val ; i++){
        if(dp[n][i] <= W) ans = max(ans,i);
    }

    cout << ans << endl;
    return 0;
}
