#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
struct State {
    int x;
    int dis;
    State() = default;
    State(int x, int dis) : x(x), dis(dis) {}
    bool operator<(const State& rhs) const {
        return dis > rhs.dis;
    }
};
void solve() {
    int m,start,dest,e;
    cin >> m >> start >> dest >> e;
    vector<vector<pair<int,int>>> a(505);
    rep(i,1,m) {
        int c,n; cin >> c >> n;
        vector<int> g(n+5);
        rep(j,1,n) cin >> g[j];
        rep(j,1,n) rep(k,j+1,n) {
            a[g[j]].emplace_back(g[k], c);
            a[g[k]].emplace_back(g[j], c);
        }
    }
    vector<int> dis(505, inf);
    vector<bool> vis(505, false);
    dis[start] = 0;
    priority_queue<State> q;
    q.emplace(start, 0);
    while(!q.empty()) {
        auto [nx, ndis] = q.top();
        q.pop();
        if(vis[nx]) continue;
        vis[nx] = true;
        for(auto [v, d] : a[nx]) {
            if(dis[v] > dis[nx] + d) {
                dis[v] = dis[nx] + d;
                q.emplace(v, dis[v]);
            }
        }
    }
    if(dis[dest] == inf) {
        cout << -1 << endl;
    } else {
        cout << dis[dest] << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}