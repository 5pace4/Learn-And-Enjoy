// this problem is solved int GFG: https://www.geeksforgeeks.org/problems/number-of-provinces/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>>g(V);
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(adj[i][j])g[i].push_back(j);
            }
        }
        int connected_component = 0;
        vector<int>vis(V, 0);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                connected_component++;
                DFS(i, g, vis);
            }
        }
        return connected_component;
    }
    private:
    void DFS(int u, vector<vector<int>> &g, vector<int>&vis) {
        vis[u] = 1;
        for(auto v:g[u]) {
            if(!vis[v]) {
                DFS(v, g, vis);
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
