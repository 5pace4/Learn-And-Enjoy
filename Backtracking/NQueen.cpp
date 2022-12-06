#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int a[100][100], n; 
bool isValid(int row, int col) {
    for(int i = 0; i < col; i++) {
        if(a[row][i]) return false; //left side attack
    }
    for(int i = row, j = col; i>= 0 and j >= 0; i--, j--) {
        if(a[i][j]) return false; //upper left diagonal
    }
    for(int i = row, j = col; i >= 0 and j < n; i--, j++) {
        if(a[i][j]) return false; //lower right diagonal
    }

    return true;
}
bool SolveNQueen(int col) {
    if(col >= n) return true;
    for(int i = 0; i < n; i++) {
        if(isValid(i, col)) {
            a[i][col] = 1;
            if(SolveNQueen(col + 1)) return true;
            a[i][col] = 0; //backtrack
        }
    }
    return false;
}
void yoo() {
   cin >> n;
   SolveNQueen(0);
   for(int i = 0; i < n ; i++) {
    for(int j = 0; j < n; j++) {
        cout << a[i][j] << ' ';
    }
    cout <<'\n';
   }
}
int32_t main() {
     ios_base::sync_with_stdio(0);cin.tie(0);
     
     int T; cin >> T;
     while(T--) yoo();
     
     return 0;
}

