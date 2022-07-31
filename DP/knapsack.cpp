#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 105, mod = 1e9 + 7;
int w[N], v[N], dp[N][100005];
int n, W;
int KnapSack(int i, int weight) {
  if(i > n) return 0;
  if(dp[i][weight] != -1) return dp[i][weight];
  int ans = KnapSack(i+1, weight);
  if(weight + w[i] <= W) ans = max(ans, KnapSack(i+1, weight + w[i]) + v[i]);
  return dp[i][weight] = ans; 
}
int32_t main() {
     ios_base::sync_with_stdio(0);cin.tie(0);
     memset(dp, -1, sizeof dp);
     cin >> n >> W;
     for(int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
     }
     cout << KnapSack(1, 0) << '\n';
     return 0;
}
