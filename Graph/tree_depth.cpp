//tree_depth
#include<bits/stdc++.h>

using namespace std;
vector<int>g[105];
int depth[105];
void dfs(int u, int p) { // tree dfs // no need to visited array because tree has no cycle
	depth[u] = depth[p] + 1;
	for(auto v : g[u]) {
		if(v!= p) dfs(v, u);
	}
}
int32_t main() {
     ios_base::sync_with_stdio(0);cin.tie(0);
     
     int n; cin >> n;
     for(int i = 1; i < n; i++) {
     	int u, v; cin >> u >> v; 
     	g[u].push_back(v);
     	g[v].push_back(u);
     }
     dfs(1, 0);
     for(int i = 1; i <= n; i++) {
     	cout << depth[i] << ' ';
     }
     return 0;
}

/*
3 
1 2
2 3
*/

// https://csacademy.com/app/graph_editor/
