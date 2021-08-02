#include<bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long long;
//Divide and Conquer(maximum sum subarray)
//complexity O(n)
int max_sum_subarray(int arr[], int n, int* low, int* high)
{
     int mid=n/2;
   int left_sum=-100000, max_left=0;
   int sum=0;
   for(int j=mid; j>=0; j--){
       sum+=arr[j];
       if(sum>left_sum){          //13 -3 -25 20 -3 -16 -23 18 20 -7 12 -5 -22 15 -4 7
           left_sum=sum;
           max_left=j;
       }
   }
   int right_sum=-100000, max_right=0;
   sum=0;
   for(int k=mid+1; k<n; k++){
       sum+=arr[k];
       if(sum>right_sum){
           right_sum=sum;
           max_right=k;
       }
   }
   *low=max_left;
   *high=max_right;
   return left_sum+right_sum;
}
int main()
{
   int n;
   cin>>n;
   int arr[n];
   for(int i=0; i<n; i++){
       cin>>arr[i];
   }
  
   int low, high, sum;
   sum=max_sum_subarray(arr, n, &low, &high);
   cout<<low<<" "<<high<<" "<<sum<<'\n';
   
    return 0;
}