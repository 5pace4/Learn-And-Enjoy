// C++ STL basic
#include<bits/stdc++.h>

using namespace std;
int32_t main() {
     ios_base::sync_with_stdio(0);cin.tie(0);
     /***********************************************************/
     //lambda expression
     int a = 10, b = 20;
     function<int(int, int)> sum = [](int a, int b) {
        return a+b;
     };
     cout << sum(a, b) << '\n';
     function<int(int)> factorial = [&](int n) {
        if(n == 0) return 1;
        return n * factorial(n-1);
     };
     cout << factorial(5) << '\n';

     /***********************************************************/
     //tie function and structured binding

     //tie function
     pair<int, int>p = {1, 2};
     tie(a, b) = p; 
     cout << a << ' ' << b << '\n';
     tuple<int, string , double> t = {1904005, "tofayel", 3.61};
     int x; double z; string s;
     tie(x, s, z) = t;
     cout << x << ' ' << s << ' ' << z << '\n';

     //structured binding  ///// can be used in std=gnu++17
    // auto [m, n] = p;
     //cout << m << ' ' << n << '\n';
    // auto [p, name, q] = t;
    // cout << p << ' ' << name << ' ' << q << '\n';

    /***********************************************************/


    //C++ array
    //generally we don't need to use c++ array, beacuse 
    //we can do all operation using c array.
    // for c++ array -> add #include<array>

    //Declaration : array<data type, size>array_name

    array<int, 5> arr = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++)cout<<arr[i]<< ' ';
    cout<<'\n';

    //iterator : we can use iterator for any kind of c++ stl container
    
    //declaration : array<DataType, size> ::iterator it = a.begin()
    // we can simply use auto it = a.begin();

    array<int, 5>::iterator ita;
    for(ita = arr.begin(); ita!=arr.end(); ita++)  cout<<(*ita)<<' ';
    cout<< '\n';

    for(auto it : arr) cout << it << ' ';
    cout<<'\n';

    
    /***********************************************************/

    //C++ vector 
    //vector is like a resizeable array
    
    //Initializing 
    
    vector<int>v1 ; // v1 = {}
    vector<int>v2(5); //v2 = {0, 0 , 0 , 0, 0}
    vector<string>v3 = {"Tofayel", "Refaj", "Jisun"};

    //Some useful function of vector:
           /*
              1.push_back()
              2.emplace_back() == push_back()
              3.pop_back()
              4.size()
              5.erase()
              6.insert()
              7.clear()

            */
    /***********************************************************/

    

     return 0;
}
//Lambda Expression
// function<ReturnType(Parameters)> functionName = [capture](parameters){/*body*/};
