//https://www.geeksforgeeks.org/problems/prerequisite-tasks/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        
        vector<vector<int>>adj(N);
        vector<int>inDegree(N, 0);
        for(int i = 0; i < P; i++) {
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
            inDegree[prerequisites[i].first]++;
            
        }
        queue<int>q;
        int count = 0;
        for(int i = 0; i < N; i++) {
            if(inDegree[i] == 0) q.push(i);
        }
        // vector<int>ans; //store ordering in ans
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            count++;
            // ans.push_back(u);
            for(auto v:adj[u]) {
                inDegree[v]--;
                if(inDegree[v] == 0) q.push(v);
            }
        }
        
        return count == N;
    }
   
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
