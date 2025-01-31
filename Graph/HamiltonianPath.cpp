//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool check(int N, int M, vector<vector<int>>& Edges) {
        vector<vector<int>> adj(N);
        
        for (int i = 0; i < M; i++) {
            adj[Edges[i][0] - 1].push_back(Edges[i][1] - 1);
            adj[Edges[i][1] - 1].push_back(Edges[i][0] - 1);
        }

        vector<int> vis(N, 0);
        
        for (int i = 0; i < N; i++) {
            if (dfs(i, N, 1, adj, vis)) return true;
        }
        return false;
    }

private:
    // DFS function for Hamiltonian Path
    bool dfs(int node, int N, int count, vector<vector<int>>& adj, vector<int>& vis) {
        if (count == N) return true; 

        vis[node] = 1;
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (dfs(neighbor, N, count + 1, adj, vis)) return true;
            }
        }
        vis[node] = 0; // Backtrack
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	
cout << "~" << "\n";
}
}
// } Driver Code Ends
