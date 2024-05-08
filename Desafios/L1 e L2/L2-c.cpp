#include<iostream>
#include<string.h>

#define MAX_N 100001
#define MAX_M 100001

using namespace std;

long long int a[MAX_N]; // array original
long long int fix[MAX_N]; // array que registra quanto cada posição foi ajustada
long long int ops[MAX_M]; // array que registra quantas operações afetam cada operação
long long int operations[MAX_M][3]; // matriz que armazena as operações em si

int main(){
    int n, m, k;
    while (cin >> n >> m >> k){
        memset(a, 0, sizeof(a));
        memset(fix, 0, sizeof(fix));
        memset(ops, 0, sizeof(ops));
        memset(operations, 0, sizeof(operations));

        // Lê o array original
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        // Lê as operações
        for (int i = 0; i < m; i++){
            for (int j = 0; j < 3; j++)
                cin >> operations[i][j];

            // Ajusta as operações para índices baseados em zero
            operations[i][0]--, operations[i][1]--;
        }

        // Lê as queries e registra quantas operações afetam cada operação
        for (int i = 0; i < k; i++){
            int left, right;
            cin >> left >> right;
            left--, right--;
            ops[left]++, ops[right + 1]--;
        }

        long long int tmp = 0;

        // Processa as operações de acordo com o número de vezes que elas aparecem nas queries
        for (int i = 0; i < m; i++){
            tmp += ops[i];
            fix[operations[i][0]] += tmp * operations[i][2];
            fix[operations[i][1] + 1] -= tmp * operations[i][2];
        }
        
        tmp = 0;

        // Aplica os ajustes no array original e imprime o resultado final
        for (int i = 0; i < n; i++){
            tmp += fix[i];
            if (i == 0) cout << tmp + a[i];
            else cout <<  " " << tmp + a[i];
        }
        cout << "\n";
    }
    return 0;
}
