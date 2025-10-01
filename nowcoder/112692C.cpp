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
constexpr int to[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
void solve() {
    int n,m,k; cin >> n >> m >> k;
    auto r = Vec<bool>(n+5, m+5, 0);
    rep(i,1,k) {
        int x,y,d; cin >> x >> y >> d;
        rep(a,max(1,x-d),min(n,x+d)) {
            rep(b,max(1,y-d),min(m,y+d)) {
                r[a][b] = true;
            }
        }
    }
    queue<pair<int,int>> q;
    auto dis = Vec<int>(n+5, m+5, inf);
    auto v = Vec<bool>(n+5, m+5, 0);
    rep(i,1,n) rep(j,1,m) {
        if(r[i][j]) {
            q.push({i, j});
            dis[i][j] = 0;
        }
    }
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if(v[x][y]) continue;
        v[x][y] = true;
        rep(i,0,3) {
            int tx = x + to[i][0],
                ty = y + to[i][1];
            if(tx < 1 || ty < 1 || tx > n || ty > m) continue;
            q.emplace(tx, ty);
            dis[tx][ty] = min(dis[tx][ty], dis[x][y] + 1);
        }
    }
    int ans = -1;
    rep(i,1,n) rep(j,1,m) {
        ans = max(ans, dis[i][j]);
    }
    cout << ans - 1 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}