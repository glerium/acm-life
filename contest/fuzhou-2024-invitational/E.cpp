#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
void solve()
{
    int n;cin>>n;
    vector<ll> h(n+1);
    vector<vector<int>> ver(n+1);
    for(int i=1;i<=n;i++)cin>>h[i];
    ll ans=0;
    vector<ll> e(n+1);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        ver[u].push_back(v);
        ver[v].push_back(u);
    }
    auto dfs1=[&](auto &&self,int i,int fa)->void
    {
        // cerr<<"dfs1 "<<i<<"\n";
        for(auto it:ver[i])
        {
            if(it!=fa)
            {
                self(self,it,i);
                e[i]=max(e[i],e[it]);
            }
        }
        if(h[i]>e[i])
        {
            ans+=h[i]-e[i];
            e[i]=h[i];
        }
    };
    int maxh=*max_element(h.begin()+1,h.end());
    for(int i=1;i<=n;i++)
    {
        if(h[i]==maxh&&ver[i].size()==1)
        {
            dfs1(dfs1,ver[i][0],i);
            if(e[ver[i][0]]<maxh)
            {
                ans+=maxh-e[ver[i][0]];
                e[ver[i][0]]=maxh;
            }
            if(e[i]<maxh)
            {
                ans+=maxh-e[i];
                e[i]=maxh;
            }
            cout<<ans<<'\n';
            return;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(h[i]==maxh)
        {
            for(auto it:ver[i])
                dfs1(dfs1,it,i);    
            vector<ll> es;
            for(auto it:ver[i])
            {
                es.push_back(e[it]);
            }
            sort(es.begin(),es.end(),greater<>());
            for(int j=0;j<2;j++)
            {
                if(es[j]<maxh)
                {
                    ans+=maxh-es[j];
                    es[j]=maxh;
                }
            }
            cout<<ans<<'\n';
            return;
        }
    }    
    // for(int i=1;i<=n;i++)cout<<e[i]<<" \n"[i==n];    
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);

    solve();
    return 0;
}