#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr (sizeof...(args) == 1) {
        return vector<T>(n, args...);
    } else {
        return vector(n, Vec<T>(args...));
    }
}
const int N = 1e6+10;
int fa[N], mx[N], mi[N];

int find(int x) {
    if(x == fa[x]) return x;
    else return fa[x] = find(fa[x]);  
}

void marge(int x, int y) {
    int fx = find(x); 
    int fy = find(y);
    if(fx != fy) {
        fa[fy] = fx;
        mx[fx] = max(mx[fx], mx[fy]);
        mi[fx] = min(mi[fx], mi[fy]);
    }
}
void solve() {
    using ll = long long;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)fa[i]=i;
    vector<ll> w(n+1);
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=n;i++)mx[i]=mi[i]=w[i];
    vector<vector<int>> ver(n+1);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        ver[u].push_back(v);
        ver[v].push_back(u);
    }
    vector<int> vis_vec(n+1);
    vector<pair<ll,int>> v(n+1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    set<pair<int,int>> vis;
    for(int i=1;i<=n;i++)pq.emplace(w[i],i);
    while(!pq.empty())
    {
        auto [wi,pi]=pq.top();
        pq.pop();
        // cerr<<":1 "<<wi<<' '<<pi<<'\n';
        int now=pi;
        bool ok=true;
        int maxi=0,maxw=mx[find(pi)];
        ok=false;
        for(auto it:ver[now])
        {
            if(mi[find(it)]>maxw)
            {
                maxi=it;
                maxw=mi[find(it)];
            }
        }
        if(maxi)
        {
            // cerr<<":2 "<<pi<<' '<<maxi<<'\n';
            int pre;
            marge(pi,maxi);
        } 
    }
    ll ans=0;
    for(int i=1;i<=n;i++)if(fa[i]==i)ans+=mx[i]-mi[i];
    cout<<ans<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    // while(t--) solve();
    solve();
    return 0;
}