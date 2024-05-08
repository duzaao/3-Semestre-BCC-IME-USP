#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e6;
const ll MOD = 1e9+7;

int t, n;
ll dp[maxN+1];

int main(){
    dp[1] = 2;
    dp[2] = 8;

    for(int i = 3; i <= maxN; i++)
        dp[i] = ((6*dp[i-1] - 7*dp[i-2]) % MOD + MOD) % MOD;

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }

    return 0;
}

