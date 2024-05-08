#pragma once
#include "EP.h"

using namespace std;


struct noTR {
  string  key;
  noTR * esq;
  noTR * dir; 
  Item val;
  int prior;
  noTR();
};

class TR { //treap
private:
  noTR * raiz;
  void rotRight(noTR* &raiz);
  void insertNod(noTR* &raiz, string key, Item val);
  void rotLeft(noTR* &raiz);
  void inOrdem (noTR *raiz);
  noTR * busca(noTR * raiz, string x);
  int maiorF(noTR* raiz);
  void Fordem(noTR* raiz, int F);
  int tamanhoMaiorPalavraSR(noTR * raiz, int x);
  void imprimeTam(noTR* raiz, int tam);
  void imprimePalavrasSR(noTR* raiz, int TAM, int X); 
  int menorVD(noTR* raiz);
  int menorTamanhoPalavraVD(noTR* raiz, int VD);
  void imprimeVD(noTR* raiz, int tam, int VD); 
public:
  int tamanhoTR;
  TR();
  void add_TR(string key, Item val){

  noTR* x = busca(raiz,key);

  if(x==nullptr) insertNod(raiz, key, val);
    else x->val.qtd_vzs++;
  }
  Item value_TR(string key){
    noTR* A =  busca(raiz,key);
    if(A == nullptr) return Item();
    return A->val;
  }
  void imprimirInOrdem_TR(){
    inOrdem(raiz);
  }
      int maiorFreq_TR(){
        return maiorF(raiz);
    }
    void imprimeF_TR(int F){
        Fordem(raiz, F);
    }
    int tamanhoDaMaior_TR(int x){
        return tamanhoMaiorPalavraSR(raiz,x);
    }
    void imprimeTamanho_TR(int tam){
        imprimeTam(raiz,tam);
    }
    void analisaEcalculaSR_TR(int a, int b){
        imprimePalavrasSR(raiz,a,b);
    }
    int VD_TR(){
        return menorVD(raiz);
    }
    int VD2_TR(int VD){
       return menorTamanhoPalavraVD(raiz,VD);
    }
    void imprimeVD_TR(int tam, int vd){
        imprimeVD(raiz,tam,vd);
    }

};