#include "constroi.h"



vector<char> Constroi::constroi_Mais(int i, vector<char>& traduzido) {
    int j = i;
    stack<char> pilha;
    pilha.push('*');
    j--;
    pilha.push(traduzido[j]);
    j--;

    int contadorParentesesEsquerda = 0, contadorParentesesDireita = 1;
    string primeiraParte = "";
    string segundaParte = "";

    while (contadorParentesesEsquerda != contadorParentesesDireita) {
        if (traduzido[j] == ')')
            contadorParentesesDireita++;
        else if (traduzido[j] == '(')
            contadorParentesesEsquerda++;

        pilha.push(traduzido[j]);
        j--;
    }

    int tamanhoPilhaOriginal = pilha.size();
    while (!pilha.empty()) {
        segundaParte = segundaParte + pilha.top();

        if (pilha.size() != tamanhoPilhaOriginal && pilha.size() > 2)
            primeiraParte = primeiraParte + pilha.top();

        pilha.pop();
    }

    string resultadoFinal = primeiraParte + segundaParte;
    int tamanhoResultado = resultadoFinal.length();
    j++;

    vector<char> palavra(resultadoFinal.begin(), resultadoFinal.end());

    vector<char> novoTraduzido(traduzido.size() + tamanhoResultado - (i - j + 1));

    for (int q = 0; q < traduzido.size() + tamanhoResultado - (i - j + 1); q++) {
        if (q >= j && q < j + tamanhoResultado)
            novoTraduzido[q] = palavra[q - j];
        else if (q < j)
            novoTraduzido[q] = traduzido[q];
        else
            novoTraduzido[q] = traduzido[q - tamanhoResultado + (i - j + 1)];
    }

    index = tamanhoResultado + j;
    return novoTraduzido;
}


bool Constroi::constroi_simboloRegex(char simbolo) {
    return (simbolo == '.' || simbolo == '|' || simbolo == '*' || simbolo == '+' || simbolo == '[' || simbolo == ']' || simbolo == '-' || simbolo == '^' || simbolo == '(' || simbolo == ')');
}

vector<char> Constroi::constroi_Ponto(int n, int k, vector<char>& traduzido) {
    string simbolosEspeciais = "|*.+[]-^()";
    int diferenca = simbolosEspeciais.length();
    int totalSimbolos = 127 - 32;
    int auxiliar = totalSimbolos + diferenca;
    int numeroOu = totalSimbolos - 1;
    int tamanhoTotal = auxiliar + numeroOu;
    vector<char> padraoPonto(tamanhoTotal + 2);
    padraoPonto[0] = '(';
    padraoPonto[tamanhoTotal + 1] = ')';
    int i = 0, j = 1, contadorOu = 0;

    while (i < totalSimbolos) {
        if (constroi_simboloRegex(char(i + 32))) {
            padraoPonto[j] = '\\';
            padraoPonto[j + 1] = char(i + 32);

            if (contadorOu < numeroOu) {
                padraoPonto[j + 2] = '|';
                contadorOu++;
            }

            i++;
            j = j + 3;
        }
        else {
            padraoPonto[j] = char(i + 32);

            if (contadorOu < numeroOu) {
                padraoPonto[j + 1] = '|';
                contadorOu++;
            }

            i++;
            j = j + 2;
        }
    }

    vector<char> novoTraduzido(traduzido.size() + padraoPonto.size() - 1);
    j = 0;
    int aux = 0;

    while (j + aux < traduzido.size() + padraoPonto.size()) {
        if (j < k)
            novoTraduzido[j] = traduzido[j];
        else if (j == k && aux < padraoPonto.size()) {
            novoTraduzido[j + aux] = padraoPonto[aux];
            aux++;
            continue;
        }
        else if (j > k)
            novoTraduzido[j + aux - 1] = traduzido[j];

        j++;
    }

    index = padraoPonto.size();
    return novoTraduzido;
}


string constrooi(string original) {
    string traduzido = original;
    string backup = traduzido;
    bool alterou = false;
    string novo;
    int index = 0;
    int i = 0;

    while (i < traduzido.length()) {

        
        if (traduzido[i] == '.') {
            alterou = true;
            novo = trataPonto(traduzido.length(), i, traduzido);
            traduzido = novo;
            i = i + index - 1;
        }

        if (traduzido[i] == '+') {
            alterou = true;
            novo = trataMais(i, traduzido);
            traduzido = novo;
            i = index - 1;
        }

        if (traduzido[i] == '[' && traduzido[i + 1] != '^' && traduzido[i + 2] == '-') {
            alterou = true;
            int first = int(traduzido[i + 1]);
            int last = int(traduzido[i + 3]);
            novo = trataIntervalo(i, first, last, traduzido);
            traduzido = novo;
            i = index - 1;
        }

        if (traduzido[i] == '[' && traduzido[i + 1] != '^' && traduzido[i + 2] != '-') {
            alterou = true;
            novo = trataConjunto(i, traduzido);
            traduzido = novo;
            i = index - 1;
        }

        if (traduzido[i] == '[' && traduzido[i + 1] == '^') {
            alterou = true;
            novo = trataComplemento(i + 1, traduzido);
            traduzido = novo;
            i = index - 1;
        }

        i++;
    }

    if (alterou)
        return novo;
    else
        return backup;
}