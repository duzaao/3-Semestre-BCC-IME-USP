#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {

    int n; // o limite superior do intervalo de números
    int x=1; // o número desconhecido que Vasya pensou
    int y; // o número que Petya pergunta sobre
    int k; // o número de perguntas que Petya precisa fazer para determinar x
    int ok = 0;
    int fim = 0;
    int ultimo_q_divide;
    cin >> n;

    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    
    vector <int> testes(0);
    int i = 2;
    while(i <= n && !fim){
        
        if(is_prime[i]){
            testes.push_back(i);
            
                int j = i * i;
                while(j<=n){
                    {
                        testes.push_back(j);
                        j *= i;
                    }
                
            }
        }
        i++;
    }
    
    cout << testes.size() << endl;
    for(int i = 0; i< testes.size(); i++) cout << testes[i] << " ";
    return 0;
}
