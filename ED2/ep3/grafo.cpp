#include "grafo.h"

Grafo::Grafo() : numVertices(0) {}

void Grafo::lerGrafo(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        int numVertices, k;
        int ii = 0;
        arquivo >> numVertices >> k;

        string linha;
        while (getline(arquivo, linha) && ii < numVertices) {
            fragmentos.push_back(linha);
            ii++;
        }
        arquivo.close();

        this->numVertices = numVertices;
        this->k = k;
        construirAdjacencias(k);
    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
}


    void Grafo::construirAdjacencias(int k) {
        int numVertices = fragmentos.size();
        adjList.clear(); // Limpar a lista de adjacências existente
        bool ok = true;
        int cont=0;
        for (int kk = k; ok; kk++){
            cont =0;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (i != j && temConexao(fragmentos[i], fragmentos[j],kk)) {
                    adicionarArco(fragmentos[i],fragmentos[j]);
                    cont++;
                }
            }
        }
        if (cont == 0) ok = false;
        }
    }

bool Grafo::temConexao(const string& fragmento1, const string& fragmento2, int k) {
    int tamanho1 = fragmento1.length();
    int tamanho2 = fragmento2.length();

    
    if (tamanho1 >= k && tamanho2 >= k) {
        string ultimasLetras = fragmento1.substr(tamanho1 - k);
        string primeirasLetras = fragmento2.substr(0, k);
        
        
        //if(ultimasLetras == primeirasLetras) cout << fragmento1 << " " << fragmento2<< endl;

        return ultimasLetras == primeirasLetras;
    }

    return false;
}

void Grafo::adicionarArco(string u, string v) {
    adjList[u].push_back(v);
}

bool Grafo::arcoEmCircuito(string u, string v) {
    unordered_set<string> visited;
    return dfs(u, v, visited);
}

bool Grafo::dfs(string start, string target, unordered_set<string>& visited) {
    if (start == target) {
        return true;
    }

    visited.insert(start);

    if (adjList.find(start) != adjList.end()) {
        for ( string& neighbor : adjList[start]) {
            if (visited.find(neighbor) == visited.end()) {
                if (dfs(neighbor, target, visited)) {
                    return true;
                }
            }
        }
    }

    visited.erase(start);
    return false;
}

void Grafo::removerCiclos() {
    vector<string> vertices;
    for (const auto& entry : adjList) {
        vertices.push_back(entry.first);
    }

    for (const string& u : vertices) {
        for (const string& v : adjList[u]) {
            if (arcoEmCircuito(v, u)) {
                // Encontrou um ciclo entre u e v, remove o arco
                vector<string>& vizinhos = adjList[u];
                vizinhos.erase(remove(vizinhos.begin(), vizinhos.end(), v), vizinhos.end());
            }
        }
    }
}


string Grafo::caminhoMaximo() {
    // Remove ciclos do grafo
    removerCiclos();

    string caminhoMaxString;
    int maxLength = 0;

    // Conjunto para armazenar todos os vértices do grafo
    unordered_set<string> vertices;
    for (const auto& entry : adjList) {
        vertices.insert(entry.first);
        for (const string& neighbor : entry.second) {
            vertices.insert(neighbor);
        }
    }

    // Itera sobre cada vértice como ponto de partida para a DFS
    for (const string& start : vertices) {
        // Conjunto para armazenar os vértices visitados
        unordered_set<string> visited;
        // Executa a DFS a partir do vértice de partida
        dfs1(start, start, visited, caminhoMaxString, maxLength);
    }

    return caminhoMaxString;
}

void Grafo::dfs1(const string& current, const string& path, unordered_set<string>& visited, string& caminhoMaxString, int& maxLength) {
    visited.insert(current);

    if (path.length() > maxLength) {
        maxLength = path.length();
        caminhoMaxString = path;
    }

    for (const string& neighbor : adjList[current]) {
        // Concatena o vizinho ao caminho, considerando o valor de k
        string newPath = concatenarStrings(path, neighbor);
        
        dfs1(neighbor, newPath, visited, caminhoMaxString, maxLength);
    }

    visited.erase(current);
}


string Grafo::concatenarStrings(const string& str1, const string& str2) {
    int len1 = str1.length();
    int len2 = str2.length();
    int commonLen = 0;

    // Encontra o tamanho da parte em comum entre as strings
    for (int i = 0; i < len1 && i < len2; i++) {
        //cout << str1.substr(len1 - i - 1) << " " <<  str2.substr(0, i + 1) << endl;
        if (str1.substr(len1 - i - 1) == str2.substr(0, i + 1)) {
            commonLen = i+1;
        } else {
            
        }
    }

    // Concatena as strings e remove a parte em comum
    //cout << str1 << " " << str2 << " " << commonLen << " ->  "; 
    string concatenated = str1 + str2.substr(commonLen);
    //cout << concatenated;

    return concatenated;
}





