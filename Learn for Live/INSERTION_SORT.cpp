#include<bits/stdc++.h>

using namespace std;
void INSERTION_SORT(vector<int>&a, int n) {
    for(int i = 1; i < n; i++) {
        int item = a[i], j = i - 1;
        while(a[j] > item and j >= 0) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = item;
    }
}

int main() {
    int n; cin >> n; vector<int>a(n);
    for(auto &x:a)cin>>x;
    INSERTION_SORT(a, n);
    for(auto &x:a)cout<<x<<' ';
    return 0;
}
