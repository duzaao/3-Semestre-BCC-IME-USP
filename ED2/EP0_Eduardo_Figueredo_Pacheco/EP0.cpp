#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "prioridade1.h"
#include <iomanip>

using namespace std;


int main() {
    

    item novo;

    /* Variáveis para controle de laços de repetição. */
    int i, j, n;

    /* Variáveis para contagem do número de decolagens, pousos e aviões. */
    int num_decolagem = 0, num_pouso = 0, num_aviao = 1;

    /* Variável para indicar se um avião foi atendido ou não. */
    int foi = 0;

    /* Variáveis para indicar se as pistas estão livres ou ocupadas e o tempo de ocupação de cada pista. */
    int pista1 = 1, pista2 = 1, pista3 = 1, tempo_pista1 = 0, tempo_pista2 = 0, tempo_pista3 = 0;

    /* Ponteiros para as filas de pouso e decolagem. */
    filaPrior * fila_pouso, * fila_decolagem;

    /* Variáveis para cálculo das médias de pouso e decolagem, e médias de espera de pouso e decolagem. */
    long int dadosMediaPouso = 0, dadosMediaDecolagem = 0;
    long int dadosMediaEsperaPouso = 0, dadosMediaEsperaDescolagem = 0;

    /* Variáveis para contagem de aviões que caíram e foram redirecionados. */
    int avioesQueCairam = 0, avioesRedirecionados = 0;

    /* Inicialização da variável n. */
    n = 0;

    /* Criação das filas de pouso e decolagem. */
    fila_pouso  = criaFilaPrior(8,0);
    fila_decolagem = criaFilaPrior(8,0);

    /* Variáveis para armazenar os parâmetros de entrada da simulação. */
    int tempo_simulacao, qtde_max_avioes;
    int prob_pouso, prob_emergencia, tempo_max_combustivel, tempo_max_voo;
    
    cout << "************************************************************" << endl;
    cout << "*                    SIMULADOR DE PISTA DE POUSO            *" << endl;
    cout << "************************************************************" << endl;
    cout << endl << endl;
    cout << "Insira o tempo de simulação:                      por exemplo [10,100] :  ";
    cin >> tempo_simulacao;
    cout << "Insira a quantidade máxima de aviões gerados:               por exemplo    [1,10]:  ";
    cin >> qtde_max_avioes;
    cout << "Insira a probabilidade de ser um pouso (0 - 100):           por exemplo   [1,100]:  ";
    cin >> prob_pouso;
    cout << "Insira a probabilidade de ser uma emergência (0 - 100):      por exemplo   [1,100]:  ";
    cin >> prob_emergencia;
    cout << "Insira o tempo máximo de combustível de um avião que deseja pousar:por exemplo  [100,500]:  ";
    cin >> tempo_max_combustivel;
    cout << "Insira o tempo máximo de voo de uma decolagem:                por exemplo  [200,1500]:  ";
    cin >> tempo_max_voo;
    cout << "insira (1) se quer analisar o que acontece em cada intervalo de tempo no aeroporto ou (0) para apenas ver o resultado final" << endl;
    int sleep_nmbr; cin >> sleep_nmbr; 
    cout << endl;

    srand(time(0)); 
    while (tempo_simulacao>0) {
        tempo_simulacao--;

        int aviaoDeco1 = 0, aviaoDeco2 = 0,aviaoDeco3 = 0, aviaoPouso1 = 0, aviaoPouso2 = 0; 
        Aviao aviaoD1, aviaoD2, aviaoD3, aviaoP1, aviaoP2;
        
        for(int k = 0; k<qtde_max_avioes;k++){
            if (rand() % 2 == 0) {
                item aviao = gerador(num_aviao++, prob_pouso, prob_emergencia, tempo_max_combustivel, tempo_max_voo);

                cout << endl << "******************************************************************" << endl;
                cout << "                      ENTROU NA FILA                            " << endl;
                cout << " O avião " << aviao.aviao.numero << " entrou na fila e tem emergencia:  " << aviao.aviao.nivel_emergencia <<endl;
                cout << "O avião irá " << ((aviao.aviao.status)?"pousar.":"decolar.")<< endl;
                cout << "******************************************************************" << endl;

                if(aviao.aviao.status){
                    insereFilaPrior(fila_pouso, aviao);
                    muda_indice(fila_pouso);
                    num_pouso++;
                    dadosMediaPouso += aviao.aviao.tempo_combustivel;
                }
                else {
                    insereFilaPrior(fila_decolagem, aviao);
                    muda_indice(fila_decolagem);
                    num_decolagem++;
                    dadosMediaDecolagem += aviao.aviao.tempo_combustivel;

                }

                
                foi =1;
            }
        }

        /* Contadores: */
        int y = 0;
        int z =0;

        /* CASO DE DECOLAGEM (inserção)*/
        cout << "Decolagem: " ;
        while(y < num_decolagem &&foi){
            cout << fila_decolagem->dados[y].aviao.indice << " " << fila_decolagem->dados[y].aviao.nivel_emergencia << " / ";
            y++;  
            
        }
        cout << endl;
        
        /*CASO DE POUSO (inserção)*/
        cout << "Pouso: ";
        while(z < num_pouso &&foi){
            cout << fila_pouso->dados[z].aviao.indice << " " << fila_pouso->dados[z].aviao.nivel_emergencia << " / ";
            z++;  
            
        }
        cout << endl << endl;
        sleep(sleep_nmbr);

/*DECOLAGEM */
        if(!filaPriorVazia(fila_decolagem) && (pista3>0)){

            aviaoD3 = removeFilaPrior(fila_decolagem);
            aviaoDeco3  = 1;
            pista3*=-1;
            num_decolagem--;
            dadosMediaEsperaDescolagem += aviaoD3.tempoEspera;


        }
/*Decolagem de Emergencia */
        if(!filaPriorVazia(fila_decolagem))
            if(Primeiro_FilaPrior(fila_decolagem).nivel_emergencia>=3){
                if(pista1>0){

                    aviaoD1 = removeFilaPrior(fila_decolagem);
                    aviaoDeco1  = 1;
                    num_decolagem--;
                    dadosMediaEsperaDescolagem += aviaoD1.tempoEspera;
                    pista1*=-1;

                }
                else if(pista2>0){
                    aviaoD2 = removeFilaPrior(fila_decolagem);
                    aviaoDeco2  = 1;
                    num_decolagem--;
                    dadosMediaEsperaDescolagem += aviaoD2.tempoEspera;
                    pista2*=-1;
                }
            }

/* */

/*POUSO*/  


        if(!filaPriorVazia(fila_pouso) && (pista1>0||pista2>0)){

            if(pista1>0 && pista2>0) { // se as duas pistas estão liberadas

                if(!filaPriorVazia(fila_pouso)){ 
                    aviaoP2 = removeFilaPrior(fila_pouso);
                    aviaoPouso2 = 1;
                    num_pouso--;
                    dadosMediaEsperaPouso += aviaoP2.tempoEspera;
                    pista2 *= -1; 
                }
            }
            else if (pista1>0) {    // se somente a primeira pista está liberada            
                aviaoP1 = removeFilaPrior(fila_pouso);
                aviaoPouso1 = 1;
                num_pouso--;
                dadosMediaEsperaPouso += aviaoP1.tempoEspera;
                pista1*=-1;
            }
            else {       // se somente a segund apista está liberada             
                aviaoP2 = removeFilaPrior(fila_pouso);
                aviaoPouso2 = 1;
                num_pouso--;
                dadosMediaEsperaPouso += aviaoP2.tempoEspera;
                pista2 *= -1; 
            }
            
        }

/* */

/*CONTAGEM DO TEMPO : */



/*Aqui acontece a contagem do tempo para que cada pista depois de utilizada fique 2 unidades de tempo sem uso! */
        if(pista1<0) tempo_pista1++;
        if(pista2<0) tempo_pista2++;
        if(pista3<0) tempo_pista3++;
        if(tempo_pista1%3==0 && pista1 < 0) {tempo_pista1 = 0; pista1 *= -1; } 
        if(tempo_pista2%3==0 && pista2 < 0) {tempo_pista2 = 0; pista2 *= -1; } 
        if(tempo_pista3%3==0 && pista3 < 0) {tempo_pista3 = 0; pista3 *= -1; }



/* */



/* VERIFICAÇÕES :    */



/*Aqui verificaremos se pode acontecer do avião cair*/
    int numero_quedas = verificaQuedaAvioes(fila_pouso);
      if(numero_quedas){ num_pouso -= numero_quedas; avioesQueCairam += numero_quedas;} /*se caiu, diminui-se um numero de z (numero de avioes na espera de pousar)*/

/*Verifica se o aviao pode ser redirecionado*/
        int numero_redirecionamento = VerificacaoDeMudanca(fila_pouso);
        if(numero_redirecionamento){ num_pouso -= numero_redirecionamento; avioesRedirecionados += numero_redirecionamento;} 
/*lembrar de criar uma função que atualize o tempo de combustivel*/
        atualizaTempo(fila_pouso);
        atualizaTempo(fila_decolagem);


/*Aqui verificaremos se o avião já está esperando há mais de 10% do seu tempo de voo*/
        verificaCombustivel(fila_pouso);


/*Aqui verificamos se o aviao pra decolar está esperando ha muito tempo*/
        VerificacaoDeMudanca_Decolagem(fila_decolagem);

/*Aqui verificamos se a fila de prioridades segue com a ordem de prioridade para os mais emergentes*/
        verifica_e_conserta_fila_prior(fila_decolagem);
        verifica_e_conserta_fila_prior(fila_pouso);




/**/



        cout << "+-----------+-----------------+---------------+-----------------+-------------------------" << endl;
        cout << "| DECOLAGEM | Avião | Destino |      Tempo de Voo       | Nível de Emergência |  Situação" << endl;
        cout << "+-----------+-----------------+---------------+-----------------+-------------------------" << endl;
        
        if(aviaoDeco1) cout << "|           | " << aviaoD1.numero << " | " << aviaoD1.destino << "     | " << setw(12) << aviaoD1.tempo_de_voo << "           |  " << aviaoD1.nivel_emergencia << "                    |   Decolou na pista 1!" << endl;
        if(aviaoDeco3) cout << "|           | " << aviaoD3.numero << " | " << aviaoD3.destino << "     | " << setw(12) << aviaoD3.tempo_de_voo << "           |  " << aviaoD3.nivel_emergencia << "                    |   Decolou na pista 3!" << endl;
        if(aviaoDeco2) cout << "|           | " << aviaoD2.numero << " | " << aviaoD2.destino << "     | " << setw(12) << aviaoD2.tempo_de_voo << "           |  " << aviaoD2.nivel_emergencia << "                    |   Decolou na pista 2!" << endl;
        for(int i = 0; i<num_decolagem && i<5;i++) cout << "|           | " << fila_decolagem->dados[i].aviao.numero << " | " << fila_decolagem->dados[i].aviao.destino << "     | " << setw(12) << fila_decolagem->dados[i].aviao.tempo_de_voo << "           |  " << fila_decolagem->dados[i].aviao.nivel_emergencia << "                    | " << fila_decolagem->dados[i].aviao.indice+1 << "º lugar na fila de espera!" << endl;
        cout << endl;
        cout << "+-----------+-----------------+-------------------------+-----------------+" << endl << endl;
        
        cout << "Número de emergencias na Decolagem : "<< qtdeEmergencias(fila_decolagem) << endl;


        cout << "+-----------+-----------------+---------------+-----------------+-------------------------" << endl;
        cout << "|   POUSO   | Avião | Destino |      Tempo de Voo       | Nível de Emergência |  Situação" << endl;
        cout << "+-----------+-----------------+---------------+-----------------+-------------------------" << endl;
        if(aviaoPouso1) cout << "|           | " << aviaoP1.numero << " | " << aviaoP1.destino << "     | " << setw(12) << aviaoP1.tempo_de_voo << "           |  " << aviaoP1.nivel_emergencia << "                    |   POUSOU na pista 1!" << endl;
        if(aviaoPouso2) cout << "|           | " << aviaoP2.numero << " | " << aviaoP2.destino << "     | " << setw(12) << aviaoP2.tempo_de_voo << "           |  " << aviaoP2.nivel_emergencia << "                    |   POUSOU na pista 2!" << endl;
        for(int i = 0; i<num_pouso && i<5;i++) cout << "|           | " << fila_pouso->dados[i].aviao.numero << " | " << fila_pouso->dados[i].aviao.destino << "     | " << setw(12) << fila_pouso->dados[i].aviao.tempo_de_voo << "           |  " << fila_pouso->dados[i].aviao.nivel_emergencia << "                    | " << fila_pouso->dados[i].aviao.indice+1 << "º lugar na fila de espera!" << endl;
        cout << "+-----------+-----------------+-------------------------+-----------------+" << endl << endl;

        cout << "Número de emergencias na fila de pouso : "<< qtdeEmergencias(fila_pouso) << endl;


    }

    if(!filaPriorVazia(fila_decolagem) || !filaPriorVazia(fila_pouso)){
        
        if(!filaPriorVazia(fila_decolagem)){
            cout << "ATENÇÃO, O TEMPO DE FUNCIONAMENTO DO AEROPORTO FINALIZOU " << endl;
            cout << "+-----------+-----------------+---------------+-----------------+-------------------------" << endl;
            cout << "| DECOLAGEM | Avião | Destino |      Tempo de Voo       | Nível de Emergência |  Situação" << endl;
            cout << "+-----------+-----------------+---------------+-----------------+-------------------------" << endl;
            for(int i = 0; i<num_decolagem;i++) cout << "|           | " << fila_decolagem->dados[i].aviao.numero << " | " << fila_decolagem->dados[i].aviao.destino << "     | " << setw(12) << fila_decolagem->dados[i].aviao.tempo_de_voo << "           |  " << fila_decolagem->dados[i].aviao.nivel_emergencia << "                    | " << fila_decolagem->dados[i].aviao.indice+1 << "º lugar na fila de espera!" << endl;
            cout << endl;
            cout << "+-----------+-----------------+-------------------------+-----------------+" << endl << endl;
        }
        if(!filaPriorVazia(fila_pouso)){
            cout << "ATENÇÃO, O TEMPO DE FUNCIONAMENTO DO AEROPORTO FINALIZOU " << endl;
            cout << "+-----------+-----------------+---------------+-----------------+-------------------------" << endl;
            cout << "|   POUSO   | Avião | Destino |      Tempo de Voo       | Nível de Emergência |  Situação" << endl;
            cout << "+-----------+-----------------+---------------+-----------------+-------------------------" << endl;
            for(int i = 0; i<num_pouso ;i++) cout << "|           | " << fila_pouso->dados[i].aviao.numero << " | " << fila_pouso->dados[i].aviao.destino << "     | " << setw(12) << fila_pouso->dados[i].aviao.tempo_de_voo << "           |  " << fila_pouso->dados[i].aviao.nivel_emergencia << "                    | " << fila_pouso->dados[i].aviao.indice+1 << "º lugar na fila de espera!" << endl;
            cout << "+-----------+-----------------+-------------------------+-----------------+" << endl << endl;

        }
    }
            cout << "O número total de decolagens foi : " << fila_decolagem->total << endl;
            cout << "O número total de pousos foi : " << fila_pouso->total << endl;
            cout <<  "Combustível médio para Decolagem : "<< (float)dadosMediaDecolagem/fila_decolagem->total << endl;
            cout <<  "Tempo de espera médio para decolagem : "<< (float)dadosMediaEsperaDescolagem/fila_decolagem->total << endl;
            cout <<  "Combustível médio para pouso : "<< (float)dadosMediaPouso/fila_pouso->total << endl;
            cout <<  "Tempo de espera médio para pouso : "<< (float)dadosMediaEsperaPouso/fila_pouso->total << endl;
            cout<< "Numero de avioes que caíram : " << avioesQueCairam << endl;
            cout<< "Numero de avioes que foram redirecionados : " << avioesRedirecionados << endl;
// g++ EP0.cpp prioridade.cpp -o programa

    destroiFilaPrior(fila_decolagem);
    destroiFilaPrior(fila_pouso);

    return 0;
}

