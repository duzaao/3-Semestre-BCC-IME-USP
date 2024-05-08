#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

using ll = long long;





int main(){

    long long x = 1000000;
    vector<bool> is_prime(x+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= x; i++) {
        if (is_prime[i] && (long long)i * i <= x) {
            for (int j = i * i; j <= x; j += i)
                is_prime[j] = false;
        }
    }

    ll n,y;
    cin >> y;
    for(ll j = 0; j<y;j++){
    cin >> n;
    double z = sqrt(n);
    if(n==1 || n == 2 || n==3) {cout << "NO" << endl;continue;}
    if(z == (int)z){
        int zz = (int)z;
        if(n%zz ==0){
            ll x = 0;
            ll w = 0;
            
            if(is_prime[zz]){
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        } 
    }
    else cout << "NO" << endl;
    }
    return 0;

}
