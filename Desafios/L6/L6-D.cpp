#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

vector<vector<int>> adj; // Mudança de long long para int, pois o grafo é simples e não precisamos de números muito grandes
vector<bool> vis;
int d_max, no_max; 

void dfs(int u, int dist) { // Mudança de int para void, pois a função não precisa retornar nada

  vis[u] = true;
  for(int v:adj[u]) {
    if(!vis[v]) {
      if(dist+1 > d_max) {
        d_max = dist+1;
        no_max = v;
      }
      dfs(v, dist+1);
    }
  }
}

int main() {
    int n , m , i, j, u ,v , cont;

    cin >> n;
    adj.resize(n+1); // Redimensionamento do vetor de adjacências para o número de vértices do grafo

    for(i=0;i<n-1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vis.resize(n+1);
    vis.assign(n+1, false);
// Mudança do memset para receber o ponteiro do vetor e do tamanho em bytes

    d_max = 0;
    no_max = 1; // Inicialização do nó máximo como 1, pois o grafo é conexo

    dfs(1,0);

    vis.assign(n+1, false);

    d_max = 0;

    dfs(no_max,0);

    cout << d_max << endl;
    return 0;
}
