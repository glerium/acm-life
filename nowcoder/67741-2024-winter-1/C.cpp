#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn=1e5+10;
int _,n,q,tc;
ll m,t[maxn],s[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>q>>tc;
    rep(i,1,n) cin>>t[i];
    sort(t+1,t+1+n);
    rep(i,1,n) s[i]=s[i-1]+t[i];
    while(q--) {
        cin>>m;
        ll ct=m/tc;
        cout<<s[max(0ll,n-ct)]+tc<<endl;
    }
    return 0;
}