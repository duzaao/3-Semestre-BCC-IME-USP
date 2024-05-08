#include "TR.h"

TR::TR(){
   raiz = nullptr;
   tamanhoTR = 0;
}

noTR::noTR(){
         //Atribuindo uma prioridade aleatoria
        
         this->prior = rand()%100;
}

void TR::rotLeft(noTR* &root) { //left rotation
   noTR* R = root->dir;
   noTR* X = root->dir->esq;
   R->esq = root;
   root->dir= X;
   root = R;
}

void TR::rotRight(noTR* &root) { //right rotation
   noTR* L = root->esq;
   noTR* Y = root->esq->dir;
   L->dir = root;
   root->esq= Y;
   root = L;
}


void TR::insertNod(noTR* &root, string key, Item val) { //insertion
   if (root == nullptr) {
        root = new noTR();
        root->key = key;
        root->val = val;
        root->dir = root->esq = nullptr;
        tamanhoTR++;
        return;
   }
   if (key < root->key) {
      insertNod(root->esq, key, val);
      if (root->esq != nullptr && root->esq->prior > root->prior)
      rotRight(root);
   } else {
      insertNod(root->dir, key, val);
      if (root->dir!= nullptr && root->dir->prior > root->prior)
      rotLeft(root);
   }
}

void TR::inOrdem (noTR *raiz) {

if (raiz != nullptr){
    inOrdem (raiz->esq);
    cout << raiz->prior << ": "<<raiz->key << " : " << raiz->val.qtd_vzs << " " << raiz->val.tam << " " <<raiz->val.numRepeticoes<<"\n";
    inOrdem (raiz->dir);
}
}

noTR * TR::busca(noTR * raiz, string x){
    if(raiz == nullptr )
        return nullptr;
    if (x == raiz->key){
        //raiz->val.qtd_vzs++;
        return raiz;

    }
    if (x < raiz->key)
        return busca (raiz->esq, x);
    return busca (raiz->dir, x);
    }

int TR::maiorF(noTR* raiz){
    if(raiz == nullptr) return 0;
    int M, N ,Z; 
    M = N = Z = 0;
    if (raiz->val.qtd_vzs > M) M = raiz->val.qtd_vzs;
    N = maiorF (raiz->esq);
    Z = maiorF (raiz->dir);
    M = max(N,max(M,Z));
    return M;
}

void TR::Fordem(noTR* raiz, int F){
    if (raiz != nullptr){
    Fordem (raiz->esq,F);
    if(raiz->val.qtd_vzs == F) cout << raiz->key << "\n";
    Fordem (raiz->dir,F);
    }
}

int TR::tamanhoMaiorPalavraSR(noTR* raiz, int x) {
    if (raiz == nullptr) {
        return 0;
    }
    if(x != -1 && raiz->val.numRepeticoes != x && raiz->esq == nullptr && raiz->dir == nullptr){
        return 0;
    }
    int tamanhoMaior = 0;
    if(raiz->val.tam > tamanhoMaior){
        tamanhoMaior = raiz->val.tam;
    }
    int tamanhoEsq = tamanhoMaiorPalavraSR(raiz->esq,x);
    int tamanhoDir = tamanhoMaiorPalavraSR(raiz->dir,x);
    if (tamanhoEsq > tamanhoMaior) {
        tamanhoMaior = tamanhoEsq;
    }
    if (tamanhoDir > tamanhoMaior) {
        tamanhoMaior = tamanhoDir;
    }
    return tamanhoMaior;
}

void TR::imprimePalavrasSR(noTR* raiz, int TAM, int X) {
    if (raiz == nullptr) {
        return;
    }
    imprimePalavrasSR(raiz->esq, TAM, X);
    if (raiz->val.tam == TAM && raiz->val.numRepeticoes == X) {
        cout << raiz->key << endl;
    }
    imprimePalavrasSR(raiz->dir, TAM, X);
}


void TR::imprimeTam(noTR* raiz, int tam){
    if (raiz != nullptr){
    imprimeTam (raiz->esq,tam);
    if(raiz->val.tam >= tam) cout << raiz->key << "\n";
    imprimeTam (raiz->dir,tam);
    }
}

int TR::menorVD(noTR* raiz) {
    if (raiz == nullptr) {
        return 0;
    }
    int menorEsq = menorVD(raiz->esq);
    int menorDir = menorVD(raiz->dir);
    int x = raiz->esq != nullptr ? - raiz->esq->val.numVogaisRepetidas + raiz->esq->val.numVogais : 0;
    if(x<=0) x=0;
    int vogaisAtual = - raiz->val.numVogaisRepetidas + raiz->val.numVogais;
    if(vogaisAtual <= 0) vogaisAtual = 0;
    int maior = max(max(x , vogaisAtual), max(menorEsq, menorDir));
    return maior;
}

int TR::menorTamanhoPalavraVD(noTR* raiz, int VD) {
    if (raiz == nullptr) {
        return 1e3;
    }
    
    int tamanhoEsq = menorTamanhoPalavraVD(raiz->esq, VD);
    int tamanhoDir = menorTamanhoPalavraVD(raiz->dir, VD);
    int tamanhoAtual = 1e3;
    
    int vogais = raiz->val.numVogais - raiz->val.numVogaisRepetidas;
    
    if (vogais == VD) {
        tamanhoAtual = raiz->key.size();
    }
    
    return min(min(tamanhoEsq, tamanhoDir), tamanhoAtual);
}

void TR::imprimeVD(noTR* raiz,  int VD, int tam) {
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
        imprimeVD(raiz->esq, tam, VD);
    }

    // percorrendo subárvore direita
    if (raiz->dir != nullptr) {
        imprimeVD(raiz->dir, tam, VD);
    }
}