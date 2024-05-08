#include <iostream>
#include <vector>

using namespace std;

void dfs(){
    bool * vis = new bool[G->v];
    for(int i = 0; i< G->v; i++){
        vis[i] = false;
    }
    for(int u = 0; u< G->v; u++){
        if(!vis[u])
            dfsR(u,vis);
    }

    delete[vis];

}

void dfsR (int v, bool* vis){
    vis[v] = true;
    for(int w = 0; w< G->v; w++){
        if(!vis[w] && G->adj[v][w]){
            dfsR(w,vis);
        }
    }
}

int main() {
    int n = 7; // Número total de nós no grafo
    vector<vector<int>> graph(n);

    // Definir as arestas do grafo
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[2].push_back(5);
    graph[2].push_back(6);

    cout << "DFS: ";
    dfsWrapper(graph, 0);
    cout << endl;

    return 0;
}
