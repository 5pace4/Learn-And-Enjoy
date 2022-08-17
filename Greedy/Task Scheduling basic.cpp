// task scheduling :  unweighted task
// remember : always sort the the array depending on the finishing time
// Tutorial : https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/

#include<bits/stdc++.h>

using namespace std;
#define int long long
bool sortbysec(const pair<int, int>&a, const pair<int, int>&b) {
     return a.second < b.second;
}
void yoo() {
     int n; cin >> n;
     vector<int>start(n);
     for(auto &i:start)cin>>i;
     vector<int>finish(n);
     for(auto &i:finish)cin>>i;
     vector<pair<int, int>>a;
     for(int i = 0; i < n; i++) {
          //int s, e; cin >> s >> e;
          a.push_back({start[i], finish[i]});
     }
     sort(a.begin(), a.end(), sortbysec);
     int ans = 1; int u = 1;
     for(int i = 1; i < n; i++) {
          if(a[i].first >= a[u - 1].second)u = i, ans++;
     }
     cout << ans << '\n';
}
int32_t main() {
     ios_base::sync_with_stdio(0);cin.tie(0);
     
     yoo();
     return 0;
}

/* 
Sample case 01:
6
1 3 0 5 8 5
2 4 6 7 9 9

output : 4

*/
