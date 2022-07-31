#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 3003, mod = 1e9 + 7;
int w[N], v[N], dp[N][N];
string a, b;
int lcs(int i, int j) {
    if(i >= a.size() or j >= b.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = max(lcs(i+1, j), lcs(i, j+1));
    if(a[i] == b[j]) ans = lcs(i+1, j+1) + 1;
    return dp[i][j] = ans;
}
void print(int i, int j) {
    if(i >= a.size() or j >= b.size()) return;
    if(a[i] == b[j]) {
        cout << a[i];
        print(i+1, j+1);
        return;
    }
    int x = lcs(i+1, j);
    int y = lcs(i, j+1);
    if(x > y) {
        print(i+1, j);
    }
    else {
        print(i, j+1);
    }
}
int32_t main() {
     ios_base::sync_with_stdio(0);cin.tie(0);
     memset(dp, -1, sizeof dp);
     cin >> a >> b;
     cout << lcs(0, 0) << '\n';
     print(0, 0);
     return 0;
}
