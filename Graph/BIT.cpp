#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e5;
vector<int>a(N, 0), t(N, 0);
int n;
void updateBIT(int idx, int val) {
	while(idx <= n) {
		t[idx] += val;
		idx+=(idx & -idx);
	}
}
int query(int idx) {
	int sum = 0;
	while(idx > 0) {
		sum+=t[idx];
		idx-=(idx & -idx);
	}
	return sum;
}
int32_t main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		updateBIT(i, a[i]);
	}
	// l, r --> 4, 2
	cout << query(4) - query(1) << '\n';
	//upadate an index
	updateBIT(2, 5);
	cout << query(4) - query(1) << '\n';
	return 0;
}
