#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
struct Edge {
    int to, w;
};
struct State {
    int x;
    ll dis;
    bool operator<(const State& rhs) const {
        return dis > rhs.dis;
    }
};
void solve() {
    int n,m; cin >> n >> m;
    vector<vector<Edge>> a(n+5);
    rep(i,1,m) {
        int x,y,z; cin >> x >> y >> z;
        a[x].push_back({y, z});
        a[y].push_back({x, z});
    }
    int k,t; cin >> k >> t;
    // airport -> n+1: 0;
    // n+1 -> airport: t;
    rep(i,1,k) {
        int x; cin >> x;
        a[n+1].push_back({x, 0});
        a[x].push_back({n+1, t});
    }
    auto dis = Vec<ll>(n+5, n+5, inf);
    rep(i,1,n+1) dis[i][i] = 0;
    auto dijkstra = [&](int x, vector<ll> &dis) {
        fill(dis.begin(), dis.end(), inf);
        dis[x] = 0;
        priority_queue<State> q;
        vector<bool> vis(dis.size());
        q.push({x, 0});
        while(!q.empty()) {
            auto now = q.top(); q.pop();
            if(now.dis != dis[now.x]) continue;
            if(vis[now.x]) continue;
            vis[now.x] = true;
            for(auto [v, w] : a[now.x]) {
                if(dis[v] > dis[now.x] + w) {
                    dis[v] = dis[now.x] + w;
                    q.push({v, dis[v]});
                }
            }
        }
    };
    rep(i,1,n+1) {
        // get initial dis
        dijkstra(i, dis[i]);
    }
    int q; cin >> q;
    rep(_,1,q) {
        int type; cin >> type;
        if(type == 1) {
            int x,y,t; cin >> x >> y >> t;
            rep(i,1,n+1) rep(j,1,n+1) {
                dis[i][j] = min(dis[i][j], dis[i][x] + t + dis[y][j]);
                dis[i][j] = min(dis[i][j], dis[i][y] + t + dis[x][j]);
            }
        } else if(type == 2) {
            int x; cin >> x;
            // add n+1 <-> x (dis=t)
            rep(i,1,n+1) rep(j,1,n+1) {
                dis[i][j] = min(dis[i][j], dis[i][x] + t + dis[n+1][j]);
                dis[i][j] = min(dis[i][j], dis[i][n+1] + 0 + dis[x][j]);
            }
        } else {
            ll ans = 0;
            rep(i,1,n) rep(j,1,n) {
                // cout << i << ' ' << j << ' ' << dis[i][j] << endl;
                if(dis[i][j] == inf) continue;
                ans += dis[i][j];
            }
            cout << ans << endl;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}