#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, V;
    cin >> N >> V;

    vector<int> valor(N+1), peso(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> peso[i] >> valor[i];
    }

    // Aloca a matriz dp dinamicamente
    int*** dp = new int**[N+1];
    for (int i = 0; i <= N; i++) {
        dp[i] = new int*[V+1];
        for (int j = 0; j <= V; j++) {
            dp[i][j] = new int[V+1];
        }
    }

    // Inicializa a matriz dp com -1
    memset(dp, -1, N * (V + 1) * sizeof(int));

    // Casos base
    for (int v = 0; v <= V; v++) {
        dp[0][v][0] = 0;
        for (int i = 1; i <= N; i++) {
            dp[i][v][0] = 0;
        }
    }

    // DP
    for (int i = 1; i <= N; i++) {
        for (int v = 0; v <= V; v++) {
            for (int k = 0; k <= min(v, peso[i]); k++) {
                for (int j = 0; j <= V; j++) {
                    if (dp[i-1][j][v-k] != -1) {
                        dp[i][v][j] = max(dp[i][v][j], dp[i-1][j][v-k] + valor[i] * k);
                    }
                }
            }
        }
    }

    // Encontra a solução
    int ans = 0;
    for (int v = 0; v <= V; v++) {
        for (int j = 0; j <= V; j++) {
            ans = max(ans, dp[N][v][j]);
        }
    }

    cout << ans << endl;

    // Libera a memória alocada para a matriz dp
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= V; j++) {
            delete[] dp[i][j];
        }
        delete[] dp[i];
    }
    delete[] dp;

    return 0;
}
