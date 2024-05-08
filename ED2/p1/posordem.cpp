#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main(){

    string s;
    stack <char> pilha;

    cin >> s;
    bool ok = true;
    bool tudo_certo = true;
    cout << endl;

    for (char c : s){

        if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){
            cout << c;
        }
        else if(c == '-' || c == '+' || c == '*' || c == '/'){
            if(!pilha.empty()){
                if(pilha.top() == '-' || pilha.top() == '+'){
                    while(pilha.top() == '-' || pilha.top() == '+'){
                        cout << pilha.top();
                        pilha.pop();
                        if(pilha.empty()) break;
                    }
                }
                else if(pilha.top() == '*' || pilha.top() == '/'){
                    while(pilha.top() == '*' || pilha.top() == '/'){
                        cout << pilha.top();
                        pilha.pop();
                        if(pilha.empty()) break;
                    }
                }
            }
            pilha.push(c);
        }
        else if(c == '('){
            pilha.push(c);
        }
        else if(c == ')'){
            while(pilha.top() != '('){
                cout << pilha.top();
                pilha.pop();
            }
            pilha.pop();
        }
    }

    while(!pilha.empty()){
        cout << pilha.top();
        pilha.pop();
    }

    return 0;
}
