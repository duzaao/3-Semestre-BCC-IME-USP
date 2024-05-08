#include <iostream>
#include <vector>
using namespace std;

int achaFonte(const std::vector<std::vector<int>>& adj_list) {
    int V = adj_list.size();
    std::vector<int> in_degree(V, 0);
    
    // Calcula o grau de entrada de cada vértice
    for (int u = 0; u < V; u++) {
        for (int v : adj_list[u]) {
            in_degree[v]++;
        }
    }
    
    
    // Procura um vértice com grau de entrada zero (fonte)
    for (int u = 0; u < V; u++) {
        if (in_degree[u] == 0) {
            return u;
        }
    }
    
    // Não foi encontrado vértice fonte
    return -1;
}

int main() {
    int V = 6; // Número de vértices do grafo
    std::vector<std::vector<int>> adj_list(V);
    
    // Exemplo de grafo
    adj_list[0] = {1, 2};
    adj_list[1] = {3};
    adj_list[2] = {3, 4};
    adj_list[3] = {5};
    adj_list[4] = {5};
    adj_list[5] = {};
    
    int fonte = achaFonte(adj_list);
    
    if (fonte != -1) {
        std::cout << "Vértice fonte encontrado: " << fonte << std::endl;
    } else {
        std::cout << "Não há vértice fonte no grafo." << std::endl;
    }
    
    return 0;
}


