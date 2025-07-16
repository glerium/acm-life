#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
void solve()
{
    int n;
    cin>>n;
    n*=2;
    vector<int> a(n+1);
    vector<ll> pre(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int> b=a;
    for(int i=2;i<=n;i+=2)a[i]=-a[i];
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    ll ans=abs(pre[n]);
    ll pren=pre[n];
    map<ll,int> mp[2];
    for(int i=1;i<=n;i++)
    {
        auto it2=mp[i%2].lower_bound((2*pre[i]-pre[n])/2);
        auto it3=mp[i%2].lower_bound((2*pre[i]-pre[n]+1)/2);
        auto it1=mp[i%2].end();
        if(it2!=mp[i%2].begin())
        {
            it1=it2;
            it1--;
        }
        if(it1!=mp[i%2].end())
        {
            ll preit1=it1->first;
            ll now=abs(2*(preit1-pre[i])+pren);
            ans=min(ans,now);
        }
        if(it2!=mp[i%2].end())
        {
            ll preit2=it2->first;
            ll now=abs(2*(preit2-pre[i])+pren);
            ans=min(ans,now);
        }
        if(it3!=mp[i%2].end())
        {
            ll preit3=it3->first;
            ll now=abs(2*(preit3-pre[i])+pren);
            ans=min(ans,now);
        }
        mp[i%2][pre[i]]=i;
    }
    ll sum=accumulate(b.begin(),b.end(),0LL);
    cout<<(sum-ans)/2<<'\n';
    // cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t;cin>>t;while(t--)solve();
    return 0;
}