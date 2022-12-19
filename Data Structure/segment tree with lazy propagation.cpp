#include<bits/stdc++.h>

using namespace std;

const int N = 3e5 + 9;
int a[N];
struct ST {
    #define lc (n << 1)
    #define rc ((n << 1) + 1)
    long long t[4*N], lazy[4*N];

    ST() {
        memset(t, 0, sizeof t);
        memset(lazy, 0, sizeof lazy);
    }
    inline void push(int n, int b, int e) { // change this
        if(lazy[n] == 0) return;
        t[n] = t[n] + lazy[n] * (e - b + 1);
        if(b != e) {
            lazy[lc] = lazy[lc] + lazy[n];
            lazy[rc] = lazy[rc] + lazy[n];
        }
        lazy[n] = 0;
    }
    inline long long combine(long long a, long long b) {
        return a + b; //change this
    }
    inline void pull(int n) {
        t[n] = t[lc] + t[rc]; //change this
    }
    void build(int n, int b, int e) {
        lazy[n] = 0; //change this
        if(b==e) {
            t[n] = a[b];
            return ;
        }
        int m = (b+e) >> 1;
        build(lc, b, m);
        build(rc, m+1, e);
        pull(n);
    }
    void update(int n, int b, int e, int i, int j, long long v) {
        push(n, b, e);
        if(j < b || e < i) return;
        if(i <= b && e <= j) {
            lazy[n] = v; //set lazy
            push(n, b, e);
            return;
        }
        int m = (b+e) >> 1;
        update(lc, b, m, i, j, v);
        update(rc, m+1, e, i, j, v);
        pull(n);

    }
    long long query(int n, int b, int e, int i, int j) {
        push(n, b, e);
        if(i > e || b > j) return 0; //return null
        if(i <= b && e <= j) return t[n];
        int m = (b + e) >> 1;
        return combine(query(lc, b, m, i, j), query(rc, m + 1, e, i, j));
    }
}t;
int main() {
    int n = 5;
    for(int i = 1; i <= n; i++) {
        a[i] = i;
    }
    t.build(1, 1, n); //building the segment tree
    t.update(1, 1, n, 2, 3, 10); // adding 10 to the segment [2, 3]
    cout << t.query(1, 1, n, 1, 5) << '\n'; //range sum query on the segment
    return 0;
}
