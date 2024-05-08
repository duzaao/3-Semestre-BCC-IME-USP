#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <const int MOD>
struct mint {
    ll x;
    mint(): x(0) {}
    mint(ll _x): x(_x%MOD<0?_x%MOD+MOD:_x%MOD) {}
    void operator+=(mint rhs) { x+=rhs.x; if(x>=MOD) x-=MOD; }
    void operator-=(mint rhs) { x-=rhs.x; if(x<0)x+=MOD; }
    void operator*=(mint rhs) { x*=rhs.x; x%=MOD; }
    void operator/=(mint rhs) { *this *= rhs.inv(); }
    mint operator+(mint rhs) { mint res=*this; res+=rhs; return res; }
    mint operator-(mint rhs) { mint res=*this; res-=rhs; return res; }
    mint operator*(mint rhs) { mint res=*this; res*=rhs; return res; }
    mint operator/(mint rhs) { mint res=*this; res/=rhs; return res; }
    mint inv() { return this->pow(MOD-2); }
    mint pow(ll e) {
        mint res(1);
        for(mint p=*this;e>0;e/=2,p*=p) if(e%2)
            res*=p;
        return res;
    }
};

using Z = mint<1000000007>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        vector<ll> ns(3);
        cin >> ns[0] >> ns[1] >> ns[2];

        sort(ns.begin(), ns.end());

        Z res = 1;
        for (int i = 0; i < 3; i++) {
            res *= (ns[i] - i);
        }

        cout << res.x << endl;
    }

    return 0;
}
