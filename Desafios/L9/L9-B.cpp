#include <iostream>
using namespace std;

const int MAXN = 2e5 + 1;
const int LOGK = 20;

int N, Q, x, k;
int p[MAXN][LOGK];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    for (int i = 2; i <= N; i++)
        cin >> p[i][0];
    for (int j = 1; j < LOGK; j++) {
        for (int i = 1; i <= N; i++) {
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
    }

    for (int q = 0; q < Q; q++) {
        cin >> x >> k;
        for (int i = 0; i < LOGK; i++) {
            if (k & (1 << i)) {
                x = p[x][i];
            }
        }
        cout << (x ? x : -1) << '\n';
    }
}
