#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 vector<int> sliding_window_max(vector<int> &a, int k) {
    vector<int>ans;

    deque<int>dq;
    for(int i = 0; i < a.size(); i++) {
        if(!dq.empty() and dq.front() == i - k) dq.pop_front(); //dq full?

        while(!dq.empty() and a[i] >= a[dq.back()]) dq.pop_back();

        dq.push_back(i);
        if(i >= k - 1)ans.push_back(a[dq.front()]);
    }
    return ans;
 }
int32_t main() {
     ios_base::sync_with_stdio(0);cin.tie(0);
     
     int n, k; cin >> n >> k; 
     vector<int>a(n);
     for(int i = 0; i < n; i++) cin >> a[i];

     vector<int>ans = sliding_window_max(a, k);
     for(auto &i:ans)cout << i << ' ';
     cout << '\n';
     return 0;
}


//https://www.youtube.com/watch?v=CZQGRp93K4k
