#include <iomanip>

struct Aviao {
    int tempo_de_voo;
    char numero[6]; // A string do número deve ter espaço para os 5 caracteres e o caractere nulo '\0' no final
    bool emergencia;
    char destino[4];
    int nivel_emergencia;
    bool status;
    int indice;
    int tempo_combustivel;
    int tempoEspera;
    int jafoiEmergenciado;
};

struct item {
    Aviao aviao;
    int prioridade;
};

struct filaPrior {
    int max; // capacidade máxima da fila
    int tam; // tamanho atual da fila
    int total;
    item *dados; // vetor que armazena os itens da fila
};

/**
 * Troca a posição de dois itens em uma fila de prioridade
 * @param a Um item da fila
 * @param b Outro item da fila
 */
void troca(item& a, item& b);

/**
 * Cria uma nova fila de prioridade
 * @param max Capacidade máxima da fila
 * @param tam Tamanho inicial da fila
 * @return Um ponteiro para a nova fila criada
 */
filaPrior * criaFilaPrior (int max, int tam);

/**
 * Redimensiona a fila de prioridade, aumentando sua capacidade
 * @param f Ponteiro para a fila de prioridade a ser redimensionada
 * @return O ponteiro para a fila redimensionada
 */
filaPrior * resizeFilaPrior (filaPrior * f); 

/**
 * Libera a memória alocada para a fila de prioridade
 * @param f Ponteiro para a fila de prioridade a ser liberada
 */
void destroiFilaPrior (filaPrior * f);

/**
 * Verifica se a fila de prioridade está vazia
 * @param f Ponteiro para a fila de prioridade
 * @return Verdadeiro se a fila está vazia, falso caso contrário
 */
int filaPriorVazia (filaPrior *f); 

/**
 * Remove e retorna o avião de maior prioridade da fila de prioridade
 * @param f Ponteiro para a fila de prioridade
 * @return O avião removido da fila
 */
Aviao removeFilaPrior (filaPrior * f);

/**
 * Insere um avião na fila de prioridade
 * @param f Ponteiro para a fila de prioridade
 * @param x O item a ser inserido
 */
void insereFilaPrior (filaPrior *f, item x);

/**
 * Muda a prioridade de um avião na fila de prioridade
 * @param f Ponteiro para a fila de prioridade
 * @param indice Índice do avião cuja prioridade será modificada
 * @param novapr A nova prioridade do avião
 */
void mudaPrior (filaPrior *f, int indice, int novapr);

/**
 * Atualiza o índice de todos os aviões na fila de prioridade
 * @param f Ponteiro para a fila de prioridade
 */
void muda_indice(filaPrior *f);

/**
 * Retorna o primeiro avião da fila de prioridade, sem removê-lo
 * @param f Ponteiro para a fila de prioridade
 * @return O primeiro avião da fila
 */
Aviao Primeiro_FilaPrior(filaPrior *f);
/**
 * Atualiza o tempo de espera de todos os aviões na fila de prioridade de pouso
 * @param fila Ponteiro para a fila de prioridade de pouso
**/
void atualizaTempo(filaPrior* fila);
/**
 * Verifica o combustível de todos os aviões na fila de prioridade de pouso e os move para a fila de emergência, se necessário
 * @param fila Ponteiro para a fila de prioridade de pouso
 **/
void verificaCombustivel(filaPrior* fila);

/**
 * Remove um avião específico da fila de prioridade
 * @param f Ponteiro para a fila de prioridade
 * @param aviao O avião a ser removido
 **/
void removeAviaoFilaPrior(filaPrior* f, Aviao aviao);

/**
 * Verifica se algum avião ultrapassou o tempo de espera máximo e o remove da fila de prioridade de pouso
 * @param f Ponteiro para a fila de prioridade de pouso
 * @return A quantidade de aviões removidos
 **/
int verificaQuedaAvioes(filaPrior* f);

/**
 * Verifica e conserta a fila de prioridade, garantindo que todos os aviões estejam ordenados por prioridade corretamente
 * @param fila Ponteiro para a fila de prioridade
 **/
void verifica_e_conserta_fila_prior(filaPrior* fila);

/**
 * Retorna a quantidade de aviões de emergência na fila de prioridade
 * @param fila Ponteiro para a fila de prioridade
 * @return A quantidade de aviões de emergência
 **/
int qtdeEmergencias(filaPrior *fila);

/**
 * Verifica se houve mudança na fila de prioridade de pouso e retorna o valor correspondente
 * @param f Ponteiro para a fila de prioridade de pouso
 * @return O número de mudanças
 **/
int VerificacaoDeMudanca(filaPrior* f);



/**
 * Verifica se o tempo de espera do avião é maior que 10% do tempo de voo e, se for o caso, altera sua prioridade para 3
 * @param f Ponteiro para a fila de prioridade de decolagem
 **/
void VerificacaoDeMudanca_Decolagem(filaPrior* f);

/**
 * 
 * Gera um novo item (avião) com as informações fornecidas.
 * @param num_aviao Número do avião
 * @param prob_pouso Probabilidade de o avião precisar pousar (em %)
 * @param prob_emergencia Probabilidade de o avião ter uma emergência (em %)
 * @param tempo_max_combustivel Tempo máximo de combustível do avião (em minutos)
 * @param tempo_max_voo Tempo máximo de voo do avião (em minutos)
 * @return O novo item gerado (avião)
**/
item gerador(int num_aviao, int prob_pouso, int prob_emergencia, int tempo_max_combustivel, int tempo_max_voo);