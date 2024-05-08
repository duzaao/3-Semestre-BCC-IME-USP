#include <iostream>
#include <cmath>

using namespace std;

int N;
long long x[1001], y[1001], ans;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++)
        cin >> x[i] >> y[i];
    
    x[N] = x[0];
    y[N] = y[0];

    for (int i = 0; i < N; i++) {
        ans += x[i] * y[i + 1];
        ans -= y[i] * x[i + 1];
    }
    
    cout << abs(ans) << endl;
    
    return 0;
}
