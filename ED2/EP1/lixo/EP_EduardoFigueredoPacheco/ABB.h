#pragma once
#include "EP.h"

using namespace std;

struct noABB {
  string  key;
  noABB * esq;
  noABB * dir; 
  Item val;
  noABB();
};




class ABB {
public:

    ABB() : raiz(nullptr) {}
    ~ABB() {
        delete(raiz);
    }

    noABB * buscaABB(string x) {
        return buscaABB(raiz, x);
    }
    noABB * procuraABB(string x) {
        return procuraABB(x);
    }
    void adicionarABB(string key, Item val) {
        raiz = addABB(raiz, key, val);
    }
    Item valorABB(string key) {
        noABB* A = buscaABB(raiz, key);
        if(A == nullptr) return Item();
        else return A->val;
    }
    void imprimirInOrdemABB() {
        inOrdemABB(raiz);
    }
    int maiorFreqABB(){
        return maiorFABB(raiz);
    }
    void imprimeFABB(int F){
        FordemABB(raiz, F);
    }
    int tamanhoDaMaiorABB(int x){
        return tamanhoMaiorPalavraSRABB(raiz,x);
    }
    void imprimeTamanhoABB(int tam){
        imprimeTamABB(raiz,tam);
    }
    void analisaEcalculaSRABB(int a, int b){
        imprimePalavrasSRABB(raiz,a,b);
    }
    int VDABB(){
        return menorVDABB(raiz);
    }
    int VD2ABB(int VD){
       return menorTamanhoPalavraVDABB(raiz,VD);
    }
    void imprimeVDABB(int tam, int vd){
        imprimeVDABB(raiz,tam,vd);
    }
    int tamanhoABB;
private:
    noABB * raiz;
    noABB * buscaABB (noABB * raiz, string  x);
    noABB * procuraABB(noABB * raiz, string x);
    noABB * insereABB (noABB * raiz, string  x, Item val);
    noABB *  addABB (noABB * raiz,string  key, Item val);
    int valueABB (noABB * raiz,string  key);
    void inOrdemABB (noABB *raiz); 
    int maiorFABB(noABB * raiz);
    void FordemABB(noABB * raiz, int F);
    int tamanhoMaiorPalavraSRABB(noABB * raiz, int x);
    void imprimeTamABB(noABB* raiz, int tam);
    void imprimePalavrasSRABB(noABB * raiz, int TAM, int X); 
    int menorVDABB(noABB* raiz);
    int menorTamanhoPalavraVDABB(noABB * raiz, int VD);
    void imprimeVDABB(noABB* raiz, int tam, int VD); 
};

