// this problem was solved in GFG: https://www.geeksforgeeks.org/problems/detect-cycle-using-dsu/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
   int detectCycle(int V, vector<int>adj[])
   {
       vector<int>par(V);
       vector<int>size(V, 0);
       for(int i = 0; i < V; i++) {
           par[i] = i;
           size[i]++;
       }
       for(int u  = 0; u < V; u++) {
           for(auto v: adj[u]) {
               if(v <= u) continue; // Skip reverse edges and duplicates
               
               int rep_u = findrep(u, par);
               int rep_v = findrep(v, par);
               
               if(rep_u == rep_v) return 1;
               union_(u, v, par, size);
               
           }
       }
       return 0;
       
   }
   private:
   void union_(int u, int v, vector<int> &par, vector<int>&size) {
       u = findrep(u, par);
       v = findrep(v, par);
       
       if(u!=v) {
           if(size[u] < size[v]) swap(u, v);
           par[v] = u;
           size[u]+=size[v];  //optimized : size of the trees as rank
       }
       
   }
   int findrep(int u, vector<int>&par) {
       if(u == par[u]) return u;
       return par[u] = findrep(par[u], par); //path compression: O(logn)
   }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int V, E;
      cin >> V >> E;
      vector<int>adj[V];
      for(int i = 0; i < E; i++){
         int u, v;
         cin >> u >> v;
         adj[u].push_back(v);
         adj[v].push_back(u);
      }
      Solution obj;
      int ans = obj.detectCycle(V, adj);
      cout << ans <<"\n";  
cout << "~" << "\n";
}
   return 0;
}
// } Driver Code Ends
