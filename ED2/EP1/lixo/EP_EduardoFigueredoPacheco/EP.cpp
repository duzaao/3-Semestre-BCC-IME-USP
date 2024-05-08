#include "A23.h"
#include "ABB.h"
#include "VO.h"
#include "ARB.h"
#include "TR.h"

int main()
{


    // Ler o arquivo
    ifstream file;
    string line;

    // Estrutura desejada
    string E; 
    cin >> E;
    
    // Numero de palavras a serem lidas
    int N, num =0;
    cin >> N;

    // Número de quests
    int Q;  

    // VO
    vector<Pair> v; 
    Pair par; 
    VO VO1 = VO();

    // ABB
    A23 arvore23;

    // A23
    ABB arvoreABB;

    // ARB
    ARB arvoreRB;

    // TR
    TR arvoreTR;

    int maiorFreq = 0;

    vector<string> palavras; 
    
        for(int i = 0; i< N;i++){
            // Separar palavras 
            vector<string> palavras; 
            string palavraT, palavra=""; 
            cin >> palavraT;

            for (int i = 0; i < palavraT.length()+1; i++) { 
                if ((palavraT[i] >= 'a' && palavraT[i] <= 'z') || (palavraT[i] >= 'A' && palavraT[i] <= 'Z')) { 
                    palavra += palavraT[i]; 
                } 
                else {
                    if(palavra == " " || palavra == "") continue;
                    palavras.push_back(palavra); 
                    palavra = ""; 
                } 
                
            }
            
            
            // Percorrer o vetor de palavras e adicionar ou incrementar
            // Aqui analisamos a quatidade de repetições e a quantidade de vogais
            for (int i = 0; i < palavras.size() && num < N; i++) {


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

                //Aqui se adiciona a palavra de acordo com a estrutura desejada: 
                if(E == "A23"){
                    arvore23.add_23(palavra,VAL);
                }
                else if (E == "ABB"){
                    arvoreABB.adicionarABB(palavra,VAL);
                }
                else if(E == "VO"){
                    par.first = palavra;
                    par.second = VAL;
                     Pair* B = VO1.BuscaBB(v,par.first);
                
                    if(B == nullptr)
                        int x = VO1.InsereBB(v,par);
                    else B->second.qtd_vzs++;
                }
                else if(E == "ARB"){
                    arvoreRB.add_ARB(palavra,VAL);
                }
                else if(E == "TR"){
                    arvoreTR.add_TR(palavra,VAL);
                }
                num++;

            }
            }

	cout << "insira o numero de queries : " << endl;
        cin >> Q;

    //arvore23.imprimirInOrdem();
    
    // Daqui pra baixo ocorre o processamento dos testes de acordo com a estrutura escolhida; 
    if(E == "A23"){
        int F = arvore23.maiorFreq23();
        string x;

        for(int k = 0; k< Q+1; k++){
            getline(cin, x);

            if(x[0] == 'F'){
                cout << "Palavras com a maior frequencia (" << F << "): ";
                arvore23.imprimeF23(F);
            }

            else if (x[0] == 'O') {
                x.erase(0,2);
                Item p = arvore23.value23(x);
                if(p.tam==0){
                    cout << "Não ocorre" << endl;
                    continue;
                }
                int freq= 0 ;

                    freq  = p.qtd_vzs;

                
                cout << x << " ocorre " <<freq << " vez(es)"<<  endl;
            }
            else if (x[0] == 'L') {
                int maior = arvore23.tamanhoDaMaior23(-1);
                cout << "Palavras com o maior tamanho (" << maior << "): ";
                arvore23.imprimeTamanho23(maior);
                cout << endl;
            }
            else if (x[0] == 'S' && x[1] == 'R') {
                int ok = 0 , ok2 = 0;
                int i;
                for(i = 0; i < 10 && !ok; i++){
                    ok = arvore23.tamanhoDaMaior23(i);
                
                }
                arvore23.analisaEcalculaSR23(ok, --i);

            }
            else if (x[0] == 'V' && x[1] == 'D') {
                int a = arvore23.VD23();
                int b =  arvore23.VD2_23(a);
                arvore23.imprimeVD23(b,a);
                
            }
        }

    }
    else if(E == "ABB"){
        int F = arvoreABB.maiorFreqABB();
        string x;

        for(int k = 0; k< Q+1; k++){
            getline(cin, x);

            if(x[0] == 'F'){
                cout << "Palavras com a maior frequencia (" << F << "): ";
                arvoreABB.imprimeFABB(F);
            }

            else if (x[0] == 'O') {
                x.erase(0,2);
                int freq;
                Item val = arvoreABB.valorABB(x);
                freq = val.qtd_vzs;
                if(freq == 0) {
                    cout << "Não ocorre" << endl;
                    continue;
                }
                cout << x << " ocorre " <<freq << " vez(es)"<<  endl;
            }
            else if (x[0] == 'L') {
                int maior = arvoreABB.tamanhoDaMaiorABB(-1);
                cout << "Palavras com o maior tamanho (" << maior << "): ";
                arvoreABB.imprimeTamanhoABB(maior);
            }
            else if (x[0] == 'S' && x[1] == 'R') {
                int ok = 0 , ok2 = 0;
                int i;
                for(i = 0; i < 10 && !ok; i++){
                    ok = arvoreABB.tamanhoDaMaiorABB(i);

                }
                arvoreABB.analisaEcalculaSRABB(ok, --i);

            }
            else if (x[0] == 'V' && x[1] == 'D') {
                int a = arvoreABB.VDABB();
                int b =  arvoreABB.VD2ABB(a);
                arvoreABB.imprimeVDABB(b,a);
                
            }
        }
    }
    else if(E == "VO"){
        maiorFreq = 0;
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
                cout << "Maiores palavras de tamanho (" << maxTam << ") : " ;
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

    }
    else if( E == "ARB"){


        //arvoreRB.imprimirInOrdem_ARB();

        int F = arvoreRB.maiorFreq_ARB();
        string x;

        for(int k = 0; k< Q+1; k++){
            getline(cin, x);

            if(x[0] == 'F'){
                cout << "Palavras com a maior frequencia (" << F << "): ";
                arvoreRB.imprimeF_ARB(F);
            }

            else if (x[0] == 'O') {
                x.erase(0,2);
                Item val = arvoreRB.value_ARB(x);
                int freq  = val.qtd_vzs;
                if(freq == 0)
                {
                    cout << "Não ocorre" << endl;
                    continue;
                }
                cout << x << " ocorre " << freq << " vez(es)"<<  endl;
            }
            else if (x[0] == 'L') {
                int maior = arvoreRB.tamanhoDaMaior_ARB(-1);
                cout << "Palavras com o maior tamanho (" << maior << "): ";
                arvoreRB.imprimeTamanho_ARB(maior);
            }
            else if (x[0] == 'S' && x[1] == 'R') {
                int ok = 0 ;
                int i;
                for(i = 0; i < 10 && !ok; i++){
                    ok = arvoreRB.tamanhoDaMaior_ARB(i);

                }
                arvoreRB.analisaEcalculaSR_ARB(ok, --i);

            }
            else if (x[0] == 'V' && x[1] == 'D') {
                int a = arvoreRB.VD_ARB();
                int b =  arvoreRB.VD2_ARB(a);
                arvoreRB.imprimeVD_ARB(b,a);
                
            }
        }

    }
    else if( E == "TR"){

        


        int F = arvoreTR.maiorFreq_TR();
        string x;

        for(int k = 0; k< Q+1; k++){
            getline(cin, x);

            if(x[0] == 'F'){
                cout << "Palavras com a maior frequencia (" << F << "): ";
                arvoreTR.imprimeF_TR(F);
            }

            else if (x[0] == 'O') {
                x.erase(0,2);
                Item val = arvoreTR.value_TR(x);
                int freq = val.qtd_vzs;
                if(freq == 0)
                {
                    cout << "Não ocorre" << endl;
                    continue;
                }
                cout << x << " ocorre " << freq << " vez(es)"<<  endl;
            }
            else if (x[0] == 'L') {
                int maior = arvoreTR.tamanhoDaMaior_TR(-1);
                cout << "Palavras com o maior tamanho (" << maior << "): ";
                arvoreTR.imprimeTamanho_TR(maior);
            }
            else if (x[0] == 'S' && x[1] == 'R') {
                int ok = 0 , ok2 = 0;
                int i;
                for(i = 0; i < 10 && !ok; i++){
                    ok = arvoreTR.tamanhoDaMaior_TR(i);

                }
                arvoreTR.analisaEcalculaSR_TR(ok, --i);

            }
            else if (x[0] == 'V' && x[1] == 'D') {
                int a = arvoreTR.VD_TR();
                int b =  arvoreTR.VD2_TR(a);
                arvoreTR.imprimeVD_TR(a,b);
                
            }
        }

    }
    
                
 }





