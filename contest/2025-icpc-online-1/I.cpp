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
struct State {
    int x;
    pair<int,int> dis;
    State(int x_,pair<int,int> dis_) {x=x_;dis=dis_;}
    bool operator<(const State& rhs) const {
        return dis > rhs.dis;
    }
};
pair<int,int> padd(pair<int,int> pa,int w,int V)
{
    pa.second+=w;
    if(pa.second>V)
    {
        pa.first++;
        pa.second=w;
    }
    return pa;
}
void solve() {
    int n,m,V,T;
    cin>>n>>m>>V>>T;
    vector<vector<pair<int,int>>> ver(n+1);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        ver[u].emplace_back(v,w);
        ver[v].emplace_back(u,w);
    }
    pair<int,int> inf={1000000000,V};
    vector<pair<int,int>> dis(n+1,{1000000000,V});
    vector<int> vis(n+1);
    dis[T]={1,0};
    priority_queue<State> q;
    q.emplace(T,dis[T]);
    while(!q.empty())
    {
        auto [nowx, nowd]=q.top();
        q.pop();
        if(vis[nowx])continue;
        vis[nowx]=true;
        for(auto [v,w]:ver[nowx])
        {
            if(padd(nowd,w,V)<dis[v])
            {
                dis[v]=padd(nowd,w,V);
                q.emplace(v,dis[v]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dis[i]>=inf)cout<<-1<<' ';
        else cout<<dis[i].first<<' ';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    // while(t--) solve();
    solve();
    return 0;
}