#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
    long long n,x,y,cont = 0, soma = 0;
    cin >> n;
    vector<int> v(n);


    for(int i = 0; i< n; i++){ cin >> v[i];

    }

    sort(v.begin(),v.end());

    int contx=1;
    for(int i = 1; i< n; i++) {
        if(v[i] == v[i-1]) {
            contx++;
            cont = contx/2;
        }
        else {
            soma += contx/2;
            contx = 1;
        }
    }

 soma += contx/2;

    cout << soma << endl;
}