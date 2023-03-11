#include<bits/stdc++.h>

using namespace std;
int partition(int a[], int b, int e) {
    int pivot = a[e]; // always choose the end element as pivot
    int Pindex = b;
    for(int i = b; i < e; i++) {
        if(a[i] <= pivot) {
            swap(a[i], a[Pindex]);
            Pindex++;
        }
    }
    swap(a[Pindex], a[e]);
    return Pindex;
}
void QuickSort(int a[], int b, int e) {
    if(b < e) {
        int p = partition(a, b, e);
        QuickSort(a, b, p - 1);
        QuickSort(a, p+1, e);
    }
}
int main() {
    int n; cin >> n; int a[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i];

    QuickSort(a, 1, n);
    
    for(int i = 1; i <= n; i++) cout << a[i] << ' ';
        
    return 0;
}
