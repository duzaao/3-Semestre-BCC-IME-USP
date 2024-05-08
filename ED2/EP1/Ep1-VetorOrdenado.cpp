#include <iostream>
#include <fstream>
#include <algorithm> 
#include <string> 
#include <cstring>
#include <vector>

using namespace std;

struct Item { 
    string key;
    int tam; 
    int value;
    int numVogais;
    int numVogaisRepetidas;
}; 

vector<Item> itemVec; 

// Função para adicionar um item e sua chave no vetor ordenado
void add(string key, int val) 
{ 
    Item item; 
    item.key = key; 
    item.value = val; 
    item.tam = key.length();
    
    int contVogais = 0;

    for(int i = 0; i < key.length(); i++){
        if(key[i] == 'a' || key[i] == 'e' || key[i] == 'i' || key[i] == 'o' || key[i] == 'u')
            {
                contVogais++;
            }

    }


    item.numVogais = contVogais;

    int vog[5];
    vog[0] =vog[1] = vog[2] = vog[3] = vog[4] = -1;
    for(int i=0;i<key.length();i++){
        if(key[i] == 'a') vog[0]++;
        if(key[i] == 'e') vog[1]++;
        if(key[i] == 'i') vog[2]++;
        if(key[i] == 'o') vog[3]++;
        if(key[i] == 'u') vog[4]++;
        
    }
        if(vog[0] == -1) vog[0] = 0; 
        if(vog[1] == -1) vog[1] = 0; 
        if(vog[2] == -1) vog[2] = 0; 
        if(vog[3] == -1) vog[3] = 0; 
        if(vog[4] == -1) vog[4] = 0; 

    int somaRep = vog[0] + vog[1] + vog[2] + vog[3] + vog[4];
    item.numVogaisRepetidas = somaRep;
  
    // Inserir na posição correta para manter o vetor ordenado 
    int pos = 0;
    while (pos < itemVec.size() && itemVec[pos].key < key) 
        pos++; 
    itemVec.insert(itemVec.begin() + pos, item); 
} 

// Função para buscar um item dado sua chave
int value(string key) 
{ 
    // Pesquisar na posição correta para manter o vetor ordenado 
    int pos = 0; 
    while (pos < itemVec.size() && itemVec[pos].key < key) 
        pos++; 
  
    // Retornar -1 se a chave não for encontrada 
    if (pos == itemVec.size() || itemVec[pos].key != key) 
        return -1; 
    
    itemVec[pos].value++;
    return itemVec[pos].value; 
}

/* Verifica se A<=B e retorna 1 se é menor ou 0 se não é menor */
int comparaString(char *A , char *B){
  int i, j=0;
  int x, y,z;
  x= strlen(A);
  y= strlen(B);
  if(x<y) z = x;
  else z = y;
  for (i = 0; i< z;i++){
    if(A[i]==B[i]) {j++;continue;}
    if(A[i]<B[i]) return 1;
    return 0;
  }
  if(j==z){
    if(x>=y) return 0;
  }
  return 1;
} 

/*int main(int argc, char* argv[]) 
{ 
    if(argc < 2){
        cout << "Arquivo não especificado!" << endl;
        return 0;
    }

    string fileName = argv[1];
*/
    // Ler o arquivo
void insertInSortedArray(string arr[], int& size, const string& word) {
    int left = 0;
    int right = size - 1;
    int index = size;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= word)
            left = mid + 1;
        else {
            index = mid;
            right = mid - 1;
        }
    }

    for (int i = size; i < index; i--)
        if(i-1 > 0)
            arr[i] = arr[i - 1];

    arr[index] = word;
    size++;
}

int main() {
    string fileName = "texto.txt";
    ifstream file;
    string line;
    int Q;
    int maiorFreq = 0;
    cin >> Q;
    file.open(fileName);
    if (file.is_open()) {
        string* palavras = new string[Q]; // Usando um array dinâmico de tamanho Q
        int palavrasSize = 0;

        while (getline(file, line)) {
            string palavra;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == ' ') {
                    insertInSortedArray(palavras, palavrasSize, palavra);
                    palavra = "";
                } else {
                    palavra += line[i];
                }
            }
            insertInSortedArray(palavras, palavrasSize, palavra);
        }

        for (int j = 0; j < palavrasSize; j++)
            cout << palavras[j] << " ";

        delete[] palavras; // Liberando a memória alocada

    } else {
        cout << "Arquivo não encontrado!" << endl;
        return 0;
    }

  
    // Exibir os resultados 
    /*for (int i = 0; i < itemVec.size(); i++) { 
        cout << itemVec[i].key << ": tamanho = " << itemVec[i].tam << "; numero de vezes = " << itemVec[i].value << "; numero de vogais = " << itemVec[i].numVogais << "; numero de vogais repetidas = "<< itemVec[i].numVogaisRepetidas << endl; 
    } */
    for (int i = 0; i < itemVec.size(); i++) {
            if(itemVec[i].value > maiorFreq) maiorFreq = itemVec[i].value; 
        }
    string x;
    for(int k = 0; k< Q+1; k++){
        getline(cin, x);

        if(x[0] == 'F'){
            for (int i = 0; i < itemVec.size(); i++) { 
                if(itemVec[i].value == maiorFreq) cout << itemVec[i].key << "  ";
            }
            cout << endl;
        }
        else if (x[0] == 'O') {
            x.erase(0,2);
            int freq = value(x);
            if(freq == -1) {
                cout << "Não ocorre" << endl;
                continue;
            }
            cout << x << " ocorre " <<freq << " vez(es)"<<  endl;
        }
        else if (x[0] == 'L') {
            int maxTam = 0;
            for (int i = 0; i < itemVec.size(); i++) {
                if(itemVec[i].tam > maxTam) maxTam = itemVec[i].tam;
            }
            for (int i = 0; i < itemVec.size(); i++) {
                if(itemVec[i].tam == maxTam) cout << itemVec[i].key << "  ";
            }
        }
        else if (x[0] == 'S' && x[1] == 'R') {
            int maxTam = 0;
            for (int i = 0; i < itemVec.size(); i++) {
                if(itemVec[i].tam > maxTam && itemVec[i].numVogaisRepetidas == 0) maxTam = itemVec[i].tam;
            }
            for (int i = 0; i < itemVec.size(); i++) {
                if(itemVec[i].tam == maxTam && itemVec[i].numVogaisRepetidas == 0) cout << itemVec[i].key << "  ";
            }
        }
        else if (x[0] == 'V' && x[1] == 'D') {
            string z = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaazzzzzzzzzzzzzzzzzza";
            int nMax = 0;
            int nAnterior=0;
            for (int i = 0; i < itemVec.size(); i++) {
                if(itemVec[i].key == "aeio")         cout << itemVec[i].key << ": tamanho = " << itemVec[i].tam << "; numero de vezes = " << itemVec[i].value << "; numero de vogais = " << itemVec[i].numVogais << "; numero de vogais repetidas = "<< itemVec[i].numVogaisRepetidas << endl; 
                if(itemVec[i].numVogais-itemVec[i].numVogaisRepetidas >= nMax){
                    if(itemVec[i].numVogais-itemVec[i].numVogaisRepetidas == nMax){
                        if(itemVec[i].tam < z.length()) z = itemVec[i].key;
                    }
                    else {
                        z = itemVec[i].key;
                        nMax = itemVec[i].numVogais-itemVec[i].numVogaisRepetidas;
                    }
            }
            
            }cout << z << "  ";
        }
        
    }
    return 0;
}
