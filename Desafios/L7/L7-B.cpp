#include<bits/stdc++.h>

using namespace std;

bool visited[10][10];
int dist[10][10];
int dx[] = {2, 2, -2, -2, 1, -1, 1, -1};
int dy[] = {1, -1, 1, -1, 2, 2, -2, -2};

bool isOk(int x, int y){
    if(x < 0 || x > 7 || y < 0 || y > 7 || visited[x][y]) return false;
    return true;
}

void bfs(int iniX, int iniY){
    memset(visited, false, sizeof(visited));
    memset(dist, -1, sizeof(dist));

    queue<pair<int, int> > queue;
    queue.push(make_pair(iniX, iniY));
    dist[iniX][iniY] = -1;

    while(!queue.empty()){
        pair<int, int> p = queue.front();
        queue.pop();
        int vX = p.first;
        int vY = p.second;

        if(visited[vX][vY]) continue;

        visited[vX][vY] = true;
        for(int i = 0 ; i < 8 ; i++){
            int newX = vX + dx[i];
            int newY = vY + dy[i];
            if(isOk(newX, newY)){
                queue.push(make_pair(newX, newY));
                dist[newX][newY] = dist[vX][vY] + 1;
            }
        }
    }
}

int main(){

    int t; cin >> t;
    while(t--){
        string ini, fim; cin >> ini >> fim;
        int iniX = ini[0] - 97;
        int iniY = ini[1] - 49;
        int fimX = fim[0] - 97;
        int fimY = fim[1] - 49;

        bfs(iniX, iniY);
        cout << dist[fimX][fimY] + 1 << endl;
    }
}