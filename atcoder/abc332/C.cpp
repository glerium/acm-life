#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a,b,mx;
string s;
int main() {
    cin>>n>>m>>s;
    for(auto i:s) {
        if(i=='0') a=0,b=0;
        else if(i=='1'&&a<m)
            a++;
         else {
             b++;
             mx=max(mx,b);
         }
    }
    cout<<mx<<endl;
    return 0;
}