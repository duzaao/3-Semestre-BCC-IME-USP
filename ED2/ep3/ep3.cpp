#include "grafo.h"



int main() {
    string nomeArquivo;
    cout << "Digite o nome do arquivo com a sequencia de DNA: ";
    cin >> nomeArquivo;

    Grafo grafo;
    grafo.lerGrafo(nomeArquivo);

    string caminhoMaximo = grafo.caminhoMaximo();

    cout << "Caminho máximo encontrado: " << caminhoMaximo << endl;

    return 0;
}