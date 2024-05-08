
bool reconhece(Graph G, string palavra) {
    bool* atingidas = new bool[G.V];
    for (int i = 0; i < G.V; i++)
        atingidas[i] = false;

    G.dfsR(0, atingidas);

    for (int i = 0; i < palavra.length(); i++) {
        bool* prox = new bool[G.V];
        memset(prox, false, G.V * sizeof(bool));

        for (int j = 0; j < G.V; j++) {
            if (atingidas[j] && palavra[j] == palavra[i])
                prox[j + 1] = true;
        }

        bool* marcados = new bool[G.V];
        memset(marcados, false, G.V * sizeof(bool));

        for (int j = 0; j < G.V; j++) {
            if (prox[j]) {
                memset(marcados, false, G.V * sizeof(bool));
                G.dfsR(j, marcados);
                for (int k = 0; k < G.V; k++) {
                    if (marcados[k])
                        atingidas[k] = true;
                }
            }
        }

        delete[] prox;
        delete[] marcados;
    }

    bool resultado = atingidas[G.V-1];
    delete[] atingidas;
    return resultado;
}