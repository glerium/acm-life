#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n,m,q;
    cin>>n>>m>>q;
    int open=0;
    vector<set<int>> tryed(m+5);
    vector<int> lscore(n+5);
    vector<ll> pscore(m+5);
    for(int i=1;i<=n;i++)lscore[i]=m;
    while(q--)
    {
        int op;cin>>op;
        if(op==1)
        {
            int x;cin>>x;
            open=x;
        }
        else if(op==2)
        {
            int id,x;
            cin>>id>>x;
            if(open!=x)continue;
            if(tryed[id].find(x)!=tryed[id].end())continue;
            tryed[id].insert(x);
            pscore[id]+=lscore[x];
            lscore[x]--;
        }
        else if(op==3)
        {
            int id,x;
            cin>>id>>x;
            if(open!=x)continue;
            if(tryed[id].find(x)!=tryed[id].end())continue;
            tryed[id].insert(x);
        }
    }
    vector<pair<ll,ll>> p(m);
    for(int i=1;i<=m;i++)p[i-1]={i,pscore[i]};
    sort(p.begin(),p.end(),[](pair<ll,ll> &a,pair<ll,ll> &b){return a.second!=b.second?a.second>b.second:a.first<b.first;});
    for(auto it:p)cout<<it.first<<' '<<it.second<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t;cin>>t;while(t--)solve();
    return 0;
}