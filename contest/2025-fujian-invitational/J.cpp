#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t;cin>>t;while(t--)
    {
        ll n;cin >> n;
        vector<ll> ans;
        for(int i=0;i<50;i++)
        {
            if((n>>i)&1)
            {
                ans.push_back(1LL<<i);
                n+=1LL<<i;
            }
        }
        // cout<<__lg(n)<<'\n';
        // cout<<((1LL<<50)>1e12)<<'\n';
        cout<<ans.size()<<'\n';
        for(auto it:ans)cout<<it<<' ';
        cout<<'\n';
    }

    return 0;
}