#include "ARB.h"

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
    ARB arvore;
    int Q;
    int maiorFreq = 0;
    cin >> Q;
    vector<string> palavras; 
    file.open(fileName);
    if(file.is_open()){
        while(getline(file, line)){
            // Separar palavras 
            vector<string> palavras; 
            string palavra; 
            for (int i = 0; i < line.length(); i++) { 
                if (line[i] == ' ') { 
                    palavras.push_back(palavra); 
                    palavra = ""; 
                } 
                else { 
                    palavra += line[i]; 
                } 
            }
               // for (int i = 0; i<palavras.size(); i++ ) cout << palavras[i] << " ";
            
            // Percorrer o vetor de palavras e adicionar ou incrementar
            for (int i = 0; i < palavras.size(); i++) {

                string palavra = palavras[i];
                if(palavra == " ") continue;
                //cout << palavra << " ";
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
                    for(int  j = i + 1; j < palavra.length(); j++)
                    {
                        if(palavra[i] == palavra[j])
                        {
                            count++;
                            break;
                        }
                    }
                }
                VAL.numRepeticoes = count;
               
                arvore.add_ARB(palavra,VAL);
                

            } 
        }
    }
    else{
        cout << "Arquivo não encontrado!" << endl;
        return 0;
    }
  
   //arvore.imprimirInOrdem_ARB();
   //if(arvore.tudoCertoComARBT()) cout << "Tudo ok:  O numero de pretos na arvore está igual para todos os nós" << endl;
   //if(arvore.RNOK()) cout << "tudo ok: Não há pais vermelhos com filhos vermelhos" << endl;
 //Exibir os resultados
//arvore.imprimirInOrdem();



int F = arvore.maiorFreq_ARB();
string x;

for(int k = 0; k< Q+1; k++){
    getline(cin, x);

    if(x[0] == 'F'){
        cout << "Palavras com a maior frequencia (" << F << "): ";
        arvore.imprimeF_ARB(F);
    }

    else if (x[0] == 'O') {
        x.erase(0,2);
        noARB* y = arvore.value_ARB(x);
        if(y==nullptr)
        {
            cout << "Não ocorre" << endl;
            continue;
        }
        cout << x << " ocorre " << y->val.qtd_vzs << " vez(es)"<<  endl;
    }
    else if (x[0] == 'L') {
        int maior = arvore.tamanhoDaMaior_ARB(-1);
        cout << "Palavras com o maior tamanho (" << maior << "): ";
        arvore.imprimeTamanho_ARB(maior);
    }
    else if (x[0] == 'S' && x[1] == 'R') {
        int ok = 0 ;
        int i;
        for(i = 0; i < 10 && !ok; i++){
            ok = arvore.tamanhoDaMaior_ARB(i);

        }
        cout << ok << " " << i -1 << endl;
        arvore.analisaEcalculaSR_ARB(ok, --i);

    }
    else if (x[0] == 'V' && x[1] == 'D') {
        int a = arvore.VD_ARB();
        int b =  arvore.VD2_ARB(a);
        arvore.imprimeVD_ARB(b,a);
        
    }
}
}
