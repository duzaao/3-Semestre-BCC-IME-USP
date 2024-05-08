#include <iostream>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t) {
        long long n;
        cin >> n;
        if (n % 2 == 0) {
            long long p = 1;
            for (long long i = 1; i <= n / 2; i++) {
                p = (p * i) % 998244353;
            }
            cout << (p * p) % 998244353 << endl;
        }
        else {
            cout << 0 << endl;
        }
        t--;
    }
    return 0;
}
