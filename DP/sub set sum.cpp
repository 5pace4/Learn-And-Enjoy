#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 200;
int a[N], dp[N][N];
int n, s;
int SubsetSum(int i, int target) {
   if(target == 0) return 1;
   if(i == 0) return (a[i] ==  target);
   if(dp[i][target] != -1) return dp[i][target];

   bool ans = false;
   if(a[i] <= target) ans = SubsetSum(i-1, target-a[i]);

   return dp[i][target] = ans | SubsetSum(i-1, target);

}
int32_t main() {
     ios_base::sync_with_stdio(0);cin.tie(0);
     memset(dp, -1, sizeof dp);
     cin >> n >> s;
     for(int i = 0; i < n; i++) cin >> a[i];
     cout << SubsetSum(n-1, s) << '\n';
     return 0;
}

