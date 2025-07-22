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
struct State {
    int x,y;
};
struct Edge {
    int x, y;
    ll d;
    bool operator<(const Edge& rhs) const{
        return d < rhs.d;
    }
};
constexpr int to[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
void solve() {
    int n,m; cin >> n >> m;
    auto a = Vec<ll>(n+5, m+5, 0);
    rep(i,1,n) rep(j,1,m) cin >> a[i][j];
    ll ans = 0;
    set<int> st;
    constexpr ll costBuild = 1ll << 34;
    rep(i,1,n) rep(j,1,m) {
        st.insert(a[i][j]);
    }
    vector<pair<int,int>> valPoint(10007);
    rep(i,1,n) rep(j,1,m) valPoint[a[i][j]] = {i, j};
    auto doErase = [&](int x, int y) {
        queue<State> que;
        st.erase(a[x][y]);
        que.push({x,y});
        while(!que.empty()) {
            auto now = que.front();
            que.pop();
            int nx = now.x, ny = now.y;
            rep(i,0,3) {
                int tx = nx + to[i][0],
                    ty = ny + to[i][1];
                if(tx < 1 || tx > n || ty < 0 || ty > m)
                    continue;
                if(!st.count(a[tx][ty]))
                    continue;
                if(a[tx][ty] > a[nx][ny])
                    continue;
                st.erase(a[tx][ty]);
                que.push({tx, ty});
            }
        }
    };
    vector<pair<int,int>> pts;
    pts.push_back({1, 1});
    doErase(1, 1);
    while(!st.empty()) {
        int maxVal = *prev(st.end());
        auto [nx, ny] = valPoint[maxVal];
        pts.push_back({nx, ny});
        doErase(nx, ny);
    }
    ans += (pts.size() - 1) * costBuild;

    // generated tree
    int pc = pts.size();
    vector<ll> dis(pc+5, inf);
    dis[0] = 0;
    vector<bool> vis2(pc+5);
    int ct = pc;
    ll mxans = 0;
    while(ct) {
        ll cur = -1, curv = inf;
        rep(i,0,pc-1) {
            if(vis2[i]) continue;
            if(curv > dis[i]) {
                cur = i;
                curv = dis[i];
            }
        }
        mxans += curv;
        vis2[cur] = true;
        ct--;
        rep(rr,0,pc-1) {
            if(rr == cur) continue;
            auto &i = pts[cur], &j = pts[rr];
            ll d = 114 * abs(i.first - j.first) + 5141 * abs(i.second - j.second) + 919810 * abs(a[i.first][i.second] - a[j.first][j.second]);
            dis[rr] = min(dis[rr], d);
        }
    }

    cout << ans + mxans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}