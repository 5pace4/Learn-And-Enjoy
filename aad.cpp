//big number adition
#include<bits/stdc++.h>

using namespace std;
using ll=long long;
string bigSum(string s1, string s2){
    string sum="";
    if(s1.size()>s2.size()){
        swap(s1, s2);
    }
    int ln1=s1.size(), ln2= s2.size(), intsum=0, carry=0;
     int digitdiffer=ln2-ln1;
    for(int i=ln1-1; i>=0; i--){
        intsum=(s1[i]-'0')+(s2[i+digitdiffer]-'0')+carry;
        sum.push_back(intsum%10+'0');
        carry=intsum/10;       
    }
    for(int i=digitdiffer-1; i>=0; i--){
        intsum=(s2[i]-'0')+carry;
        sum.push_back(intsum%10+'0');
        carry=intsum/10; 
    }
    if(carry)
      sum.push_back(carry+'0');

    reverse(sum.begin(), sum.end());
    return sum;
}
int main(){
      string s1, s2;
      cin>>s1>>s2;
      cout<<bigSum(s1, s2)<<endl;

}