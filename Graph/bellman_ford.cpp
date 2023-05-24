#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int inf = 1e9;
vector<vector<int>>g;
int n, e;
vector<int> BellmanFord(int source) {
    vector<int>dis(n+1, inf);
    dis[source] = 0;
    // N - 1 times relaxation
    for(int i = 0; i < n - 1; i++) {
        for(auto it:g) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dis[u] != inf && dis[u] + wt < dis[v]) { //relaxation
                dis[v] = dis[u] + wt; 
            }
        }
    }

    //check negative cycle by n'th relaxation
    for(auto it:g) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dis[u] != inf && dis[u] + wt < dis[v]) {
                return {-1};
        }
     }
     return dis;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> e;
    for(int i = 0; i < e; i++) {
        int u, v, w; cin >> u >> v >> w;
        g.push_back({u, v, w});
    }
    vector<int>dis = BellmanFord(1);
    if(dis[0] == -1)cout<<"Exist negative cycle.";
    else for(int i = 0; i < n ; i++) cout << dis[i] << ' ';
    cout << '\n'; 
}
/*
test case 1:
5 5
1 0 5
1 2 2
1 4 6
2 3 3
3 1 4

test case 2:
3 3
0 1 -1
1 2 -2
2 0 -3
*/

//Tryout it: https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1
