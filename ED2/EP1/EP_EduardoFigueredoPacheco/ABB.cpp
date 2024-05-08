#include "ABB.h"

noABB:: noABB(){}

noABB * ABB::buscaABB(noABB * raiz, string x){
    if(raiz == nullptr )
        return nullptr;
    if (x == raiz->key){
        //raiz->val.qtd_vzs++;
        return raiz;

    }
    if (x < raiz->key)
        return buscaABB (raiz->esq, x);
    return buscaABB (raiz->dir, x);
    }


noABB* ABB::procuraABB(noABB* raiz, string x){
if(raiz==nullptr) return nullptr;
    if (x == raiz->key)
    return raiz;
if (x< raiz->key)
    return procuraABB (raiz->esq, x);
return procuraABB (raiz->dir, x);
}      



noABB * ABB::insereABB (noABB * raiz, string  x,Item val){
int i;
if (raiz == nullptr){
    raiz = new noABB();

    raiz->key = x;
    raiz->val = val;
    raiz->dir = raiz->esq = nullptr;
    tamanhoABB++;
    return raiz;
}

if(x < raiz->key){
    raiz->esq = insereABB (raiz->esq, x, val);
}
else if(x >  raiz->key){
    raiz->dir = insereABB (raiz->dir, x,val);
}
return raiz;
}


noABB*  ABB::addABB (noABB* raiz,string  key, Item val){
    noABB *aux = buscaABB(raiz, key);
    if(aux != nullptr){
        aux->val.qtd_vzs ++;
        return raiz;
    }
    else{
        
        return insereABB(raiz, key,val);
    }
}

// Retorna o valor da key
int ABB::valueABB (noABB* raiz,string  key) {
    noABB *aux = buscaABB(raiz, key);
    if(aux != nullptr){
        return (aux->val.qtd_vzs);
    }
    else {
        return 0;
    }
}

void ABB::inOrdemABB (noABB *raiz) {

if (raiz != nullptr){
    inOrdemABB (raiz->esq);
    cout << raiz->key << " : " << raiz->val.qtd_vzs << " " << raiz->val.tam << " " <<raiz->val.numRepeticoes<<"\n";
    inOrdemABB (raiz->dir);
}
}

int ABB::maiorFABB(noABB* raiz){
    if(raiz == nullptr) return 0;
    int M, N ,Z; 
    M = N = Z = 0;
    if (raiz->val.qtd_vzs > M) M = raiz->val.qtd_vzs;
    N = maiorFABB (raiz->esq);
    Z = maiorFABB (raiz->dir);
    M = max(N,max(M,Z));
    return M;
}

void ABB::FordemABB(noABB* raiz, int F){
    if (raiz != nullptr){
    FordemABB (raiz->esq,F);
    if(raiz->val.qtd_vzs == F) cout << raiz->key << "\n";
    FordemABB (raiz->dir,F);
    }
}

int ABB::tamanhoMaiorPalavraSRABB(noABB* raiz, int x) {
    if (raiz == nullptr) {
        return 0;
    }
    
    int tamanhoMaior = 0;
            if (x != -1 && raiz->val.numRepeticoes != x && raiz->esq == nullptr && raiz->dir == nullptr) {
            return 0;
        }

        if (x == -1) {
            if (raiz->val.tam > tamanhoMaior) {
                tamanhoMaior = raiz->val.tam;
            }
        }
        else if (raiz->val.numRepeticoes == x && raiz->val.tam > tamanhoMaior) {
            tamanhoMaior = raiz->val.tam;
        }
    
    int tamanhoEsq = tamanhoMaiorPalavraSRABB(raiz->esq,x);
    int tamanhoDir = tamanhoMaiorPalavraSRABB(raiz->dir,x);
    if (tamanhoEsq > tamanhoMaior) {
        tamanhoMaior = tamanhoEsq;
    }
    if (tamanhoDir > tamanhoMaior) {
        tamanhoMaior = tamanhoDir;
    }
    return tamanhoMaior;
}

void ABB::imprimePalavrasSRABB(noABB* raiz, int TAM, int X) {
    if (raiz == nullptr) {
        return;
    }
    imprimePalavrasSRABB(raiz->esq, TAM, X);
    if (raiz->val.tam == TAM && raiz->val.numRepeticoes == X) {
        cout << raiz->key << endl;
    }
    imprimePalavrasSRABB(raiz->dir, TAM, X);
}


void ABB::imprimeTamABB(noABB* raiz, int tam){
    if (raiz != nullptr){
    imprimeTamABB (raiz->esq,tam);
    if(raiz->val.tam >= tam) cout << raiz->key << "\n";
    imprimeTamABB (raiz->dir,tam);
    }
}

int ABB::menorVDABB(noABB* raiz) {
    if (raiz == nullptr) {
        return 0;
    }
    int menorEsq = menorVDABB(raiz->esq);
    int menorDir = menorVDABB(raiz->dir);
    int x = raiz->esq != nullptr ? - raiz->esq->val.numVogaisRepetidas + raiz->esq->val.numVogais : 0;
    if(x<=0) x=0;
    int vogaisAtual = - raiz->val.numVogaisRepetidas + raiz->val.numVogais;
    if(vogaisAtual <= 0) vogaisAtual = 0;
    int maior = max(max(x , vogaisAtual), max(menorEsq, menorDir));
    return maior;
}

int ABB::menorTamanhoPalavraVDABB(noABB* raiz, int VD) {
    if (raiz == nullptr) {
        return 1e3;
    }
    
    int tamanhoEsq = menorTamanhoPalavraVDABB(raiz->esq, VD);
    int tamanhoDir = menorTamanhoPalavraVDABB(raiz->dir, VD);
    int tamanhoAtual = 1e3;
    
    int vogais = raiz->val.numVogais - raiz->val.numVogaisRepetidas;
    
    if (vogais == VD) {
        tamanhoAtual = raiz->key.size();
    }
    
    return min(min(tamanhoEsq, tamanhoDir), tamanhoAtual);
}

void ABB::imprimeVDABB(noABB* raiz,  int VD, int tam) {
    if (raiz == nullptr) {
        return;
    }

    // verificando se a palavra atende aos critérios
    //if(raiz->key == "aeioud") cout << raiz->val.tam << "==" << tam << "   " <<  raiz->val.numVogais - raiz->val.numVogaisRepetidas << "==" << VD << endl;
    if (raiz->val.numVogais - raiz->val.numVogaisRepetidas == VD && raiz->val.tam == tam) {
        cout << raiz->key << endl;
    }

    // percorrendo subárvore esquerda
    if (raiz->esq != nullptr) {
        imprimeVDABB(raiz->esq, tam, VD);
    }

    // percorrendo subárvore direita
    if (raiz->dir != nullptr) {
        imprimeVDABB(raiz->dir, tam, VD);
    }
}