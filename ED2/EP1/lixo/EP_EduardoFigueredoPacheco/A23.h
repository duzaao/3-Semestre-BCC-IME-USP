#pragma once
#include "EP.h"

using namespace std;

typedef string Key; // Tipo de dados da chave



// Tipo de dados do valor

typedef struct no {
    bool is2no;
    Key ch1;
    Item val1;
    Key ch2;
    Item val2;
    no* p1;
    no* p2;
    no* p3;

    no(bool is2no, Key ch1, Item val1, Key ch2, Item val2, no* p1, no* p2, no* p3) : is2no(is2no), ch1(ch1), val1(val1), ch2(ch2), val2(val2), p1(p1), p2(p2), p3(p3) {}

} no;

class A23 {
    private:
        no* raiz;

        no* put23(no* raiz, Key key, Item val, bool &cresceu);
        void inOrder23(no* raiz);
        int maiorF23(no* raiz);
        void Fordem23(no* raiz,int F);
        no* busca23(no* raiz,string x);
        int tamanhoMaiorPalavraSR23(no* raiz, int x);
        void imprimeTam23(no* raiz,int tam);
        void imprimePalavrasSR23(no * raiz,int a,int b);
        int menorVD23(no* raiz);
        int menorTamanhoPalavraVD23(no* raiz,int VD);
        void imprimeVD23(no* raiz,int tam,int vd);
    public:
        A23() : raiz(nullptr) {}
        ~A23() {
            delete(raiz);
        }
        void add_23(string key, Item val){
            bool cresceu = 0;
            if(key == "") return;
            no* p = busca23(raiz,key);
            if(p != nullptr){

                //cout << p->ch1 << " " << " =  " << key << endl;
                if(p->ch1 == key){
                    p->val1.qtd_vzs++;
                    return;
                }
                else if(!p->is2no){    
                 if(p->ch2 == key){
                    p->val2.qtd_vzs++;
                    return;
                }}
            
            
            }
        else raiz = put23(raiz, key, val, cresceu);
        }

        void imprimirInOrdem(){
            inOrder23(raiz);
        }

        // 

        int maiorFreq23(){
        return maiorF23(raiz);
        }
        void imprimeF23(int F){
            Fordem23(raiz, F);
        }

        Item value23(string x){
            no* A = busca23(raiz, x);
            if(A==nullptr) return Item();
            else if(A->ch1 == x) return A->val1;
            else return A->val2;
            
        }

        int tamanhoDaMaior23(int x){
            return tamanhoMaiorPalavraSR23(raiz,x);
        }
        void imprimeTamanho23(int tam){
            imprimeTam23(raiz,tam);
        }
        void analisaEcalculaSR23(int a, int b){
            imprimePalavrasSR23(raiz,a,b);
        }
        int VD23(){
            return menorVD23(raiz);
        }
        int VD2_23(int VD){
        return menorTamanhoPalavraVD23(raiz,VD);
        }
        void imprimeVD23(int tam, int vd){
            imprimeVD23(raiz,tam,vd);
        }

};