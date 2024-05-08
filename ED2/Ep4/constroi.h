#include "ep4.h"



class Constroi {
private:
    vector<char> constroi_Ponto(int n, int i, vector<char>& traduzido);
    vector<char> constroi_Mais(int i, vector<char>& traduzido);
    char* constroi_trataIntervalo(int k, int first, int last, char* traduzido);
    char* constroi_trataConjunto(int k, char* traduzido);
    char* constroi_trataComplemento(int k, char* traduzido);
    bool constroi_simboloRegex(char simbolo);
    bool constroi_contido(char caractere, char* conjunto);
    int index = 0;

public:
    Constroi() {}
    char* constroi_traduz(string original);
};