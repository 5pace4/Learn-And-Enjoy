//phase - 2 : Extra class of basic graph theory 

//Cyclic directed graph
//NOTE: It will also works for undirected graph
#include<bits/stdc++.h>

using namespace std;
const int N = 1e5;
vector<int>g[N];
int col[N]; //color active node and inactive node
			//active node -> red
			//inactive node -> blue
bool cycle;
void dfs(int u) {
	col[u] = 1; //red color -> 1
	for(auto v : g[u]) {
		if(col[v] == 0)dfs(v);
		else if(col[v] == 1) {
			cycle = true;
		}
	}
	col[u] = 2; //blue color -> 2
}
int32_t main() {
     ios_base::sync_with_stdio(0);cin.tie(0);
     
     int n, m; cin >> n >> m;
     for(int i = 0; i < m; i++) {
     	int u, v; cin >> u >> v;
     	g[u].push_back(v);
     }
     cycle = false;
     //dfs(1); // for connected graph

     // for disconnected graph
     for(int i = 1; i <= n; i++) {
     	if(col[i] == 0) dfs(i);
     }
     cout << (cycle?"YES\n" : "NO\n");

     return 0;
}
/*
3 3

1 2
2 3
3 1
*/
