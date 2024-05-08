
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 110;

int n, e, t, m;
int visited[MAXN];
int dist[MAXN];
vector<pair<int, int> > adj[MAXN];

void dijkstra(int ini){
    memset(visited, 0, sizeof(visited));
    memset(dist, -1, sizeof(dist));

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > queue;

    queue.push(make_pair(0, ini));

    while(!queue.empty()){
        pair<int, int> p = queue.top();
        int v = p.second;
        int d = p.first;
        queue.pop();

        if(visited[v]) continue;

        visited[v] = 1;
        dist[v] = d;

        for(auto x : adj[v]){
            int vizinho = x.second;
            int d = x.first;
            if(!visited[vizinho]){
                queue.push(make_pair(dist[v] + d, vizinho));
            }
        }
    }
}

int main(){

    int ans = 0;
    cin >> n >> e >> t >> m;

    for(int i = 0 ; i < m ; i++){
        int a, b, p; cin >> a >> b >> p;
        adj[a].push_back(make_pair(p, b));
    }

    for(int i = 1 ; i <= n ; i++){
        dijkstra(i);
        if(dist[e] <= t && dist[e] >= 0) ans++;
    }

    cout << ans << endl;
}