//Check a grpah bipartite/bicoloring or not
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e5 + 9;
vector<int>g[N];
bool vis[N], ok; int col[N]; //coloring array -> color every node 0(red) or 1(black)
int node, edge;
void dfs(int u) {
    vis[u] = true;
    for(auto v : g[u]) {
        if(!vis[v]) {
            col[v] = col[u] ^ 1; // 1 converts 0 and 0 converts 1
            dfs(v);
        }
        else {
            if(col[u] == col[v]) {
                ok = false;
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin>>node>>edge;
     for(int i = 0; i < edge; i++) {
        int u, v;;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
     }
     ok = true;
     //dfs(1); // If conneceted

     /// If the graph is disconnected
     for(int i = 1; i <= node; i++) {
        if(!vis[i]) dfs(i);
     }
     /// end traversing all node
     if(ok) {
        cout << "Bipartite\n";
     }
     else {
        cout << "Not bipartite\n";
     }
    return 0;
}
