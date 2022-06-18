#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e5;
vector<int>a(N, 0), t(N, 0);
int n;
class FenWickTree {
	public:
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
};
int32_t main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	
	FenWickTree obj;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		obj.updateBIT(i, a[i]);
	}
	// l, r --> 4, 2
	cout << obj.query(4) - obj.query(1) << '\n';
	//upadate an index
	obj.updateBIT(2, 5);
	cout << obj.query(4) - obj.query(1) << '\n';
	return 0;
}
