#include<bits/stdc++.h>
using namespace std;
const int N = 200;
int a[N], dp[N][N];
int n, s;
int CoinChange(int i, int target) {
   if(target == 0) return dp[i][target] = 1;
   if(i < 0) return 0;
   if(dp[i][target] != -1) return dp[i][target];

   if(a[i] <= target) return dp[i][target] = CoinChange(i, target-a[i]) + CoinChange(i-1, target);

   else return dp[i][target] = CoinChange(i-1, target);

}
int32_t main() {
     ios_base::sync_with_stdio(0);cin.tie(0);
     memset(dp, -1, sizeof dp);
     cin >> n >> s;
     for(int i = 0; i < n; i++) cin >> a[i];
     cout << CoinChange(n-1, s) << '\n';
     return 0;
}

