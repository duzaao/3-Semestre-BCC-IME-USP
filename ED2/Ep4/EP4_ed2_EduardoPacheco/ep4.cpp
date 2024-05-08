#include <string.h>
#include <stack>
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Graph {
private:
    char* re; // Vetor de caracteres para armazenar a expressão regular

public:
    vector<vector<int>> adj;
    vector<vector<char>> letras;
    int L;
    int V;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
        letras.resize(V);
        L = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void dfsR(int v, bool* visited) {
        visited[v] = true;
        

        for (int i = 0; i < adj[v].size(); i++) {
            int u = adj[v][i];
            if (!visited[u]) {
                dfsR(u, visited);
            }
        }
    }



    void setRegex(string regexp) {
        int m = regexp.length();
        re = new char[m + 1];
        strcpy(re, regexp.c_str());
    }

    char* getRegex() {
        return re;
    }
};

bool reconhece(Graph G, string texto) {
    char* re = G.getRegex(); // Obtém a expressão regular do grafo
    bool* atingidos = new bool[G.V];



    for (int i = 0; i < G.V; i++)
        atingidos[i] = false;

    G.dfsR(0, atingidos);



    for (int i = 0; i < texto.length(); i++) {
        bool* prox = new bool[G.V];
        for (int l = 0; l < G.V; l++)
            prox[l] = false;

        for (int j = 0; j < G.V; j++) {
            if (atingidos[j] && re[j] == texto[i])
                prox[j + 1] = true;
        }
        bool ok = false;
        for (int j = 0; j < G.V; j++) if(prox[j]==false) ok = false; else {ok = true; break;}
        if(ok == false) return false;

        bool* marcados = new bool[G.V];
        for (int j = 0; j < G.V; j++)
            marcados[j] = false;

        for (int j = 0; j < G.V; j++) {
            if (prox[j]) {
                for (int k = 0; k < G.V; k++)
                    marcados[k] = false;

                G.dfsR(j, marcados);

                for (int k = 0; k < G.V; k++) {
                    if (marcados[k])
                        atingidos[k] = true;
                }
            }
        }

        //delete[] prox;
        delete[] marcados;
    }



    bool resultado = atingidos[G.V - 1];
    delete[] atingidos;

    return resultado;
}

Graph criarGrafoExpressaoRegular(string regexp) {
    stack<int> ops;
    int m = regexp.length();
    Graph G(m + 1);
    G.setRegex(regexp); // Define a expressão regular no grafo

    for (int i = 0; i < m; i++) {
        int lp = i;

        if (regexp[i] == '[') {
            int j = 0;

            if (regexp[i + 1] == '^') {
                i = i + 2;
                G.letras[G.L].push_back('&'); // Utiliza push_back para adicionar elementos ao vetor de caracteres
                j++;
                while (regexp[i] != ']') {
                    G.letras[G.L].push_back(regexp[i]); // Utiliza push_back para adicionar elementos ao vetor de caracteres
                    j++;
                    i++;
                }
                G.letras[G.L].push_back('\0'); // Adiciona o caractere nulo ao final do vetor de caracteres
                G.L++;
                continue;
            } else {
                while (regexp[i] != ']') {
                    G.addEdge(lp, lp + 1); // Adiciona aresta para o próximo caractere
                    G.letras[G.L].push_back(regexp[i]); // Utiliza push_back para adicionar elementos ao vetor de caracteres
                    j++;
                    lp = lp + 1;
                    i++;
                }
                G.addEdge(lp, lp + 1); // Adiciona aresta para o próximo caractere
                G.letras[G.L].push_back('\0'); // Adiciona o caractere nulo ao final do vetor de caracteres
                G.L++;
                continue;
            }
        }

        if (regexp[i] == '(' || regexp[i] == '|')
            ops.push(i);
        else {
            if (regexp[i] >= 'A' && regexp[i] <= 'Z')
                continue;
            if (regexp[i] == ')') {
                int or_op = ops.top();
                ops.pop();
                if (regexp[or_op] == '|') {
                    lp = ops.top();
                    ops.pop();
                    G.addEdge(lp, or_op + 1);
                    G.addEdge(or_op, i);
                } else if (regexp[or_op] == '(') {
                    lp = or_op;
                }
            }
        }
        if (i < m - 1 && regexp[i + 1] == '*') {
            G.addEdge(lp, i + 1);
            G.addEdge(i + 1, lp);
        }
        if (regexp[i] == '(' || regexp[i] == '*' || regexp[i] == ')')
            G.addEdge(i, i + 1);
    }

    return G;
}


int main() {
    string expressao;
    cout << "Digite uma expressão regular: ";
    cin >> expressao;

    Graph grafo = criarGrafoExpressaoRegular(expressao);

    string palavra;
    int n;
    cout << "Digite o número de testes: ";
    cin >> n;

    for (int x = 0; x < n; x++) {
        cout << "Digite uma palavra para verificar: ";
        cin >> palavra;

        bool resultado = reconhece(grafo, palavra);

        if (resultado)
            cout << "S" << endl;
        else
            cout << "N" << endl;
    }
    return 0;
}
