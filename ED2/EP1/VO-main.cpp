#include "VO.h"


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
    vector<Pair> v; 
    Pair par; 
    VO VO1 = VO();
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
                par.second = VAL;
                par.first = palavra;
                //cout << "+ adicionada :  "<<palavra << endl;
                Pair* B = VO1.BuscaBB(v,par.first);
                
                if(B == nullptr)
                    int x = VO1.InsereBB(v,par);
                else B->second.qtd_vzs++;
                //arvore.imprimirInOrdem();
                //cout << endl << endl << endl;
            } 
        }
    }
    else{
        cout << "Arquivo não encontrado!" << endl;
        return 0;
    }

    for (int i = 0; i < v.size(); i++) {
            if(v[i].second.qtd_vzs > maiorFreq) maiorFreq = v[i].second.qtd_vzs; 
        }
    string x;
    for(int k = 0; k< Q+1; k++){
        getline(cin, x);

        if(x[0] == 'F'){
            for (int i = 0; i < v.size(); i++) { 
                if(v[i].second.qtd_vzs == maiorFreq) cout << v[i].first << "  ";
            }
            cout << endl;
        }
        else if (x[0] == 'O') {
            x.erase(0,2);
            Pair *P = VO1.BuscaBB(v,x);
            if(P == nullptr) {
                cout << "Não ocorre" << endl;
                continue;
            }
            int freq = P->second.qtd_vzs;
            cout << x << " ocorre " <<freq << " vez(es)"<<  endl;
        }
        else if (x[0] == 'L') {
            int maxTam = 0;
            for (int i = 0; i < v.size(); i++) {
                if(v[i].second.tam > maxTam) maxTam = v[i].second.tam;
            }
            for (int i = 0; i < v.size(); i++) {
                if(v[i].second.tam == maxTam) cout << v[i].first << "  ";
            }
        }
        else if (x[0] == 'S' && x[1] == 'R') {
            int maxTam = 0;
            for (int i = 0; i < v.size(); i++) {
                if(v[i].second.tam > maxTam && v[i].second.numVogaisRepetidas == 0) maxTam = v[i].second.tam;
            }
            for (int i = 0; i < v.size(); i++) {
                if(v[i].second.tam == maxTam && v[i].second.numVogaisRepetidas == 0) cout << v[i].first << "  ";
            }
        }
        else if (x[0] == 'V' && x[1] == 'D') {
            string z = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaazzzzzzzzzzzzzzzzzza";
            int nMax = 0;
            int nAnterior=0;
            for (int i = 0; i < v.size(); i++) {
                //if(v[i].first == "aeio")         cout << v[i].first << ": tamanho = " << v[i].second.tam << "; numero de vezes = " << v[i].second.value << "; numero de vogais = " << v[i].second.numVogais << "; numero de vogais repetidas = "<< v[i].second.numVogaisRepetidas << endl; 
                if(v[i].second.numVogais-v[i].second.numVogaisRepetidas >= nMax){
                    if(v[i].second.numVogais-v[i].second.numVogaisRepetidas == nMax){
                        if(v[i].second.tam < z.length()) z = v[i].first;
                    }
                    else {
                        z = v[i].first;
                        nMax = v[i].second.numVogais-v[i].second.numVogaisRepetidas;
                    }
            }
            
            }cout << z << "  ";
        }
        
    }
    return 0;
}
