#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int t,n,m,a[maxn],p[maxn],v[maxn];
typedef long long ll;
vector<int> sta(maxn<<1);
void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>p[i]>>v[i];
    map<int,int> ct;
    set<int> st, stall;
    for(int i=1;i<=n;i++) {
        sta[a[i]]=0;
        st.insert(a[i]);
        stall.insert(a[i]);
    }
    for(int i=1;i<=m;i++) {
        if(a[p[i]]==v[i]) continue;
        ct[a[p[i]]] += i - sta[a[p[i]]];
        st.erase(a[p[i]]);
        a[p[i]] = v[i];
        sta[v[i]] = i;
        st.insert(v[i]);
        stall.insert(v[i]);
    }
    for(auto i : st) 
        ct[i] += m - sta[i] + 1;
    ll ans = 0;
    for(auto i : stall)
        ans += 1ll*m*(m+1)/2 - 1ll*(m+1-ct[i])*(m-ct[i])/2;
    cout<<ans<<endl;
}
int main(){
    cin>>t;
    while(t--) solve();
    return 0;
}