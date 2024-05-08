#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;
#define ll long long

vector<bool> sieve(ll n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

int main() {
    ll n;
    cin >> n;

vector<ll> nums(n);
for (ll i = 0; i < n; i++) {
    cin >> nums[i];
}

vector<map<ll, ll>> factors(n);
for (ll i = 0; i < n; i++) {
    ll x = nums[i];
    for (ll p = 2; p*p <= x; p++) {
        while (x % p == 0) {
            factors[i][p]++;
            x /= p;
        }
    }
    if (x > 1) factors[i][x]++;
}

vector<bool> is_prime = sieve(1000000);

ll gcd = 1;
for (ll p = 2; p <= 1000000; p++) {
    if (!is_prime[p]) continue;
    ll sum = 0, cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (factors[i].count(p)) {
            sum += factors[i][p];
            cnt++;
        }
    }
    if (cnt * 2 > n) {
        ll exp = (int) sum / n;
        gcd *= pow(p, exp);
    }
}


ll ops = 0;

/*for (ll i = 0; i < n; i++) {
    cout << "Elemento " << i << ": ";
    for (auto it = factors[i].begin(); it != factors[i].end(); it++) {
        cout << it->first << "^" << it->second << " ";
    }
    cout << endl;
}*/

map<ll, ll> gcd_factors;
for (ll p = 2; p <= 1000000; p++) {
    if (!is_prime[p]) continue;
    ll sum = 0, cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (factors[i].count(p)) {
            sum += factors[i][p];
            cnt++;
        }
    }
    if (cnt * 2 > n) {
        ll exp = sum / n;
        gcd_factors[p] = exp;
    }
}


for (ll i = 0; i < n; i++) {
    bool is_divisible = true;
    for (auto it = gcd_factors.begin(); it != gcd_factors.end(); it++) {
        ll p = it->first;
        ll exp = it->second;
        if (factors[i].count(p)) {
            if (factors[i][p] < exp) {
                is_divisible = false;
                ops += exp - factors[i][p];
            }
        } else {
            is_divisible = false;
            ops += exp;
        }
    }
}

cout << gcd << " " << ops << endl;
return 0;

}
