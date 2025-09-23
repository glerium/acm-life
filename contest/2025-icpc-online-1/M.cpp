#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
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
    ll dis;
    bool operator<(const State& rhs) const {
        return dis > rhs.dis;
    }
};
bitset<5007> vis;
vector<vector<pair<int,int>>> a(5007);
vector<pair<int,int>> edg(10004);
priority_queue<State> q;
constexpr ll inf = LLONG_MAX / 2 - 10;

void solve() {
    int n,m;
    cin>>n>>m;
    
    rep(i,1,n-1) {
        int u,v,w; cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    
    rep(i,1,m) {
        int p,q; cin >> p >> q;
        edg[i] = {p, q};
    }
    auto f = Vec<ll>(n+5, n+5, inf);
    f[1][0] = 0;
    function<void(int,int)> dfs = [&](int x, int fa) -> void {
        for(auto [v, d] : a[x]) {
            if(v == fa) continue;
            f[v][0] = f[x][0] + d;
            dfs(v, x);
        }
    };
    dfs(1, 0);
    rep(k,1,n) {
        ll mind = inf;
        int mini;

        rep(i,1,m) {
            auto [p, q] = edg[i];
            f[p][k] = min(f[q][k-1], f[p][k]);
            f[q][k] = min(f[p][k-1], f[q][k]);
        }
        vector<int> vec;
        rep(i,1,n) {
            if(f[i][k] < f[i][k-1])
                vec.push_back(i);
        }
        
        vis.reset();
        while(!q.empty()) q.pop();
        
        for(auto i : vec)
            q.push({i, f[i][k]});
        while(!q.empty()) {
            auto [nowx, nowd] = q.top();
            q.pop();
            if(vis[nowx]) continue;
            vis[nowx] = true;
            for(auto [v, d] : a[nowx]) {
                if(nowd + d < f[v][k]) {
                    f[v][k] = nowd + d;
                    q.push({v, f[v][k]});
                }
            }
        }
    }

    // cout << dis[get(1, 3)] << endl;
    auto ans = Vec<ll>(n+5, inf);
    rep(k,0,n) {
        rep(i,1,n)
            ans[i] = min(ans[i], f[i][k]);
        ll s = 0;
        rep(i,1,n) s += ans[i];
        cout << s << endl;
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