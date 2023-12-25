#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn=2e5+10;
int t,n;
ll l[maxn],r[maxn],k[maxn],d[maxn];
set<ll> st;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        st.clear();
        cin>>n;
        rep(i,1,n) cin>>l[i];
        rep(i,1,n) cin>>r[i];
        rep(i,1,n) cin>>k[i];
        rep(i,1,n) st.insert(r[i]);
        sort(l+1,l+1+n);
        sort(r+1,r+1+n);
        sort(k+1,k+1+n);
        ll ans=0;
        for(int i=n;i>=1;i--) {
            auto found=st.upper_bound(l[i]);
            d[i]=*found-l[i];
            st.erase(found);
        }
        sort(d+1,d+1+n,greater<ll>());
        rep(i,1,n) ans+=d[i]*k[i];
        cout<<ans<<endl;
    }
}