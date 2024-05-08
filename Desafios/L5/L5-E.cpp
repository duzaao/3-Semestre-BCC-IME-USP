
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define ll long long

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

void P(vector<Z> &fatoriais){
    int i;
    for (i = 1 ; i< 1000000; i++)
        fatoriais.push_back(fatoriais[i-1]*i);
}


int main(){
    vector<Z> fatoriais;
    P(fatoriais);
    vector<ll> valores;
    ll i, n, k, temp;
    Z soma = 0;
    cin >> n >> k;
    valores.push_back(0);
    for(i = 0; i< n; i++){
        cin >> temp;
        valores.insert(valores.begin()+ i, temp);

    }
    sort(valores.begin(),valores.end());
    for(i = k; i<= n ; i++){
        soma = soma + fatoriais[i-1]/fatoriais[i-k]*fatoriais[k-1]*valores[i];
    }
    cout << soma.x << endl;
    return 0;

}