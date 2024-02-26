#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(ll x,ll y) {
    return !y?x:gcd(y,x%y);
}
multiset<ll> st;
vector<array<ll,3>> ans;
int gg;
void fnd(ll x) {
    if(x==1) {
        st.insert(x);
        return;
    }
    if(x%2==0) {
        while(st.count(x/2)<2) fnd(x/2);
        ans.push_back({2,1ll*x/2*gg,1ll*x/2*gg});
    }else{
        int ct1=st.count(x/2), ct2=st.count(x-x/2);
        while(st.count(x/2)<2) fnd(x/2);
        while(st.count(x-x/2)<2) fnd(x-x/2);
        ans.push_back({2,1ll*x/2*gg,1ll*(x-x/2)*gg});
    }
    st.insert(x);
}
void solve() {
    ans.clear();
    int x,y; cin>>x>>y;
    ans.push_back({1,x,y});
    ans.push_back({1,x,y});
    gg=gcd(x,y);
    int ct=1ll*x*y/gg;
    st.clear();
    st.insert(1);
    st.insert(1);
    fnd(ct);
    cout<<ans.size()<<endl;
    for(auto [x,y,z]:ans) cout<<x<<' '<<y<<' '<<z<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}