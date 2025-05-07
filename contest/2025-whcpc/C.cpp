#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
int n,m,T;
vector<vector<pair<int, double>>> a;
struct State {
    int x;
    double dis;
    bool operator<(const State& rhs) const {
        return dis > rhs.dis;
    }
};
vector<double> dis;
vector<bool> vis;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> T;
    a.resize(n + 5);
    dis.resize(n + 5);
    vis.resize(n + 5);
    fill(dis.begin(), dis.end(), 1e20);
    dis[1] = 0;
    rep(i,1,m) {
        int u,v,s,k; cin >> u >> v >> s >> k;
        a[u].emplace_back(v, sqrt(1.0 * s * k));
        a[v].emplace_back(u, sqrt(1.0 * s * k));
    }
    priority_queue<State> q;
    q.push({1, 0});
    while(!q.empty()) {
        auto cur = q.top(); q.pop();
        if(cur.x == n) break;
        // cout << cur.x << ' ' << cur.dis << endl;
        if(vis[cur.x]) continue;
        if(abs(dis[cur.x] - cur.dis) > 1e-9)
            continue;
        vis[cur.x] = true;
        for(auto &[v, d] : a[cur.x]) {
            if(vis[v]) continue;
            if(dis[v] > dis[cur.x] + d) {
                dis[v] = dis[cur.x] + d;
                q.push({v, dis[v]});
            }
        }
    }
    cout << fixed << setprecision(10) << dis[n] * dis[n] / T << endl;
    return 0;
}
