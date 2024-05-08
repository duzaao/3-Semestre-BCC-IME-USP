#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main(){

    string s;
    stack <char> pilha;

    cin >> s;
    bool ok = true;
    bool tudo_certo = true;

    for (char c : s){
        if(tudo_certo){
        if((c == 'a' || c == 'b') && ok){
            pilha.push(c);
        }
        else{
            if(ok){
                if(c == 'c'){
                    ok = false;
                    continue;
                }
                tudo_certo = false;
                break;
            }
            
            if(pilha.empty()) break;
            if(pilha.top() == c){
                pilha.pop();
                continue;
            }
            else {
                tudo_certo = false;
                break;
            }

        }}
    }
    if(!pilha.empty()) tudo_certo = false;
    if(tudo_certo) cout << "ok" << endl;
    else cout << "não ta ok" << endl;
}

// pilha.top
//pilha.push(c);
// pilha.empty()