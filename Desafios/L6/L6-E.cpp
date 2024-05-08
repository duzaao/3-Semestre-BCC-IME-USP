#include<bits/stdc++.h>

using namespace std;

vector<long long > adj[1000000];
bool visited[1000000];
bool flag;

void dfs(long long  v) {
	if(visited[v]) return;
	visited[v] = true;
	if(adj[v].size() != 2) flag = true; 
	for (long long  oi:adj[v]){ dfs(oi);}
}

int main() {
	long long  n, m;
	cin >> n >> m;
	for (long long  i = 0; i < m; i++) {
		long long  a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	long long  cycles = 0;
	memset(visited, 0, sizeof(visited));
	for (long long  i = 1; i <= n; i++) {
		if(!visited[i]){
		flag = false;
		dfs(i);
		if(!flag) cycles++;}
	}
	cout << cycles << endl;
	return 0;
}