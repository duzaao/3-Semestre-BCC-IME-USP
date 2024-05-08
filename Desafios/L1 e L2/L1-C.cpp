#include <iostream>

using namespace std;

long long bb(long long k, long long n, long long a, long long b, long long L, long long U) {
    long long meio = (L + U) / 2;
    while (L < U) {
        if (meio*a + (n-meio)*b < k) {
            L = meio + 1;
        } else {
            U = meio;
        }
        meio = (L + U) / 2;
    }
    return L;
}

int main() {
    long long q, k, n, a, b, x=0, flag;
    cin >> q;
    // k é bateria, q é número de jogos, n é número de turnos
    while (x < q) {
        flag = 0;
        cin >> k >> n >> a >> b;
        if (b*n >= k) {
            cout << -1 << endl;
            flag = 1;
        }
        if (flag == 0) {
            cout << bb(k, n, a, b, 0, k/a + 1) << endl;
        }
        x++;
    }
    return 0;
}
