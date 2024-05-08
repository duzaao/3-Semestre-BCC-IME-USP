#include <iostream>
#include <cstring>
#include <vector>
#include "prioridade1.h"
using namespace std;


// Função auxiliar para trocar dois itens de lugar
void troca(item& a, item& b) {
    item aux = a;
    a = b;
    b = aux;
}

// Cria uma nova fila de prioridades com capacidade máxima max e tamanho inicial tam
filaPrior* criaFilaPrior(int max, int tam) {
    filaPrior *f = new filaPrior;
    f->max = max;
    f->tam = tam;
    f->total = 0; 
    f->dados = new item[max];
    return f;
}


// Libera a memória alocada para a fila de prioridades
void destroiFilaPrior(filaPrior *f) {
    delete[] f->dados;
    delete f;
}

// Redimensiona a fila de prioridades para o dobro de sua capacidade
filaPrior* resizeFilaPrior(filaPrior *f) {
    item *old_dados = f->dados;
    f->max = f->max * 2;
    f->dados = new item[f->max];
    for (int i = 0; i < f->tam; i++) {
        f->dados[i] = old_dados[i];
    }
    delete[] old_dados;
    return f;
}

// Retorna 1 se a fila de prioridades está vazia e 0 caso contrário
int filaPriorVazia(filaPrior *f) {
    return (f->tam == 0);
}

void insereFilaPrior(filaPrior *fila, item elem) {
    if (fila->tam == fila->max) {
        fila = resizeFilaPrior(fila);
    } 
        int i = fila->tam - 1;
        while (i >= 0 && elem.aviao.nivel_emergencia > fila->dados[i].aviao.nivel_emergencia) {
            fila->dados[i + 1] = fila->dados[i];
            fila->dados[i + 1].aviao.indice++;
            i--;
        }
        fila->dados[i + 1] = elem;
        fila->dados[i + 1].aviao.indice = i + 1;
        fila->total++;
        fila->tam++;
    
}



Aviao removeFilaPrior(filaPrior *f) {
    Aviao primeiro = f->dados[0].aviao; // Salva o primeiro elemento da fila
    f->dados[0] = f->dados[f->tam-1]; // Substitui o primeiro elemento pelo último
    f->tam--; // Decrementa o tamanho da fila
    muda_indice(f); // Atualiza os índices dos demais aviões
    return primeiro; // Retorna o primeiro elemento salvo
}



void mudaPrior(filaPrior *f, Aviao aviao, int novapr) {
    int i;
    for (i = 0; i < f->tam; i++) {
        if (f->dados[i].aviao.indice == aviao.indice) {
            break;
        }
    }
    if (i == f->tam) {
        return; // avião não encontrado
    }
    f->dados[i].aviao.emergencia = novapr;
    f->dados[i].aviao.nivel_emergencia = novapr;
    while (i > 0 && f->dados[(i-1)/2].aviao.nivel_emergencia < f->dados[i].aviao.nivel_emergencia) {
        troca(f->dados[i], f->dados[(i-1)/2]);
        i = (i-1)/2;
    }
    while (2*i+1 < f->tam) {
        int filho_maior = 2*i+1;
        if (filho_maior+1 < f->tam && f->dados[filho_maior+1].aviao.nivel_emergencia > f->dados[filho_maior].aviao.nivel_emergencia) {
            filho_maior++;
        }
        if (f->dados[i].aviao.nivel_emergencia < f->dados[filho_maior].aviao.nivel_emergencia) {
            troca(f->dados[i], f->dados[filho_maior]);
            i = filho_maior;
        } else {
            break;
        }
    }
    muda_indice(f);
}


void muda_indice(filaPrior *f) {
    for (int i = 0; i < f->tam; i++) {
        f->dados[i].aviao.indice = i;
    }
}

Aviao Primeiro_FilaPrior(filaPrior *f) {
    Aviao primeiro = f->dados[0].aviao; // Salva o primeiro elemento da fila
    return primeiro; // Retorna o primeiro elemento salvo
}

void atualizaTempo(filaPrior* fila) {
    for (int i = 0; i < fila->tam; i++) {
        fila->dados[i].aviao.tempoEspera += 5;
        fila->dados[i].aviao.tempo_combustivel -= 5;
    }
}

void verificaCombustivel(filaPrior* fila) {
    for (int i = 0; i < fila->tam; i++) {
        int tempoEstimado = i * 5;
        int tempoRestante = fila->dados[i].aviao.tempo_combustivel - tempoEstimado;
        
        if ((tempoRestante <= 0) && (fila->dados[i].aviao.nivel_emergencia <3) && (fila->dados[i].aviao.jafoiEmergenciado==0)) {
            cout << "!!!!!!!!!!!!!!!!!! O AVIÃO "<< fila->dados[i].aviao.numero << " PODE CAIR E SUA POSIÇÃO FOI ATUALIZADA !!!!!!!!!!!!!!!" << endl;
            item aviao;
            aviao.aviao = fila->dados[i].aviao;
            removeAviaoFilaPrior(fila,fila->dados[i].aviao);
            aviao.aviao.nivel_emergencia=3;
            aviao.aviao.emergencia =1;
            aviao.aviao.jafoiEmergenciado = 1;
            aviao.prioridade = 3;
            insereFilaPrior(fila,aviao);
        }
    }
}

void removeAviaoFilaPrior(filaPrior* f, Aviao aviao) {
    for (int i = 0; i < f->tam; i++) {
        if (strcmp(f->dados[i].aviao.numero, aviao.numero) == 0) { // compara o número do avião na fila com o número do avião a ser removido
            for (int j = i; j < f->tam-1; j++) {
                f->dados[j] = f->dados[j+1]; // desloca os aviões uma posição para a esquerda
                f->dados[j].aviao.indice = j; // atualiza o índice do avião deslocado
            }
            f->tam--; // diminui o tamanho da fila
            muda_indice(f);
            return;
        }
    }
}


int verificaQuedaAvioes(filaPrior* f) {
    int aviaoCaiu = 0; // flag para indicar se algum avião caiu
    for (int i = 0; i < f->tam; i++) {
        Aviao aviao = f->dados[i].aviao;
        
        if (aviao.tempo_combustivel < 0) {
            cout << "** ATENÇÃO **  O AVIÃO (" << aviao.numero << ") CAIU **ATENÇÃO **\n";
            removeAviaoFilaPrior(f, aviao); // remove o avião da fila
            aviaoCaiu++; // indica que um avião caiu
            
        }
    }
    return aviaoCaiu; // retorna 1 se algum avião caiu e 0 caso contrário
}

void verifica_e_conserta_fila_prior(filaPrior* fila) {
    int tam = fila->tam;
    for (int i = 0; i < tam; i++) {
        for (int j = i+1; j < tam; j++) {
            if (fila->dados[i].aviao.nivel_emergencia < fila->dados[j].aviao.nivel_emergencia) {
                troca(fila->dados[i], fila->dados[j]);
            } else if (fila->dados[i].aviao.nivel_emergencia == fila->dados[j].aviao.nivel_emergencia) {
                // Prioridades iguais, verificar critérios de desempate
                Aviao aviao_i = fila->dados[i].aviao;
                Aviao aviao_j = fila->dados[j].aviao;

                if (aviao_i.emergencia && !aviao_j.emergencia) {
                    troca(fila->dados[i], fila->dados[j]);
                } else if (aviao_i.emergencia && aviao_j.emergencia && aviao_i.nivel_emergencia < aviao_j.nivel_emergencia) {
                    troca(fila->dados[i], fila->dados[j]);
                } else if (!aviao_i.emergencia && !aviao_j.emergencia && aviao_i.tempoEspera < aviao_j.tempoEspera) {
                    troca(fila->dados[i], fila->dados[j]);
                }
            }
        }
    }
    muda_indice(fila);
}


int qtdeEmergencias(filaPrior *fila) {
    int qtdeEmergencias = 0;

    for (int i = 0; i < fila->tam; i++) {
        if (fila->dados[i].aviao.emergencia) {
            qtdeEmergencias++;
        }
    }

    return qtdeEmergencias;
}

int VerificacaoDeMudanca(filaPrior* f) {
    // iterar sobre os elementos da fila
    int numero_de_redirecionamentos = 0;
    for (int i = 0; i < f->tam; i++) {
        // verificar se o avião já foi emergenciado e seu tempo de combustível é menor que 10
        if (f->dados[i].aviao.jafoiEmergenciado && f->dados[i].aviao.tempo_combustivel < 10) {
            // remover o avião da fila
            cout << "O avião " << f->dados[i].aviao.numero << " foi Redirecionado" << endl;
            removeAviaoFilaPrior(f, f->dados[i].aviao);
            numero_de_redirecionamentos++;
            // atualizar o índice da última posição da fila
            i--;
        }
    }
    return numero_de_redirecionamentos;
 }

void VerificacaoDeMudanca_Decolagem(filaPrior* f) {
    for (int i = 0; i < f->tam; i++) {
        int tempoEspera = f->dados[i].aviao.tempoEspera;
        int tempoDeVoo = f->dados[i].aviao.tempo_de_voo;
        
        if (!f->dados[i].aviao.jafoiEmergenciado && tempoEspera > tempoDeVoo/10) {
            item aviao;
            aviao.aviao = f->dados[i].aviao;
            removeAviaoFilaPrior(f, f->dados[i].aviao);
            aviao.aviao.nivel_emergencia = 3;
            aviao.prioridade = 3;
            aviao.aviao.jafoiEmergenciado = 1;
            insereFilaPrior(f, aviao);
        }
    }
}



item gerador(int num_aviao, int prob_pouso,int  prob_emergencia,int  tempo_max_combustivel,int  tempo_max_voo) {
    item aviao1;

    // Inicializa o gerador de números aleatórios com o tempo atual

    aviao1.aviao.indice = num_aviao;
    // Gera uma sequência aleatória de duas letras maiúsculas e três dígitos para o número do voo
    for (int i = 0; i < 2; i++) {
        aviao1.aviao.numero[i] = 'A' + rand() % 26;
    }
    for (int i = 2; i < 5; i++) {
        aviao1.aviao.numero[i] = '0' + rand() % 10;
    }
    aviao1.aviao.numero[5] = '\0'; // Adiciona o caractere nulo no final da string

    // Gera um número aleatório entre 30 e 250 para o tempo de voo
    aviao1.aviao.tempo_de_voo = rand() % tempo_max_voo + 40;

    // Gera um valor booleano aleatório para indicar se o avião é uma emergência
    aviao1.aviao.emergencia = rand() % 2;


    // Gera um número aleatório entre 0 e 4 para o nível de emergência, com maior probabilidade de ser 0
    int num_emergencia = rand() % 100;
    if (num_emergencia > prob_emergencia) {
        aviao1.aviao.nivel_emergencia = 1;
        aviao1.aviao.emergencia = 0;
    } else {
        aviao1.aviao.nivel_emergencia = rand() % 3 +2;
        aviao1.aviao.emergencia = 1;
    }
    

    // Gera um valor booleano aleatório para indicar o status do avião
    int stat = rand() % 101;
    if (stat > prob_pouso) {
        aviao1.aviao.status = 0; // 0 significa decolagem
    } else {
        aviao1.aviao.status = 1; // 1 significa pouso
    }

    // Gera um número aleatório para o tempo de combustível
    aviao1.aviao.tempo_combustivel = rand() % tempo_max_combustivel +50;

    
    // Gera uma sequência aleatória de três letras maiúsculas para o destino do avião
    for (int i = 0; i < 3; i++) {
        aviao1.aviao.destino[i] = 'A' + rand() % 26;
    }
    aviao1.aviao.destino[3] = '\0'; // Adiciona o caractere nulo no final da string

    
    aviao1.aviao.tempoEspera = 0;
    aviao1.aviao.jafoiEmergenciado = 0;

    return aviao1;
}
