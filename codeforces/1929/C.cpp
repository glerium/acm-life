#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int k,x,a; cin>>k>>x>>a;
    if(a<=1) {
        puts("NO");
        return;
    }
    vector<int> r(x+5);
    r[1]=1;
    int s=r[1];
    for(int i=2;i<=x;i++) {
        r[i]=s/(k-1)+1;
        // cout<<r[i]<<endl;
        s+=r[i];
        if(a<s) {
            puts("NO");
            return;
        }
    }
    r[x+1]=a-s;
    // for(int i=1;i<=x;i++) cout<<r[i]<<endl;
    s+=r[x+1];
    if(s>=r[x+1]*k||a<s) puts("NO");
    else puts("YES");
}
signed main() {
    int t;cin>>t;
    while(t--) solve();
}