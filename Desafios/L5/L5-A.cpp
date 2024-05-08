#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

constexpr ll MOD = 1000000007;

vector<ll> factorial(1000003, 0);

ll pow_mod(ll base, ll exp) {
    ll res = 1;
    while(exp > 0) {
        if(exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        exp = exp/2;
        base = (base * base) % MOD;
    }
    return res;
}

ll factorial_mod(ll n) {
    // verifica se o fatorial já foi calculado
    if(factorial[n] != 0) {
        return factorial[n];
    } 
    // se ainda não foi calculado, calcula e armazena na tabela
    factorial[n] = ((n % MOD) * ((factorial_mod(n - 1) % MOD))) % MOD;
    return factorial[n];
}

int main() {
    ll t; cin >> t;
    factorial[0] = 1;
    factorial[1] = 1;
    ll i, a, b, p, q;

    for(i = 0; i < t; i++) {
        // lê os valores de a e b
        cin >> a >> b;
        
        // calcula p = a!
        p = factorial_mod(a);
   
        // calcula q = (a-b)! * b!^(-1) mod MOD
        q = (factorial_mod(a - b) * factorial_mod(b)) % MOD;
        q = pow_mod(q, MOD - 2); // usa o pequeno teorema de Fermat

        // calcula e imprime o resultado
        cout << (p * q) % MOD << endl;
    }
    return 0;
}
