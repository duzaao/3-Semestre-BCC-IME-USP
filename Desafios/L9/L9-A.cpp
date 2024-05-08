#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
const int MAXD = 30; 

// número de planetas e consultas
int n, q;
int p[MAXN][MAXD];

int jump(int a, int d) {
    for (int i = 0; i < MAXD; i++)
        if (d & (1 << i)) a = p[a][i];
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) { cin >> p[i][0]; }
    // avalia a matriz de pais
    for (int d = 1; d < MAXD; d++)
        for (int i = 1; i <= n; i++) {
            p[i][d] = p[p[i][d - 1]][d - 1];
        }
    // processa as consultas
    while (q--) {
        int a, d;
        cin >> a >> d;
        cout << jump(a, d) << '\n';
    }
}
