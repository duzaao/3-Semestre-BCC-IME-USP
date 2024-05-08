#include<bits/stdc++.h>

using namespace std;

int main(){
string s;
cin >> s;//Leitura

map<vector<int>,long long> mp;
vector<int> cnt(10,0);
mp[cnt]++;

// Percorre a string s
for(auto &nx : s) {
    int y = nx-'0';
    cnt[y]++;//Incrementa o contador correspondente ao dígito atual
    cnt[y]%=2;//Faz o módulo 2 do contador correspondente ao dígito atual
    mp[cnt]++;//Incrementa o contador para a contagem atual
}

long long res=0;

for(auto &nx : mp) 
{
    long long x=nx.second; // Pega o número de vezes que cada combinação ocorreu
    res+=(x*(x-1))/2; //C(x,2)
}

cout << res << endl;
return 0;
}