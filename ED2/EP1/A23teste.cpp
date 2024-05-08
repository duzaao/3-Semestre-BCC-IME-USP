#include "A23.h"


int main(int argc, const char* argv[])
{
    if(argc < 2){
        cout << "Arquivo não especificado!" << endl;
        return 0;
    }

    string fileName = argv[1];

    // Ler o arquivo
    ifstream file;
    string line;
    int Q;
    A23 arvore;
    int maiorFreq = 0;
    cin >> Q;
    vector<string> palavras; 
    file.open(fileName);
    if(file.is_open()){
        while(getline(file, line)){
            // Separar palavras 
            vector<string> palavras; 
            string palavra; 
            for (int i = 0; i < line.length()+1; i++) { 
                if (line[i] == ' ' || line[i] == '\n' || line[i] == '\0') { 
                    palavras.push_back(palavra); 
                    palavra = ""; 
                } 
                else { 
                    palavra += line[i]; 
                } 
                
            }
            cout << endl;
            
            // Percorrer o vetor de palavras e adicionar ou incrementar
            for (int i = 0; i < palavras.size(); i++) {


                string palavra = palavras[i];
                Item VAL;
                
                VAL.tam = palavra.size();
                int contVogais = 0;
                for(int i = 0; i < palavra.length(); i++){
                    char c = tolower(palavra[i]);
                    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' )
                        {
                            contVogais++;
                        }

                }
                int vog[5];
                vog[0] =vog[1] = vog[2] = vog[3] = vog[4] = -1;
                for(int i=0;i<palavra.length();i++){
                    char c = tolower(palavra[i]);
                    if(c == 'a') vog[0]++;
                    if(c == 'e') vog[1]++;
                    if(c == 'i') vog[2]++;
                    if(c == 'o') vog[3]++;
                    if(c == 'u') vog[4]++;
                    
                }
                    if(vog[0] == -1) vog[0] = 0; 
                    if(vog[1] == -1) vog[1] = 0; 
                    if(vog[2] == -1) vog[2] = 0; 
                    if(vog[3] == -1) vog[3] = 0; 
                    if(vog[4] == -1) vog[4] = 0; 

                int somaRep = vog[0] + vog[1] + vog[2] + vog[3] + vog[4];

                VAL.numVogaisRepetidas = somaRep;
                VAL.numVogais = contVogais;
                VAL.qtd_vzs = 1;
                int count;    
                count = 0;

                for(int i = 0; i < palavra.length(); i++)
                {
                    for(int  j = i + 1; j < palavra.length()+1; j++)
                    {
                        if(palavra[i] == palavra[j])
                        {
                            count++;
                            break;
                        }
                    }
                }
                VAL.numRepeticoes = count;

                //cout << "+ adicionada :  "<<palavra << endl;
                arvore.add_23(palavra,VAL);
                //arvore.imprimirInOrdem();
                //cout << endl << endl << endl;
            } 
        }
    }
    else{
        cout << "Arquivo não encontrado!" << endl;
        return 0;
    }
    //arvore.viz();
   //arvore.imprimirInOrdem();
 //Exibir os resultados
//arvore.imprimirInOrdem();
int F = arvore.maiorFreq23();
string x;

for(int k = 0; k< Q+1; k++){
    getline(cin, x);

    if(x[0] == 'F'){
        cout << "Palavras com a maior frequencia (" << F << "): ";
        arvore.imprimeF23(F);
    }

    else if (x[0] == 'O') {
        x.erase(0,2);
        no* p = arvore.value23(x);
        int freq= 0 ;
        if(p->ch1 == x){
            freq  = p->val1.qtd_vzs;
        }
        else if(x == p->ch2){
            freq  = p->val1.qtd_vzs;
        }
        if(freq == 0) {
            cout << "Não ocorre" << endl;
            continue;
        }
        cout << x << " ocorre " <<freq << " vez(es)"<<  endl;
    }
    else if (x[0] == 'L') {
        int maior = arvore.tamanhoDaMaior23(-1);
        cout << "Palavras com o maior tamanho (" << maior << "): ";
        arvore.imprimeTamanho23(maior);
        cout << endl;
    }
    else if (x[0] == 'S' && x[1] == 'R') {
        int ok = 0 , ok2 = 0;
        int i;
        for(i = 0; i < 10 && !ok; i++){
            ok = arvore.tamanhoDaMaior23(i);
           
        }
        arvore.analisaEcalculaSR23(ok, --i);

    }
    else if (x[0] == 'V' && x[1] == 'D') {
        int a = arvore.VD23();
        int b =  arvore.VD2_23(a);
        arvore.imprimeVD23(b,a);
        
    }
}
}