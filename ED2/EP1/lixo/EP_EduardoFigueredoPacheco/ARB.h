#pragma once
#include "EP.h"

using namespace std;


#define RED true
#define BLACK false

struct noARB {
  string  key;
  noARB * esq;
  noARB * dir;
  noARB * pai; 
  Item val;
  bool color;
  noARB();
};


class ARB{

public:
    noARB * raiz;
    ARB() { raiz = NULL; }
    void add_ARB(string key, Item val){
        noARB* x = busca_ARB(raiz,key);
        if(x==nullptr) insere_ARB(key,val);
        else x->val.qtd_vzs++;
    }
    void imprimirInOrdem_ARB(){
        inOrdem_ARB(raiz);
    }
    int maiorFreq_ARB(){
        return maiorF_ARB(raiz);
    }
    void imprimeF_ARB(int F){
        Fordem_ARB(raiz, F);
    }

    Item value_ARB(string x){
        noARB * A = busca_ARB(raiz, x);
        if(A == nullptr) return Item();
        else return A->val;
    }

    int tamanhoDaMaior_ARB(int x){
        return tamanhoMaiorPalavraSR_ARB(raiz,x);
    }
    void imprimeTamanho_ARB(int tam){
        imprimeTam_ARB(raiz,tam);
    }
    void analisaEcalculaSR_ARB(int a, int b){
        imprimePalavrasSR_ARB(raiz,a,b);
    }
    int VD_ARB(){
        return menorVD_ARB(raiz);
    }
    int VD2_ARB(int VD){
       return menorTamanhoPalavraVD_ARB(raiz,VD);
    }
    void imprimeVD_ARB(int tam, int vd){
        imprimeVD_ARB(raiz,tam,vd);
    }

    bool tudoCertoComARBT(){
        return blackCount_ARB(raiz);
    }
    bool RNOK(){
        return rubroNegraOk_ARB(raiz);
    }

private:
    void inOrdem_ARB (noARB *raiz);
    void insere_ARB(string key, Item val);
    void inserirFixup_ARB(ARB *T, noARB *z);
    void esqRotate_ARB(ARB *T, noARB *z); 
    void dirRotate_ARB(ARB *T, noARB *x);
    noARB* busca_ARB(noARB * raiz, string x);
    int maiorF_ARB(noARB* raiz);
    void Fordem_ARB(noARB* raiz, int F);
    int tamanhoMaiorPalavraSR_ARB(noARB * raiz, int x);
    void imprimeTam_ARB(noARB* raiz, int tam);
    void imprimePalavrasSR_ARB(noARB* raiz, int TAM, int X); 
    int menorVD_ARB(noARB* raiz);
    int menorTamanhoPalavraVD_ARB(noARB* raiz, int VD);
    void imprimeVD_ARB(noARB* raiz, int tam, int VD); 
    bool rubroNegraOk_ARB(noARB * raiz);
    int blckCount_ARB(noARB* raiz, int count, int& prevCount, bool& sameBlackCount);
    bool blackCount_ARB(noARB* raiz); 
};

