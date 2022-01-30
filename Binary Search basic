#include<bits/stdc++.h>

using namespace std;
int Binary_Search(int arr[], int n, int x) {
	int low = 0, high = n - 1;

	while(low <= high) {
		int mid =  (low + high) / 2;

		if(arr[mid] == x) return mid;
		else if(x > arr[mid])low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}
//find first occurance of x
int first_occurance(int arr[], int n, int x) {
	int low = 0, high = n - 1;

	int ans = -1;
	while(low <= high) {
		int mid =  (low + high) / 2;

		if(arr[mid] == x) {
			high = mid - 1;
			ans = mid;
		}
		else if(x > arr[mid])low = mid + 1;
		else high = mid - 1;
	}
	return ans;
}
//find last occurance of x
int last_occurance(int arr[], int n, int x) {
	int low = 0, high = n - 1;

	int ans = -1;
	while(low <= high) {
		int mid =  (low + high) / 2;

		if(arr[mid] == x) {
			low = mid + 1;
			ans = mid;
		}
		else if(x > arr[mid])low = mid + 1;
		else high = mid - 1;
	}
	return ans;
}
int bsrecursive(int low, int high, int arr[], int x) {
	if(low > high)return -1;
	int mid = (low + high)/2;
	if(arr[mid] == x)return mid;
	else if(x > arr[mid]) return bsrecursive(mid + 1, high, arr, x);
	return bsrecursive(low, mid - 1, arr, x);
}
//finding lower bound : first element >= x
int lb(int arr[], int n, int x) {

	int ans = n; // if x is higher than the max element of the array ,
	             // then it returns the n'th index
	int low = 0, high = n - 1;
	while(low <= high) {
		int mid = ( low + high ) / 2;
		if(arr[mid] >= x) {
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}
//finding upper bound : first element > x
int ub(int arr[], int n, int x) {
	int ans = n; // if x is higher than the max element of the array ,
	             // then it returns the n'th index
	int low = 0, high = n - 1;
	while(low <= high) {
		int mid = ( low + high ) / 2;
		if(arr[mid] <= x) {
			low = mid + 1;
		}
		else {
			ans = mid;
			high = mid - 1;
		}
	}
	return ans;
}
//find the occurance of element x
int occurance(int arr[], int n, int x) {
	return ub(arr, n, x) - lb(arr, n, x); //think how can use first occurance
	                                      // and last occurance concept
}
//find the integer square root n using binary search
int SQRT(int n) {
	int low = 1, high = n, mid;
	while(low <= high) {
		mid = (low + high) / 2;
		if(mid * mid > n) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return mid;
}
int main() {

	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
    int x;
    cin >> x;
    cout << Binary_Search(arr, n, x) << '\n';
    cout << first_occurance(arr, n, x) << '\n'; 
    cout << last_occurance(arr, n, x) << '\n'; 
    cout << lb(arr, n, x) << '\n';
    cout << ub(arr, n, x) << '\n';
    cout << occurance(arr, n,  x) << '\n';
    cout << SQRT(x) << '\n';
	return 0;
}
//input :
// 12
// 1 2 3 4 4 4 5 5 5 6 8 9
// 5

//output :
// 8
// 6
// 8
// 6
// 9
// 3
// 2

//note : to avoid overflow condition use : mid = low + (high - low)/2
