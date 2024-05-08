#include "ARB.h"

noARB:: noARB(){}

void ARB::insere_ARB(string key, Item val) 
{ 
    noARB *z = new noARB; 
    z->key = key; 
    z->val = val; 
    z->esq = nullptr; 
    z->dir = nullptr; 
    z->color = RED; 
  
    noARB *y = nullptr; 
    noARB *x = this->raiz; 
  
    while (x != nullptr) { 
        y = x; 
        if (z->key < x->key) 
            x = x->esq; 
        else
            x = x->dir; 
    } 
  
    z->pai = y; 
    if (y == nullptr) 
        this->raiz = z; 
  
    else if (z->key < y->key) 
        y->esq = z; 
    else
        y->dir = z; 
  
    inserirFixup_ARB(this, z); 
}

  
void ARB::inserirFixup_ARB(ARB *T, noARB *z) 
{ 
    noARB *y; 
    while (z->pai != nullptr && z->pai->color == RED) { 
  
        if (z->pai == z->pai->pai->esq) { 
            y = z->pai->pai->dir;
            if(y == nullptr){
                if (z == z->pai->dir) { 
                    z = z->pai; 
                    esqRotate_ARB(T, z); 
                } 
  
                z->pai->color = BLACK; 
                z->pai->pai->color = RED; 
                dirRotate_ARB(T, z->pai->pai); 
            } 
            else if (y->color == RED) { 
                z->pai->color = BLACK; 
                y->color = BLACK; 
                z->pai->pai->color = RED; 
                z = z->pai->pai; 
            } 
            else { 
                if (z == z->pai->dir) { 
                    z = z->pai; 
                    esqRotate_ARB(T, z); 
                } 
  
                z->pai->color = BLACK; 
                z->pai->pai->color = RED; 
                dirRotate_ARB(T, z->pai->pai); 
            } 
        } 
        else { 
            y = z->pai->pai->esq; 
            if(y == nullptr){
                if (z == z->pai->esq) { 
                    z = z->pai; 
                    dirRotate_ARB(T, z); 
                } 
                z->pai->color = BLACK; 
                z->pai->pai->color = RED; 
                esqRotate_ARB(T, z->pai->pai); 
            }
            else if (y->color == RED) { 
                z->pai->color = BLACK; 
                y->color = BLACK; 
                z->pai->pai->color = RED; 
                z = z->pai->pai; 
            } 
            else { 
                if (z == z->pai->esq) { 
                    z = z->pai; 
                    dirRotate_ARB(T, z); 
                } 
                z->pai->color = BLACK; 
                z->pai->pai->color = RED; 
                esqRotate_ARB(T, z->pai->pai); 
            } 
        } 
    } 
    T->raiz->color = BLACK; 
} 
  
void ARB::esqRotate_ARB(ARB *T, noARB *x) 
{ 
    noARB *y = x->dir; 
    x->dir = y->esq; 
    if (y->esq != nullptr) 
        y->esq->pai = x; 
    y->pai = x->pai; 
    if (x->pai == nullptr) 
        T->raiz = y; 
    else if (x == x->pai->esq) 
        x->pai->esq = y; 
    else
        x->pai->dir = y; 
    y->esq = x; 
    x->pai = y; 
} 
  
void ARB::dirRotate_ARB(ARB *T, noARB *x) 
{ 
    noARB *y = x->esq; 
    x->esq = y->dir; 
    if (y->dir != nullptr) 
        y->dir->pai = x; 
    y->pai = x->pai; 
    if (x->pai == nullptr) 
        T->raiz = y; 
    else if (x == x->pai->dir) 
        x->pai->dir = y; 
    else
        x->pai->esq = y; 
    y->dir = x; 
    x->pai = y; 
}

void ARB::inOrdem_ARB (noARB *raiz) {

if (raiz != nullptr){
    inOrdem_ARB (raiz->esq);
    cout << raiz->key << " "<< raiz->val.qtd_vzs << " " << raiz->val.numRepeticoes << " ";
    if(raiz->color == RED) cout << "red" << endl;
        if(raiz->color == BLACK) cout << "blck" << endl;

    inOrdem_ARB (raiz->dir);
}
}

noARB * ARB::busca_ARB(noARB * raiz, string x){
    if(raiz == nullptr )
        return nullptr;
    if (x == raiz->key){
        //raiz->val.qtd_vzs++;
        return raiz;

    }
    if (x < raiz->key)
        return busca_ARB (raiz->esq, x);
    return busca_ARB (raiz->dir, x);
}


int ARB::maiorF_ARB(noARB* raiz){
    if(raiz == nullptr) return 0;
    int M, N ,Z; 
    M = N = Z = 0;
    if (raiz->val.qtd_vzs > M) M = raiz->val.qtd_vzs;
    N = maiorF_ARB (raiz->esq);
    Z = maiorF_ARB (raiz->dir);
    M = max(N,max(M,Z));
    return M;
}

void ARB::Fordem_ARB(noARB* raiz, int F){
    if (raiz != nullptr){
    Fordem_ARB (raiz->esq,F);
    if(raiz->val.qtd_vzs == F) cout << raiz->key << "\n";
    Fordem_ARB (raiz->dir,F);
    }
}

int ARB::tamanhoMaiorPalavraSR_ARB(noARB* raiz, int x) {
    if (raiz == nullptr) {
        return 0;
    }
    if(x != -1 && raiz->val.numRepeticoes != x && raiz->esq == nullptr && raiz->dir == nullptr){
        return 0;
    }
    int tamanhoMaior = 0;
    if(x==-1){
        if(raiz->val.tam > tamanhoMaior) tamanhoMaior = raiz->val.tam;
    }
    else if((raiz->val.tam > tamanhoMaior)&&raiz->val.numRepeticoes == x){
        tamanhoMaior = raiz->val.tam;
    }
    int tamanhoEsq = tamanhoMaiorPalavraSR_ARB(raiz->esq,x);
    int tamanhoDir = tamanhoMaiorPalavraSR_ARB(raiz->dir,x);
    if (tamanhoEsq > tamanhoMaior) {
        tamanhoMaior = tamanhoEsq;
    }
    if (tamanhoDir > tamanhoMaior) {
        tamanhoMaior = tamanhoDir;
    }
    return tamanhoMaior;
}

void ARB::imprimePalavrasSR_ARB(noARB* raiz, int TAM, int X) {
    if (raiz == nullptr) {
        return;
    }
    imprimePalavrasSR_ARB(raiz->esq, TAM, X);
    if (raiz->val.tam == TAM && raiz->val.numRepeticoes == X) {
        cout << raiz->key << endl;
    }
    imprimePalavrasSR_ARB(raiz->dir, TAM, X);
}


void ARB::imprimeTam_ARB(noARB* raiz, int tam){
    if (raiz != nullptr){
    imprimeTam_ARB (raiz->esq,tam);
    if(raiz->val.tam >= tam) cout << raiz->key << "\n";
    imprimeTam_ARB (raiz->dir,tam);
    }
}

int ARB::menorVD_ARB(noARB* raiz) {
    if (raiz == nullptr) {
        return 0;
    }
    int menorEsq = menorVD_ARB(raiz->esq);
    int menorDir = menorVD_ARB(raiz->dir);
    int x = raiz->esq != nullptr ? - raiz->esq->val.numVogaisRepetidas + raiz->esq->val.numVogais : 0;
    if(x<=0) x=0;
    int vogaisAtual = - raiz->val.numVogaisRepetidas + raiz->val.numVogais;
    if(vogaisAtual <= 0) vogaisAtual = 0;
    int maior = max(max(x , vogaisAtual), max(menorEsq, menorDir));
    return maior;
}

int ARB::menorTamanhoPalavraVD_ARB(noARB* raiz, int VD) {
    if (raiz == nullptr) {
        return 1e3;
    }
    
    int tamanhoEsq = menorTamanhoPalavraVD_ARB(raiz->esq, VD);
    int tamanhoDir = menorTamanhoPalavraVD_ARB(raiz->dir, VD);
    int tamanhoAtual = 1e3;
    
    int vogais = raiz->val.numVogais - raiz->val.numVogaisRepetidas;
    
    if (vogais == VD) {
        tamanhoAtual = raiz->key.size();
    }
    
    return min(min(tamanhoEsq, tamanhoDir), tamanhoAtual);
}

void ARB::imprimeVD_ARB(noARB* raiz,  int tam, int VD) {
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
        imprimeVD_ARB(raiz->esq, tam, VD);
    }

    // percorrendo subárvore direita
    if (raiz->dir != nullptr) {
        imprimeVD_ARB(raiz->dir, tam, VD);
    }
}

bool ARB::rubroNegraOk_ARB(noARB* raiz) {
    if (raiz == nullptr) {
        // Propriedade 3: todas as folhas são pretas
        return true;
    }

    if (raiz->color == RED) {
        // Propriedade 4: se um nó é vermelho, então seus filhos são pretos
        if ((raiz->esq->color == RED) ||
            (raiz->dir->color == RED)) {
                cout << "pai vermelho com filho vermelho" << endl;
            return false;
        }
    }

    // Propriedades 1 e 2: todo nó é preto ou vermelho e a raiz é preta
    return true;
}

int ARB::blckCount_ARB(noARB* root, int count, int& prevCount, bool& sameBlackCount) {
    if (root == nullptr) {
        // Se chegamos a uma folha, verifica se o número de nós pretos nesse caminho é o mesmo que o dos caminhos anteriores
        if (prevCount == -1) {
            prevCount = count;
            sameBlackCount = true;
        } else if (count != prevCount) {
            sameBlackCount = false;
        }
        return 0;
    }

    int blackCountLeft = blckCount_ARB(root->esq, count + (root->color == BLACK ? 1 : 0), prevCount, sameBlackCount);
    int blackCountRight = blckCount_ARB(root->dir, count + (root->color == BLACK ? 1 : 0), prevCount, sameBlackCount);
        return blackCountLeft + blackCountRight + (root->color == BLACK ? 1 : 0);
}

bool ARB::blackCount_ARB(noARB* root) {
    int prevCount = -1;
    bool sameBlackCount = true;
    blckCount_ARB(root, 0, prevCount, sameBlackCount);
    return sameBlackCount ? 1 : 0;
}
