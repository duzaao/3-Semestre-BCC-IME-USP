#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <iomanip>

using namespace std;


typedef int Key; // Tipo de dados da chave
typedef int Item; // Tipo de dados do valor

typedef struct No {
    bool is2no;
    Key ch1;
    Item val1;
    Key ch2;
    Item val2;
    No* p1;
    No* p2;
    No* p3;

   No(bool is2no, Key ch1, Item val1, Key ch2, Item val2, No* p1, No* p2, No* p3) : is2no(is2no), ch1(ch1), val1(val1), ch2(ch2), val2(val2), p1(p1), p2(p2), p3(p3) {}

} No;


 No* put23(No* raiz, Key key, Item val, bool &cresceu){
    if (raiz == nullptr) { // Caso 0 - Não tem nada
        raiz = new No(true, key, val, 0, 0, nullptr, nullptr, nullptr);
        cresceu = true;
        return raiz;
    }

    if (raiz->p1 != nullptr){  // Raiz não é folha


        if (raiz->ch1 > key) { // Caso 2 - Arvore ja tem 3 ou mais elementos
            No* p = put23(raiz->p1, key, val, cresceu);
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
                        if(p->ch1 < raiz->ch1){
                        No* novo = new No(true, p->ch1, p->val1, 0, 0, p->p1, nullptr, p->p3);
                        No* nraiz = new No(true, raiz->ch1, raiz->val1, 0, 0, novo, nullptr , raiz);
                        raiz->ch1 = raiz->ch2; 
                        raiz->val1 = raiz->val2;
                        raiz->p2 = nullptr;
                        raiz->ch2 = 0; 
                        raiz->val2 = 0;
                        novo->is2no = raiz->is2no = nraiz->is2no = true;
                        cresceu = true;
                        return nraiz;  
                        }

                 }
            }
            else return raiz;
        }
        else if (raiz->ch2 < key) {
                No* p = put23(raiz->p3, key, val, cresceu);
                if (cresceu) { // houve split
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

                        
                        No* novo = new No(true, p->ch1, p->val1, 0, 0, p->p1, nullptr, p->p3);
                        No* nraiz = new No(true, raiz->ch2, raiz->val2, 0, 0, raiz, nullptr , novo);
                        raiz->p3 = raiz->p2;
                        raiz->p2 = nullptr;
                        raiz->ch2 = 0; 
                        raiz->val2 = 0;
                        novo->is2no = raiz->is2no = nraiz->is2no = true;
                        cresceu = true;
                        return nraiz;  

                        

 
                    }
                }
                else return raiz;
            }
            else {
                No* p = put23(raiz->p2, key, val, cresceu);
                if(cresceu){
                        No* novo = new No(true, raiz->ch1, raiz->val1, 0, 0, raiz->p1, nullptr , p->p1);
                        No* nraiz = new No(true, p->ch1, p->val1, 0, 0,novo, nullptr, raiz);
                        raiz->ch1 = raiz->ch2; 
                        raiz->val1 = raiz->val2;
                        raiz->p1 = p->p3;
                        raiz->p2 = 0;
                        raiz->ch2 = 0; 
                        raiz->val2 = 0;
                        novo->is2no = raiz->is2no = nraiz->is2no = true;
                        cresceu = true;
                        return nraiz;  


                }
                else return raiz;
            }
    }
    else { // Caso 1 - Primeiros 3 elementos 
        
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
                No* novo = new No(true, raiz->ch2, raiz->val2, 0, 0, nullptr, nullptr, nullptr);
                No* nraiz = new No(true, raiz->ch1, raiz->val1, 0, 0, raiz,nullptr , novo);
                raiz->ch1 = key; 
                raiz->val1 = val;
                raiz->ch2 = 0; 
                raiz->val2 = 0;
                raiz->p3 = nullptr;
                raiz->p2 = nullptr;
                raiz->p1 = nullptr;
                novo->is2no = raiz->is2no = nraiz->is2no = true;
                cresceu = true;
                return nraiz;  
            }
            else if(raiz->ch2 < key){
                No* novo = new No(true, key, val, 0, 0, nullptr, nullptr, nullptr);
                No* nraiz = new No(true, raiz->ch2, raiz->val2, 0, 0, raiz, nullptr, novo);
                raiz->p2 = nullptr;
                raiz->ch2 = 0; 
                raiz->val2 = 0;
                raiz->p1 == nullptr;
                raiz->p3 = nullptr;
                novo->is2no = raiz->is2no = nraiz->is2no = true;
                cresceu = true;
                return nraiz;  
            }
            else{
                No* novo = new No(true, raiz->ch2, raiz->val2, 0, 0, nullptr, nullptr, nullptr);
                No* nraiz = new No(true, key, val, 0, 0, raiz, nullptr, novo);
                raiz->p2 = nullptr;
                raiz->p1 = nullptr;
                raiz->ch2 = 0; 
                raiz->val2 = 0;
                raiz->p3 = nullptr;
                novo->is2no = raiz->is2no = nraiz->is2no = true;
                cresceu = true;
                return nraiz;
            }

        }
        return raiz;
    }
    
} 




int main()
{
  No* raiz = nullptr;
  bool cresceu=0;
  
  raiz = put23(raiz, 8, 10, cresceu);
  raiz = put23(raiz, 10, 12, cresceu);
  cout << raiz->ch1 << raiz->ch2 << endl;
  raiz = put23(raiz, 7, 9, cresceu);
  cout << raiz->ch1 << "-"<<raiz->ch2 << endl;
  cout << raiz->p1->ch1 << "-" <<raiz->p1->ch2 << " "<< raiz->p3->ch1 << "-"<< raiz->p3->ch2 << endl;
  raiz = put23(raiz, 15, 18, cresceu);
    cout << raiz->ch1 << "-"<<raiz->ch2 << endl;
  cout << raiz->p1->ch1 << "-" <<raiz->p1->ch2 << " "<< raiz->p3->ch1 << "-"<< raiz->p3->ch2 << endl;
  raiz = put23(raiz, 6, 8, cresceu);
    cout << raiz->ch1 << "-"<<raiz->ch2 << endl;
  cout << raiz->p1->ch1 << "-" <<raiz->p1->ch2 << " "<< raiz->p3->ch1 << "-"<< raiz->p3->ch2 << endl;
  raiz = put23(raiz, 4, 5, cresceu);
      cout << raiz->ch1 << "-"<<raiz->ch2 << endl;
  cout << raiz->p1->ch1 << "-" <<raiz->p1->ch2 << " " << raiz->p2->ch1 << "-" <<raiz->p2->ch2 << " "<< raiz->p3->ch1 << "-"<< raiz->p3->ch2 << endl;
  raiz = put23(raiz, 12, 14, cresceu);
        cout << raiz->ch1 << "-"<<raiz->ch2 << endl;
  cout << raiz->p1->ch1 << "-" <<raiz->p1->ch2 << " "<< raiz->p3->ch1 << "-"<< raiz->p3->ch2 << endl;
    cout << raiz->p1->p1->ch1 << "-" <<raiz->p1->p1->ch2 << " " << raiz->p1->p3->ch1 << "-" <<raiz->p1->p3->ch2 << " "<< raiz->p3->p1->ch1 << "-" <<raiz->p3->p1->ch2 << " "<< raiz->p3->p3->ch1 << "-"<< raiz->p3->p3->ch2 << endl;

  raiz = put23(raiz, 18, 20, cresceu);
     cout << raiz->ch1 << "-"<<raiz->ch2 << endl;
  cout << raiz->p1->ch1 << "-" <<raiz->p1->ch2 << " "<< raiz->p3->ch1 << "-"<< raiz->p3->ch2 << endl;
    cout << raiz->p1->p1->ch1 << "-" <<raiz->p1->p1->ch2 << " " << raiz->p1->p3->ch1 << "-" <<raiz->p1->p3->ch2 << " "<< raiz->p3->p1->ch1 << "-" <<raiz->p3->p1->ch2 << " "<< raiz->p3->p3->ch1 << "-"<< raiz->p3->p3->ch2 << endl;
 raiz = put23(raiz, 20, 20, cresceu);
  cout << endl;
  cout << raiz->ch1 << "-"<<raiz->ch2 << endl;
  cout << raiz->p1->ch1 << "-" <<raiz->p1->ch2 << " "<< raiz->p3->ch1 << "-"<< raiz->p3->ch2 << endl;
    cout << raiz->p1->p1->ch1 << "-" <<raiz->p1->p1->ch2 << " " << raiz->p1->p3->ch1 << "-" <<raiz->p1->p3->ch2 << " "<< raiz->p3->p1->ch1 << "-" <<raiz->p3->p1->ch2 << " "<< raiz->p3->p2->ch1 << "-" <<raiz->p3->p2->ch2 << " "<< raiz->p3->p3->ch1 << "-"<< raiz->p3->p3->ch2 << endl;
  raiz = put23(raiz, 21, 21, cresceu);
  cout << endl;
  cout << raiz->ch1 << "-"<<raiz->ch2 << endl;
  cout << raiz->p1->ch1 << "-" <<raiz->p1->ch2 << " "<< raiz->p3->ch1 << "-"<< raiz->p3->ch2 << endl;
    cout << raiz->p1->p1->ch1 << "-" <<raiz->p1->p1->ch2 << " " << raiz->p1->p3->ch1 << "-" <<raiz->p1->p3->ch2 << " "<< raiz->p3->p1->ch1 << "-" <<raiz->p3->p1->ch2 << " "<< raiz->p3->p2->ch1 << "-" <<raiz->p3->p2->ch2 << " "<< raiz->p3->p3->ch1 << "-"<< raiz->p3->p3->ch2 << endl;
    raiz = put23(raiz, 22, 21, cresceu);

  return 0;
}