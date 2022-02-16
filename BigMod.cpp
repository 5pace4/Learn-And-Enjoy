#include<bits/stdc++.h>

using namespace std;
#define int long long 
#define M 1000000007
int recursive_exp(int a, int b){ ///recursively 
    if(b == 1)return a % M;
    if(b % 2 == 0){
        int x = recursive_exp(a, b/2);
        return x * x % M;
    }
    else{
        int x = recursive_exp(a, b/2);
        return (x * x % M ) * a % M;
    }
}
int iterative_exp(int a, int b){ /// iterative way == binary exp
    int ans = 1;
    while(b){
        if(b & 1)ans = ans * a % M;
            a = a * a % M;
            b/=2; 
    }
    return ans;
}
int binary_exp(int a, int b){
    int ans = 1;
    for(int i = 0;  i < 64; i++){
        if((b >> i) & 1){
            ans = ans * a % M;
        }
        a = a * a % M;
    }
    return ans;
}
int add_mod(int a, int b){
    return (a%M + b%M)%M;
}
int mul_mod(int a, int b){
    return (a%M * b%M)%M;
}
int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  
  cout << recursive_exp(3, 1000000000) << '\n';
  cout <<  iterative_exp(3, 1000000000) << '\n';
  cout <<  binary_exp(3, 1000000000) << '\n';
  return 0;
}
// in (a/b) % M ; use fermat's little theorem a^-1 % P = a^(P-2) % P 
