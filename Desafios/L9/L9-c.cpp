#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200005;
const int MAXLOG = 21;

vector<int> adj[MAXN];
int p[MAXLOG][MAXN];
int lev[MAXN];

void dfs(int s, int parent) {
    for (auto i : adj[s]) {
        if (i != parent) {
            lev[i] = lev[s] + 1;
            dfs(i, s);
        }
    }
}

int raise(int x, int y) {
    int z = 0;
    while (y > 0) {
        if (y & 1)
            x = p[z][x];
        z++;
        y >>= 1;
    }
    return x;
}

int lca(int x, int y) {
    if (lev[x] > lev[y])
        swap(x, y);
    int d = lev[y] - lev[x];
    y = raise(y, d);
    if (x == y)
        return x;
    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (p[i][x] != p[i][y]) {
            x = p[i][x];
            y = p[i][y];
        }
    }
    return p[0][x];
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
            int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        p[0][i] = x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    for (int i = 1; i < MAXLOG; i++) {
        for (int j = 1; j <= n; j++) {
            p[i][j] = p[i - 1][p[i - 1][j]];
        }
    }
    dfs(1, 0);
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << '\n';
    }
        cout << '\n';
    }

    return 0;
}