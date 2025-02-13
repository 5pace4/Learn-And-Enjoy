
//https://www.geeksforgeeks.org/given-array-strings-find-strings-can-chained-form-circle/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int isCircle(vector<string> &arr) {
        unordered_map<char, vector<char>> g;
        unordered_map<char, int> inDegree, outDegree;

        // Build the directed graph and degree mappings
        for (string &word : arr) {
            char u = word.front();
            char v = word.back();
            g[u].push_back(v);
            outDegree[u]++;
            inDegree[v]++;
        }

        return isEulerianCircuit(g, inDegree, outDegree) ? 1 : 0;
    }

private:
    bool isEulerianCircuit(unordered_map<char, vector<char>> &g, unordered_map<char, int> &inDegree, unordered_map<char, int> &outDegree) {
        char start = g.begin()->first;

        unordered_set<char> visited;
        stack<char> st;

        // Find a node with an outgoing edge to start DFS
        for (auto it = g.begin(); it != g.end(); ++it) {
            char ch = it->first;
            vector<char> &edges = it->second;
            if (!edges.empty()) {
                start = ch;
                break;
            }
        }

        st.push(start);
        while (!st.empty()) {
            char u = st.top();
            st.pop();
            if (visited.find(u) == visited.end()) {
                visited.insert(u);
                for (char v : g[u]) {
                    st.push(v);
                }
            }
        }

        // Ensure all nodes with edges are visited
        for (auto it = g.begin(); it != g.end(); ++it) {
            char ch = it->first;
            vector<char> &edges = it->second;
            if (!edges.empty() && visited.find(ch) == visited.end())
                return false;
        }

        // Check if in-degree and out-degree match for all nodes
        for (auto it = inDegree.begin(); it != inDegree.end(); ++it) {
            char ch = it->first;
            if (inDegree[ch] != outDegree[ch])
                return false;
        }

        return true;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
