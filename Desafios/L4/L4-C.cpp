#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n; // tamanho do labirinto
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n)); // matriz que representa o labirinto
    vector<vector<int>> dp(n, vector<int>(n)); // matriz dp

    // leitura e criação da matriz do labirinto
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = -1;
            }
        }
    }

    // caso base: a posição inicial tem apenas um caminho
    dp[0][0] = (matrix[0][0] == 0) ? 1 : 0;

    // preenchimento da matriz dp
    for (int i = 1; i < n; i++) {
        if (matrix[i][0] == 0) {
            dp[i][0] = dp[i-1][0];
        }
    }
    for (int j = 1; j < n; j++) {
        if (matrix[0][j] == 0) {
            dp[0][j] = dp[0][j-1];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }

    cout << dp[n-1][n-1] << endl;

    return 0;
}
