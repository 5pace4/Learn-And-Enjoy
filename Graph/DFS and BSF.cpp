#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 9;
vector<int>g[N];
bool vis[N];
int node, edge;
int com = 0;
vector<int>c(N);
void update() {
	memset(vis, false, sizeof vis);
}
void dfs(int u) {
	vis[u] = true;
	c[u] = com; //numbering components
	//cerr<<u<< ' '; // preorder traversal
	for(auto v : g[u]) {
		if(!vis[v]) {
			dfs(v);
		}
	}
	//cout<<u<<' '; // postorder traversal
}
void bsf(int node) {
	queue<int>q;
	q.push(node);
	vis[node] = true;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		cout << u << ' ';
		for(auto v : g[u]) {
			if(!vis[v]) {
				q.push(v);
				vis[v] = true;
			}
		}
	}
}
int main() {
     ios_base::sync_with_stdio(0);cin.tie(0);

     cin>>node>>edge;
     for(int i = 0; i < edge; i++) {
     	int u, v;;
     	cin >> u >> v;
     	g[u].push_back(v);
     	g[v].push_back(u);
     }

     //*************************************************************//

     //DFS start from here:

     //dfs(1);

     //number of connected components
     // int ans = 0;
     // for(int i = 1; i <= node; i++) {
     // 	if(!vis[i]) {
     // 		com++;
     // 		dfs(i);
     // 	}
     // }
     //cout << "Connected Components : " << ans << '\n';

     //************************************************************//
     //find whether a path (u, v) or not
     // given Q query: (node, edge, query) --> 1e5

     // Monkey Way:
     // int q;
     // cin >> q;
     // while(q--) {
     // 	update();
     // 	int u, v;
     // 	cin >> u >> v;
     // 	dfs(u);
     // 	if(vis[v]) {
     // 		cout<<"Connected\n";
     // 	}
     // 	else {
     // 		cout<<"Disconnected\n";
     // 	}
     // }

     //***********************************************************//
     //Human way:
     //At first we save the all components i.e. we will define 
     //which node situate in which components;

     // for(int i = 1; i <= node; i++) {
     // 	if(!vis[i]) {
     // 		dfs(i);
   		// 	com++;
     // 	}
     // }
     // int q;
     // cin >> q;
     // while(q--) {
     // 	int u, v;
     // 	cin >> u >> v;
     // 	if(c[u] == c[v]) {
     // 		cout<<"Have a path\n";
     // 	}
     // 	else  {
     // 		cout << "Don't have any path\n";
     // 	}
     // }

     //*********************************************************//
     //BSF start from here:
     //bsf(1);

     //Why we use bfs?

     // one important reason - we can find out the minimum distance of every node from the root nood

     // int dis[node + 1];
     // queue<int>q;
     // q.push(1);
     // vis[1] = true; dis[1] = 0;
     // while(!q.empty()) {
     //      int u = q.front();
     //      q.pop();
     //      //cout << u << ' ';
     //      for(auto v : g[u]) {
     //           if(!vis[v]) {
     //                q.push(v);
     //                dis[v] = dis[u] + 1;
     //                vis[v] = true;
     //           }
     //      }
     // }
     // for(int i = 1; i <= node ; i++) {
     //      cout << dis[i] << ' ';
     // }

      //**************************************************************//
     //Find the minimum path:
     // u1 -> u2 -> u3 -> u4

     int par[node + 1];
     queue<int>q;
     q.push(1);
     vis[1] = true;
     while(!q.empty()) {
          int u = q.front();
          q.pop();
          //cout << u << ' ';
          for(auto v : g[u]) {
               if(!vis[v]) {
                    q.push(v);
                    par[v] = u; 
                    vis[v] = true;
               }
          }
     }
     //suppose, we want to find the shortest path from 1 to 4
     int find = 4;
     while(find!=1) {
          cout << find << ' ';
          find = par[find];
     }
     cout << find << '\n';
	return 0; 
}
//DFS graph
/*
10 8       //node, edge//
1 2
1 3
2 4 
2 5
5 6
7 8 
7 9 
10 7
3          //Query
1 7
8 10
1 6
*/

///BFS graph
/*
4 5 //node , edge//
1 2 
1 3
2 3
2 4 
3 4
*/
