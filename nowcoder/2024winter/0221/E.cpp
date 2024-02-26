#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; cin>>n;
    vector<ll> a(n+10);
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1) goto yes;
    else if(n%2==0) goto yes;
    else {
        ll ct=0;
        for(int i=n-1;i>=1;i-=2) {
            a[i]+=i*ct;
            a[i-1]+=(i-1)*ct;
            if(a[i]>a[i+1]) goto no;
            ll nw=(a[i+1]-a[i])/i;
            ct+=nw;
            a[i]+=i*nw;
            a[i-1]+=i*nw;
        }
        if(is_sorted(a.begin(),a.end())) goto yes;
        else goto no;
    }
    if(0) yes: puts("YES");
    if(0) no: puts("NO");
}
int main() {
    int t; cin>>t;
    while(t--) solve();
}