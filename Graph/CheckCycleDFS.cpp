#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e5;
vector<int>g[N];
vector<bool>vis(N, false);
int node, edge;
bool CheckCycle(int u, int par) {
     vis[u] = true;
     for(auto v : g[u]) {
          if(!vis[v]) {
               if(CheckCycle(v, u)) return true;
          }
          else if(v != par) return true;
     }
     return false;
}
bool isCycle() {
     for(int i = 1; i <= node; i++) {
          if(!vis[i]) {
               if(CheckCycle(i, -1)) return true;
          }
     }
     return false;
}
int32_t main() {
     ios_base::sync_with_stdio(0);cin.tie(0);
     cin >> node  >> edge;
     for(int i = 0; i < edge; i++) {
          int u, v; cin >> u >> v;
          g[u].push_back(v);
          g[v].push_back(u);
     }
     if(isCycle()) {
          cout << "YES" << '\n';
     }
     else {
          cout << "NO" << '\n';
     }
     return 0;
}


/*

5 5
1 2
1 3
2 4
4 1 //remove this edge for acyclic graph
3 5

*/
