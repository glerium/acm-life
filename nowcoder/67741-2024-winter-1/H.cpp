#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn=1e5+10;
int t,n,m,v[maxn],w[maxn];
ll ans;
map<int,int> mp;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        mp.clear();
        cin>>n>>m;
        ans=0;
        rep(i,1,n) cin>>v[i]>>w[i];
        rep(i,1,n) if(w[i]<=m) mp[w[i]]=v[i];
        if(!m) {
            rep(i,1,n) if(!w[i]) ans+=v[i];
            cout<<ans<<endl;
            continue;
        }
        int maxb=log2(m);
        for(int i=maxb;i>=0;i--) {
            if(m&(1<<i)) {
                ll now=0;
                for(auto j:mp) {
                    if(!(j.first&(1<<i)))
                        now+=j.second;
                }
                ans=max(ans,now);
            }else{
                vector<int> tmp;
                for(auto j:mp) {
                    if(j.first&(1<<i))
                        tmp.push_back(j.first);
                }
                for(auto j:tmp) mp.erase(j);
            }
        }
        {
            ll now=0;
            for(auto j:mp) now+=j.second;
            ans=max(ans,now);
        }
        cout<<ans<<endl;
    }
    return 0;
}