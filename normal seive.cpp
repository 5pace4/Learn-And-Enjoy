#include<bits/stdc++.h>

using namespace std;
#define N 1000000
bool prime[N];
void sieve(){
   memset(prime, true, sizeof(prime));
   prime[0] = prime[1] = 0;

   for(int i = 2; i * i <= N; i++){
       if(prime[i]){
           for(int j = i * i;  j <= N; j+=i){
               prime[j]=false;
           }
       }
   }
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  sieve();
  return 0;
}
