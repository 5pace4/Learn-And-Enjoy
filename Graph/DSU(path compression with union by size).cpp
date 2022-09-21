// Check : https://cp-algorithms.com/data_structures/disjoint_set_union.html#union-by-size-rank
#include<bits/stdc++.h>

using namespace std;
const int mxn = 1e5 + 7;
int parent[mxn], size[mxn];
void make_set(int u) {
     parent[u] = u;
     size[u] = 1;
}
int findrep(int u) {
     if(u == parent[u]) return u;
     return parent[u] = findrep(parent[u]); // Optimized : O(log n) //path compression
     //return findrep(parent[u]); //naive : O(n)
}
void unite(int u, int v) {
     u = findrep(u);
     v = findrep(v);
     if(u != v) {
          if(size[u] < size[v]) swap(u, v);
          parent[v] = u;
          size[u] += size[v]; //optimized : size of the trees as rank
     }
}
bool check(int u, int v) {
     return (parent[u] == parent[v]);
}
int32_t main() { 
     ios_base::sync_with_stdio(0);cin.tie(0);
     
     int n; cin >> n; 
     for(int i = 1; i <= n; i++) make_set(i);

     unite(1, 2);
     unite(1, 3);
     unite(2, 3);

     unite(4, 5);
     cout << check(1, 4) << '\n';
     cout << check(1, 3) << '\n';
     cout << check(2, 4) << '\n';
     cout << check(2, 3) << '\n';
     return 0;
}
