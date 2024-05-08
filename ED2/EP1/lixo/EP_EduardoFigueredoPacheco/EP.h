#pragma once
#include <iostream>
#include <fstream>
#include <algorithm> 
#include <string> 
#include <cstring>
#include <vector>

struct Item{
    int qtd_vzs; /* a quantidade de vezes que aparece*/
    int tam;
    int numVogais;
    int numVogaisRepetidas;
    int numRepeticoes;

    Item(){
        qtd_vzs = 0;
        tam = 0;
        numVogais = 0;
        numVogaisRepetidas = 0;
        numRepeticoes = 0;
    }
};