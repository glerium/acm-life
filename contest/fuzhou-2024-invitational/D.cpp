#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
void solve()
{
    int n;
    ll k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    set<pair<ll,int>> st;
    for(int i=0;i<n;i++)
    {
        st.emplace(a[i],i+1);
    }
    int ans=1;
    vector<int> ansidx;
    while(!st.empty())
    {
        auto [x,xi]=*st.begin();
        ll y=x+k;
        st.erase(st.begin());
        ansidx.push_back(xi);
        while(st.upper_bound({y,1e9})!=st.end())
        {
            auto itz=st.upper_bound({y,1e9});
            auto [z,zi]=*itz;
            st.erase(itz);
            ansidx.push_back(zi);
            ans++;
            y=z+k;
        }
    }
    cout<<ans<<'\n';
    for(int i=0;i<n;i++)cout<<ansidx[i]<<' ';
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);

    solve();
    return 0;
}