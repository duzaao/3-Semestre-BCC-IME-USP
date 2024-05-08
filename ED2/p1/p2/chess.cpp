#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> buildChessboardGraph(int n) {
    vector<vector<int>> graph(n * n);
    vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1},
                                    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int currentVertex = i * n + j;

            for (auto move : moves) {
                int x = move.first;
                int y = move.second;
                int newX = i + x;
                int newY = j + y;

                if (0 <= newX && newX < n && 0 <= newY && newY < n) {
                    int neighborVertex = newX * n + newY;
                    graph[currentVertex].push_back(neighborVertex);
                }
            }
        }
    }

    return graph;
}

vector<int> findDistances(const vector<vector<int>>& graph, int startVertex) {
    int n = graph.size();
    vector<int> distances(n, -1);
    distances[startVertex] = 0;

    queue<int> q;
    q.push(startVertex);

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        for (int neighborVertex : graph[currentVertex]) {
            if (distances[neighborVertex] == -1) {
                distances[neighborVertex] = distances[currentVertex] + 1;
                q.push(neighborVertex);
            }
        }
    }

    return distances;
}

/*

while (!q.empty()){
    int current = q.front();
    q.pop();

    for(int nei : graph[current]){
        
    }
}
*/

int main() {
    int n = 5;

    // Construir o grafo
    vector<vector<int>> graph = buildChessboardGraph(n);

    // Calcular as distâncias do vértice inicial
    int startVertex = 24;
    vector<int> distances = findDistances(graph, startVertex);

    // Imprimir as distâncias
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int vertex = i * n + j;
            cout << distances[vertex] << " ";
        }
        cout << endl;
    }

    return 0;
}
