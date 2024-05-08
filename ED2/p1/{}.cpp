#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main(){

    string s;
    stack <char> pilha;

    cin >> s;
    bool tudo_certo = true;

    for (char c : s){
        
        if(c == '{' || c == '(' || c == '['){
            pilha.push(c);
        }
        else if(c == '}' || c == ')' || c == ']'){
            if(pilha.empty()) {
                tudo_certo = false;
                break;
             }
            if((c == '}' && pilha.top() == '{')||(c == ')' && pilha.top() == '(')||(c == ']' && pilha.top() == '[')){
                pilha.pop();
                continue;
            }
            else {
                tudo_certo = false;
                break;
            }
        }
        else {
            tudo_certo = false;
            break;
        }
       
    }

    if(!pilha.empty()) tudo_certo = false;
    if(tudo_certo) cout << "ok" << endl;
    else cout << "não ta ok" << endl;
}