#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> adj[N];
bool visited[N];


void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            cnt++;
        }
    }
    if (cnt == 1 && m == n) {
        cout << "FHTAGN!\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}