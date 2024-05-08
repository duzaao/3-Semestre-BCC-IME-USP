#include <bits/stdc++.h>
using namespace std;

long long dp[105][2];

long long Ktree(int n, int k, int d) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= k && i - j >= 0; j++) {
            if (j < d) {
                dp[i][0] += dp[i - j][0];
                dp[i][1] += dp[i - j][1];
            } 
            else {
                dp[i][1] += dp[i - j][0];
                dp[i][1] += dp[i - j][1];
            }
            dp[i][0] %= 1000000007;
            dp[i][1] %= 1000000007;
        }
    }
    return dp[n][1];
}

int main() {
    int n, k, d;
    cin >> n >> k >> d;
    cout << Ktree(n, k, d) << endl;
    return 0;
}
