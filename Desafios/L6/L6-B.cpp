#include<bits/stdc++.h>

using namespace std;

int colunas, linhas;
char labirinto[1002][1002];
int distancias[1005][1005];
int moveX[] = {-1, 0, 1, 0};
int moveY[] = {0, 1, 0, -1};

bool isOk(int x, int y){
if(x >= linhas || x < 0 || y >= colunas || y < 0 || distancias[x][y] != 0 || labirinto[x][y] == '#')
return false;
return true;
}

void dfs(pair<int, int> v){
for(int i = 0 ; i < 4 ; i++){
int x = v.first + moveX[i];
int y = v.second + moveY[i];
if(isOk(x, y)){
distancias[x][y] = distancias[v.first][v.second] + 1;
dfs(make_pair(x, y));
}
}
}

int main(){
    int t; cin >> t;

while(t--){
    cin >> colunas >> linhas;
    pair<int, int> livre;
    memset(distancias, 0, sizeof(distancias));

    for(int i = 0 ; i < linhas ; i++){
        for(int j = 0 ; j < colunas ; j++){
            cin >> labirinto[i][j];
            if(labirinto[i][j] == '.'){
                livre.first = i;
                livre.second = j;
            }
        }
    }

    dfs(livre);

    pair<int, int> ponta;
    for(int i = 0 ; i < linhas ; i++){
        for(int j = 0 ; j < colunas ; j++){
            if(distancias[i][j] > distancias[ponta.first][ponta.second]){
                ponta.first = i;
                ponta.second = j;
            }
        }
    }

    memset(distancias, 0, sizeof(distancias));
    dfs(ponta);

    int resposta = 0;
    for(int i = 0 ; i < linhas ; i++){
        for(int j = 0 ; j < colunas ; j++)
            resposta = max(resposta, distancias[i][j]);
    }

    cout << "Maximum rope length is " << resposta << "." << endl;
}
return 0;
}