#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 100;
int par[N];
void init() { //create parent itself of a node
     for(int i = 1; i <= N; i++) {
          par[i] = i;
     }
}
int find(int u) { //find the parent of node u
     if(u==par[u])return u;
     return par[u] = find(par[u]);
}
void Union(int u, int v) { //union u and v
     int p = find(u);
     int q = find(v);
     if(p!=q) {
          par[q] = p; // now p is parent of q
     }
}
int32_t main() {
     ios_base::sync_with_stdio(0);cin.tie(0);
     
     init();
     Union(1, 3);
     cout<<find(1)<<' '<<find(3)<<'\n';
     return 0;
}
