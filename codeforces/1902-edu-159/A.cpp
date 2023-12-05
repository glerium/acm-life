#include <bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>s;
        bool zero=false,one=false;
        for(auto i:s) if(i=='1') one=1;
        for(auto i:s) if(i=='0') zero=1;
        if(zero&&one) {
            puts("YES");
        }else if(!one) {
            puts("YES");
        }else{
            puts("NO");
        }
    }
    return 0;
}