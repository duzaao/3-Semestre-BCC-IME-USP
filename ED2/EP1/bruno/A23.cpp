
#include "A23.h"
using namespace std;



no* A23::put23(no* raiz, Key key, Item val, bool &cresceu)
{
    if (raiz == nullptr) { // Caso 0 - Não tem nada
        raiz = new no(true, key, val, "", Item(), nullptr, nullptr, nullptr);
        cresceu = true;
        return raiz;
    }

    if (raiz->p1 != nullptr){  // Raiz não é folha

        // Caso 2 - Arvore ja tem 3 ou mais elementos
        if (raiz->ch1 > key) { // Caso 2.1 - key é menor de tds
            no* p = put23(raiz->p1, key, val, cresceu);
            if (cresceu) { // houve split
                if (raiz->is2no) {


                    
                    raiz->ch2 = raiz->ch1;
                    raiz->val2 = raiz->val1;
                    raiz->p3 = raiz->p3;
                    raiz->ch1 = p->ch1;
                    raiz->val1 = p->val1;
                    raiz->p2 = p->p3;
                    raiz->p1 = p->p1;
                    cresceu = false;
                    raiz->is2no = false;
                    delete (p);
                    return raiz;
                    

                }
                else { /* raiz é um 3 nó */
                        
                        no* novo = new no(true, p->ch1, p->val1, "", Item(), p->p1, nullptr, p->p3);
                        no* nraiz = new no(true, raiz->ch1, raiz->val1, "",  Item(), novo, nullptr , raiz);
                        raiz->ch1 = raiz->ch2; 
                        raiz->val1 = raiz->val2;
                        raiz->p2 = nullptr;
                        raiz->ch2 = ""; 
                        raiz->val2 =  Item();
                        novo->is2no = raiz->is2no = nraiz->is2no = true;
                        cresceu = true;
                        return nraiz;  
                        

                 }
            }
            else return raiz;
        }
        else if (raiz->ch2 < key) { // Caso 2.2 - key é maior de tds
                no* p = put23(raiz->p3, key, val, cresceu);
                if (cresceu) { 
                    if (raiz->is2no) {
                        raiz->ch2 = p->ch1;
                        raiz->val2 = p->val1;
                        raiz->p2 = raiz->p3;
                        raiz->p3 = p->p3;
                        cresceu = false;
                        raiz->is2no = false;
                        return raiz;
                    }
                    else { /* raiz é um 3 nó, cresceu e temos que criar uma nova raiz */

                        
                        no* novo = new no(true, p->ch1, p->val1, "", Item(), p->p1, nullptr, p->p3);
                        no* nraiz = new no(true, raiz->ch2, raiz->val2, "", Item(), raiz, nullptr , novo);
                        raiz->p3 = raiz->p2;
                        raiz->p2 = nullptr;
                        raiz->ch2 = ""; 
                        raiz->val2 = Item();
                        novo->is2no = raiz->is2no = nraiz->is2no = true;
                        cresceu = true;
                        return nraiz;  

                        

 
                    }
                }
                else return raiz;
            }
             
             else { // Caso 2.2 - key é intermediario
                no* p = put23(raiz->p2, key, val, cresceu);
                if(cresceu){
                        no* novo = new no(true, raiz->ch1, raiz->val1, "", Item(), raiz->p1, nullptr , p->p1);
                        no* nraiz = new no(true, p->ch1, p->val1, "", Item(),novo, nullptr, raiz);
                        raiz->ch1 = raiz->ch2; 
                        raiz->val1 = raiz->val2;
                        raiz->p1 = p->p3;
                        raiz->p2 = nullptr;
                        raiz->ch2 = ""; 
                        raiz->val2 = Item();
                        novo->is2no = raiz->is2no = nraiz->is2no = true;
                        cresceu = true;
                        return nraiz;  


                }
                else return raiz;
            }
    
        
    
    
    
    
    }
    else { // Caso 1 - Primeiros 3 elementos (Bruno, esse ta funcionando de boa ok)
        
        if(raiz->is2no){    
            if(key < raiz->ch1){
                raiz->ch2 = raiz->ch1;
                raiz->val2 = raiz->val1;
                raiz->ch1 = key;
                raiz->val1 = val;
                raiz->is2no = false;
                cresceu = false;
            }
            else{
                raiz->ch2 = key;
                raiz->val2 = val;
                raiz->is2no = false;
                cresceu = false;

            }
        }
        else{ // se a raiz for folha e for um 3 nó
            if(raiz->ch1 > key){
                no* novo = new no(true, raiz->ch2, raiz->val2, "", Item(), nullptr, nullptr, nullptr);
                no* nraiz = new no(true, raiz->ch1, raiz->val1, "", Item(), raiz,nullptr , novo);
                raiz->ch1 = key; 
                raiz->val1 = val;
                raiz->ch2 = ""; 
                raiz->val2 = Item();
                raiz->p3 = nullptr;
                raiz->p2 = nullptr;
                raiz->p1 = nullptr;
                novo->is2no = raiz->is2no = nraiz->is2no = true;
                cresceu = true;
                return nraiz;  
            }
            else if(raiz->ch2 < key){
                no* novo = new no(true, key, val, "", Item(), nullptr, nullptr, nullptr);
                no* nraiz = new no(true, raiz->ch2, raiz->val2, "", Item(), raiz, nullptr, novo);
                raiz->p2 = nullptr;
                raiz->ch2 = ""; 
                raiz->val2 = Item();
                raiz->p1 == nullptr;
                raiz->p3 = nullptr;
                novo->is2no = raiz->is2no = nraiz->is2no = true;
                cresceu = true;
                return nraiz;  
            }
            else{
                no* novo = new no(true, raiz->ch2, raiz->val2, "", Item(), nullptr, nullptr, nullptr);
                no* nraiz = new no(true, key, val, "", Item(), raiz, nullptr, novo);
                raiz->p2 = nullptr;
                raiz->p1 = nullptr;
                raiz->ch2 = ""; 
                raiz->val2 = Item();
                raiz->p3 = nullptr;
                novo->is2no = raiz->is2no = nraiz->is2no = true;
                cresceu = true;
                return nraiz;
            }

        }
        return raiz;
    }
}

void A23::inOrder(no* raiz){
    if(raiz != nullptr){
        inOrder(raiz->p1);
        cout << raiz->ch1;
        if(raiz->p1 != nullptr ) cout << "  filho 1 - "<<raiz->p1->ch1;
        if(raiz->p3 != nullptr ) cout << "  filho 2 - "<< raiz->p3->ch1; 

        cout << endl;
        if(!raiz->is2no){
            inOrder(raiz->p2);
            cout << raiz->ch2 ;
            cout << endl;
        }
        inOrder(raiz->p3);
    }
}

int A23::maiorF(no* raiz) {
    if(raiz == nullptr) {
        return 0;
    }
    int M = raiz->val1.qtd_vzs;
    int N = maiorF(raiz->p1);
    int Z = 0, X = 0;
    int maximo = max(M,N);

    if(!raiz->is2no) {
        X = raiz->val2.qtd_vzs;
        maximo = max(maximo,X);
        Z = maiorF(raiz->p2);
        maximo = max(maximo,Z);
    }

    Z = maiorF(raiz->p3);
    M = max(maximo,Z);

    return M;
}


void A23::Fordem(no* raiz, int F){
    if (raiz != nullptr){
    Fordem (raiz->p1,F);
    if(raiz->val1.qtd_vzs == F) cout << raiz->ch1 << "\n";
    if(!raiz->is2no){Fordem (raiz->p2,F); if(raiz->val2.qtd_vzs == F) cout << raiz->ch2 << "\n"; }
    Fordem (raiz->p3,F);
    }
}

no* A23::busca(no* raiz, string x) {
    if (raiz == nullptr) {
        return nullptr;
    }
    if (raiz->is2no) { // Caso 1: nó 2-nó
        if (x == raiz->ch1) {
            return raiz;
        } else if (x < raiz->ch1) {
            return busca(raiz->p1, x);
        } else {
            return busca(raiz->p3, x);
        }
    } else { // Caso 2: nó 3-nó
        if (x == raiz->ch1) {
            return raiz;
        } else if (x == raiz->ch2) {
            return raiz;
        } else if (x < raiz->ch1) {
            return busca(raiz->p1, x);
        } else if (x < raiz->ch2) {
            return busca(raiz->p2, x);
        } else {
            return busca(raiz->p3, x);
        }
    }
}

int A23::tamanhoMaiorPalavraSR(no* raiz, int x) {
    if (raiz == nullptr) {
        return 0;
    }
    int tamanhoMaior = 0;

    if (raiz->is2no) {
        if (x != -1 && raiz->val1.numRepeticoes != x && raiz->p1 == nullptr) {
            return 0;
        }

        if (x == -1) {
            if (raiz->val1.tam > tamanhoMaior) {
                tamanhoMaior = raiz->val1.tam;
            }
        }
        else if (raiz->val1.numRepeticoes == x && raiz->val1.tam > tamanhoMaior) {
            tamanhoMaior = raiz->val1.tam;
        }
    }
    else {
        if (x != -1 && raiz->val1.numRepeticoes != x && raiz->p1 == nullptr) {
            return 0;
        }

        if (x == -1) {
            if (raiz->val1.tam > tamanhoMaior) {
                tamanhoMaior = raiz->val1.tam;
            }
            if (raiz->val2.tam > tamanhoMaior) {
                tamanhoMaior = raiz->val2.tam;
            }
        }
        else if (raiz->val1.numRepeticoes == x && raiz->val1.tam > tamanhoMaior) {
            tamanhoMaior = raiz->val1.tam;
        }
        else if (raiz->val2.numRepeticoes == x && raiz->val2.tam > tamanhoMaior) {
            tamanhoMaior = raiz->val2.tam;
        }
    }

    int tamanhoEsq = tamanhoMaiorPalavraSR(raiz->p1, x);
    int tamanhoMeio = 0;
    int tamanhoDir = tamanhoMaiorPalavraSR(raiz->p3, x);

    if (!raiz->is2no) {
        tamanhoMeio = tamanhoMaiorPalavraSR(raiz->p2, x);
    }

    if (tamanhoEsq > tamanhoMaior) {
        tamanhoMaior = tamanhoEsq;
    }
    if (tamanhoMeio > tamanhoMaior) {
        tamanhoMaior = tamanhoMeio;
    }
    if (tamanhoDir > tamanhoMaior) {
        tamanhoMaior = tamanhoDir;
    }

    return tamanhoMaior;
}


void A23::imprimeTam(no* raiz,int tam){
    if(raiz != nullptr){
        inOrder(raiz->p1);

        if(raiz->val1.tam == tam ) cout << raiz->ch1  << endl;
        if(!raiz->is2no){
            inOrder(raiz->p2);
            if(raiz->val2.tam == tam ) cout << raiz->ch2 << endl;
        }
        inOrder(raiz->p3);
    }
}

void A23::imprimePalavrasSR(no* raiz, int TAM, int X) {
    if (raiz == nullptr) {
        return;
    }
    imprimePalavrasSR(raiz->p1, TAM, X);
    if (raiz->is2no) {
        if (raiz->val1.tam == TAM && raiz->val1.numRepeticoes == X) {
            cout << raiz->ch1 << endl;
        }
    } else {
        if (raiz->val1.tam == TAM && raiz->val1.numRepeticoes == X) {
            cout << raiz->ch1 << endl;
        }
        imprimePalavrasSR(raiz->p2, TAM, X);
        if (raiz->val2.tam == TAM && raiz->val2.numRepeticoes == X) {
            cout << raiz->ch2 << endl;
        }

    }
    imprimePalavrasSR(raiz->p3, TAM, X);
}

int A23::menorVD(no* raiz) {
    if (raiz == nullptr) {
        return 0;
    }
    int menorMeio;
    int menorEsq = menorVD(raiz->p1);
    int menorDir = menorVD(raiz->p3);

    int x = 0;
    if (raiz->p1 != nullptr) {
        if (raiz->p1->is2no) {
            x = -raiz->p1->val1.numVogaisRepetidas + raiz->p1->val1.numVogais;
        } else {
            x = -raiz->p1->val2.numVogaisRepetidas + raiz->p1->val2.numVogais;
        }
        if (x <= 0) {
            x = 0;
        }
    }

    int vogaisAtual = -raiz->val1.numVogaisRepetidas + raiz->val1.numVogais;
    if (vogaisAtual <= 0) {
        vogaisAtual = 0;
    }

    int vogaisAtual2 = 0;
    if (!raiz->is2no) {
        
        if (raiz->p2->is2no) {
            vogaisAtual2 = -raiz->p2->val1.numVogaisRepetidas + raiz->p2->val1.numVogais;
        } else {
            vogaisAtual2 = -raiz->p2->val2.numVogaisRepetidas + raiz->p2->val2.numVogais;
        }
        if (vogaisAtual2 <= 0) {
            vogaisAtual2 = 0;
        }
        
    }

    int maior = max(max(x, vogaisAtual), max(menorEsq, menorDir));
    if (!raiz->is2no) {
        maior = max(maior, vogaisAtual2);
    }
    return maior;
}


int A23::menorTamanhoPalavraVD(no* raiz, int VD) {
    if (raiz == nullptr) {
        return 1e3;
    }
    int tamanhoMeio;
    int tamanhoEsq = menorTamanhoPalavraVD(raiz->p1, VD);
    if(!raiz->is2no) tamanhoMeio = menorTamanhoPalavraVD(raiz->p2, VD); 
    int tamanhoDir = menorTamanhoPalavraVD(raiz->p3, VD);
    int tamanhoAtual = 1e3;
    int vogais,vogais2;

    if(raiz->is2no){
        vogais = raiz->val1.numVogais - raiz->val1.numVogaisRepetidas;
        
        if (vogais == VD) {
            tamanhoAtual = raiz->ch1.size();
        }
    }

    else{
        vogais = raiz->val1.numVogais - raiz->val1.numVogaisRepetidas;
        
        if (vogais == VD) {
            tamanhoAtual = raiz->ch1.size();
        }
        int tamanhoAtual2;
        vogais2 = raiz->val2.numVogais - raiz->val2.numVogaisRepetidas;
        if (vogais2 == VD) {
            tamanhoAtual2 = raiz->ch1.size();
        }
        tamanhoAtual = min(tamanhoAtual,tamanhoAtual2);
    }

    return min(min(tamanhoEsq, tamanhoDir), tamanhoAtual);
}


void A23::imprimeVD(no* raiz,  int tam, int VD) {
    if (raiz == nullptr) {
        return;
    }

    if(raiz->is2no){
        if (raiz->val1.numVogais - raiz->val1.numVogaisRepetidas == VD && raiz->val1.tam == tam) {
        cout << raiz->ch1 << endl;
        }
    }
    else {
        if (raiz->val1.numVogais - raiz->val1.numVogaisRepetidas == VD && raiz->val1.tam == tam) {
        cout << raiz->ch1 << endl;
        }
        if (raiz->val2.numVogais - raiz->val2.numVogaisRepetidas == VD && raiz->val2.tam == tam) {
        cout << raiz->ch2 << endl;
        }
    }
        imprimeVD(raiz->p1, tam, VD);
        if(!raiz->is2no) imprimeVD(raiz->p2, tam, VD);
        imprimeVD(raiz->p3, tam, VD);
    
}