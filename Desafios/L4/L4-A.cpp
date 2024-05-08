#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

const long long inf = 1e9;
using ll = long long;
vector<int> items;

ll memo[1000001];

ll n; 

ll dp(ll S){
    if(memo[S] != -inf) return memo[S];
    if(S==0) return memo[S] = 0;
    for(int i = 0; i< 3;i++){
        if(S-items[i] >= 0){
            memo[S] = max(memo[S],1+dp(S-items[i]));
        }
    }
    return memo[S];
}


int main(){
    ll a, b, c;
    cin >> n >> a >> b >> c;


    for(int i = 0; i<=1000000;i++) memo[i] = -inf;
    items.push_back(a);
    items.push_back(b);
    items.push_back(c);
    ll res = dp(n);
    cout << res << endl;


}
