#include<bits/stdc++.h>

using namespace std;
#define int long long
const int inf = 1e18 + 9;
const int N = 1e5 + 7;

//typedef pair<int, int>  ipair;

vector<pair<int, int>>g[N];
vector<int>dis(N, inf);
int n, e;
void Dijkstra(int source) {
   priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>>pq;
   pq.push({0, source});
   dis[source] = 0;
   int par[n+1];
   while(!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      for(auto x:g[u]) {
         int v = x.first;
         int wt = x.second;
         if(dis[v] > dis[u] + wt) {
            dis[v] = dis[u] + wt;
            pq.push({dis[v], v});
            par[v] = u;
         }
      }
   }


  /*
   // shortest path from 1 to N
   if(dis[n] == inf) {
      cout<<-1<<'\n';
      return;
   }
   int p = n;
   vector<int>path;
   path.push_back(p);
   while(p!=1) {
      p = par[p];
      path.push_back(p);
   }
   reverse(path.begin(), path.end());
   for(auto x:path)cout<<x<<' ';
   cout<<'\n';
 */
}
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> e;
    for(int i=1; i <= e; i++) {
      int u, v, c; cin >> u >> v >> c;
      g[u].push_back({v, c});
      g[v].push_back({u, c});
    }
    Dijkstra(1); //source -> 1
    return 0;
}
