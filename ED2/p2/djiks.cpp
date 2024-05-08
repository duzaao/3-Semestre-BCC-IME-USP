#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define INF INT_MAX

// Estrutura para representar um vértice e sua distância em relação à origem
struct VerticeDistancia {
    int vertice;
    int distancia;
};

// Função para imprimir o caminho mínimo a partir do vetor de predecessores
void imprimirCaminhoMinimo(const std::vector<int>& predecessores, int verticeDestino) {
    if (predecessores[verticeDestino] == -1) {
        std::cout << verticeDestino;
        return;
    }

    imprimirCaminhoMinimo(predecessores, predecessores[verticeDestino]);
    std::cout << " -> " << verticeDestino;
}

// Algoritmo de Dijkstra para encontrar o caminho mínimo em um grafo ponderado
void dijkstra(const std::vector<std::vector<std::pair<int, int>>>& adj_list, int verticeOrigem) {
    int V = adj_list.size();
    std::vector<int> distancias(V, INF);  // Vetor de distâncias
    std::vector<int> predecessores(V, -1);  // Vetor de predecessores
    std::vector<bool> visitados(V, false);  // Vetor de visitados

    // A distância até o vértice de origem é zero
    distancias[verticeOrigem] = 0;

    // Fila de prioridade para determinar o vértice com menor distância
    std::priority_queue<VerticeDistancia, std::vector<VerticeDistancia>, std::greater<VerticeDistancia>> pq;

    // Insere o vértice de origem na fila de prioridade
    pq.push({verticeOrigem, 0});

    while (!pq.empty()) {
        // Extrai o vértice com menor distância da fila de prioridade
        int u = pq.top().vertice;
        pq.pop();

        // Marca o vértice como visitado
        visitados[u] = true;

        // Percorre todos os vértices adjacentes ao vértice atual
        for (auto& vizinho : adj_list[u]) {
            int v = vizinho.first;
            int peso = vizinho.second;

            // Relaxamento da aresta (u, v)
            if (!visitados[v] && distancias[u] + peso < distancias[v]) {
                distancias[v] = distancias[u] + peso;
                predecessores[v] = u;
                pq.push({v, distancias[v]});
            }
        }
    }

    // Imprime os caminhos mínimos para todos os vértices do grafo
    for (int i = 0; i < V; i++) {
        std::cout << "Caminho mínimo de " << verticeOrigem << " para " << i << ": ";
        if (distancias[i] == INF) {
            std::cout << "Não existe caminho." << std::endl;
        } else {
            imprimirCaminhoMinimo(predecessores, i);
            std::cout << " | Distância: " << distancias[i] << std::endl;
        }
    }
}

int main() {
    int V = 6;  // Número de vértices do grafo
    std::vector<std::vector<std::pair<int, int>>> adj_list(V);

    // Exemplo de grafo ponderado
    adj_list[0] = {{1, 4}, {2, 2}};
    adj_list[1] = {{3, 2}, {2, 5}};
    adj_list[2] = {{3, 1}, {4, 7}};
    adj_list[3] = {{4, 3}, {5, 4}};
    adj_list[4] = {};
    adj_list[5] = {{4, 1}};

    int verticeOrigem = 0;

    std::cout << "Executando o algoritmo de Dijkstra:" << std::endl;
    dijkstra(adj_list, verticeOrigem);

    return 0;
}
