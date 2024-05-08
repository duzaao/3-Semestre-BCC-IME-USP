#ifndef GRAFO_H
#define GRAFO_H

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Grafo {
private:
    int numVertices;
    int k;
    unordered_map<string, vector<string>> adjList;
    std::vector<std::string> fragmentos ;


public:
    Grafo();

    void lerGrafo(const std::string& nomeArquivo) ;
    void adicionarArco(string u, string v);
    bool arcoEmCircuito(string u, string v);
    string  caminhoMaximo();
    void dfs1(const string& current, const string& path, unordered_set<string>& visited, string& caminhoMaxString, int& maxLength);
    void removerCiclos();
    void construirAdjacencias(int k);
    bool temConexao(const std::string& fragmento1, const std::string& fragmento2, int k);
    string concatenarStrings(const string& str1, const string& str2);


private:
    bool dfs(string start, string target, unordered_set<string>& visited);
};

#endif  // GRAFO_H
