#include <iostream>
#include <vector>

bool testaCaminho(const std::vector<std::vector<int>>& adj_list, const std::vector<int>& seq) {
    int V = adj_list.size();
    int n = seq.size();
    
    // Verifica se o caminho tem pelo menos 2 vértices
    if (n < 2) {
        return false;
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u = seq[i];
        int v = seq[i + 1];
        
        // Verifica se existe uma aresta entre os vértices u e v
        bool aresta_existe = false;
        
        for (int adj : adj_list[u]) {
            if (adj == v) {
                aresta_existe = true;
                break;
            }
        }
        
        if (!aresta_existe) {
            return false;
        }
    }
    
    return true;
}

bool verificaSeq(const std::vector<std::vector<int>>& adj_list, const std::vector<int>& seq) {
    int V = adj_list.size();
    int n = seq.size();
    int u = seq[0];
    bool ok =true;
    int i = 1;
        for(int w : adj_list[u]){
            if((w == seq[i] )&& (i==(n-1))) return true;
            if(w == seq[i]) {
                i++;
                u = w;
                continue;
            }
        }
        return false;
        

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
    
    std::vector<int> caminho1 = {0, 1, 3, 5};
    std::vector<int> caminho2 = {2, 4, 5, 3};
    std::vector<int> caminho3 = {0, 2, 4};
    
    if (verificaSeq(adj_list, caminho1)) {
        std::cout << "O vetor caminho1 representa um caminho válido." << std::endl;
    } else {
        std::cout << "O vetor caminho1 não representa um caminho válido." << std::endl;
    }
    
    if (verificaSeq(adj_list, caminho2)) {
        std::cout << "O vetor caminho2 representa um caminho válido." << std::endl;
    } else {
        std::cout << "O vetor caminho2 não representa um caminho válido." << std::endl;
    }
    
    if (verificaSeq(adj_list, caminho3)) {
        std::cout << "O vetor caminho3 representa um caminho válido." << std::endl;
    } else {
        std::cout << "O vetor caminho3 não representa um caminho válido." << std::endl;
    }
    
    return 0;
}
