#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string longest_common_subsequence(string s, string t) {
    int n = s.length(), m = t.length();
    // create table
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    // fill table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    // backtrack to construct longest common subsequence
    string lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s[i-1] == t[j-1]) {
            lcs.push_back(s[i-1]);
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    string s,t;
    cin >> s >> t;
    cout << longest_common_subsequence(s, t) << endl;
    return 0;
}
