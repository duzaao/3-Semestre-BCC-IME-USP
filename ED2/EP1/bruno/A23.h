#include <iostream>
#include <fstream>
#include <algorithm> 
#include <string> 
#include <cstring>
#include <vector>

using namespace std;

typedef string Key; // Tipo de dados da chave

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
        void inOrder(no* raiz);
        int maiorF(no* raiz);
        void Fordem(no* raiz,int F);
        no* busca(no* raiz,string x);
        int tamanhoMaiorPalavraSR(no* raiz, int x);
        void imprimeTam(no* raiz,int tam);
        void imprimePalavrasSR(no * raiz,int a,int b);
        int menorVD(no* raiz);
        int menorTamanhoPalavraVD(no* raiz,int VD);
        void imprimeVD(no* raiz,int tam,int vd);
    public:
        A23() : raiz(nullptr) {}
        ~A23() {
            delete(raiz);
        }
        void add(string key, Item val){
            bool cresceu = 0;
            if(key == "") return;
            no* p = busca(raiz,key);
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
            inOrder(raiz);
        }

        // 

        int maiorFreq(){
        return maiorF(raiz);
        }
        void imprimeF(int F){
            Fordem(raiz, F);
        }

        no * value(string x){
            return busca(raiz, x);
        }

        int tamanhoDaMaior(int x){
            return tamanhoMaiorPalavraSR(raiz,x);
        }
        void imprimeTamanho(int tam){
            imprimeTam(raiz,tam);
        }
        void analisaEcalculaSR(int a, int b){
            imprimePalavrasSR(raiz,a,b);
        }
        int VD(){
            return menorVD(raiz);
        }
        int VD2(int VD){
        return menorTamanhoPalavraVD(raiz,VD);
        }
        void imprimeVD(int tam, int vd){
            imprimeVD(raiz,tam,vd);
        }

};


