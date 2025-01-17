#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr int INF = 0x3f3f3f3f;
struct State {
    int x, y;
    bool hdir;  // 0:v, 1:h
    int step;
    bool operator<(const State& rhs) const{
        return step > rhs.step;
    }
};
void solve() {
    int n,m; cin >> n >> m;
    string b[n+5] = {};
    rep(i,1,n) cin >> b[i];
    rep(i,1,n) b[i] = ' ' + b[i];
    int sx, sy, gx, gy;
    rep(i,1,n) rep(j,1,m) {
        if(b[i][j] == 'S') sx = i, sy = j;
        else if(b[i][j] == 'G') gx = i, gy = j;
    }
    int step[n+5][m+5][2] = {};
    memset(step, 0x3f, sizeof(step));

    priority_queue<State> q;
    q.push({sx, sy, false, 0});
    q.push({sx, sy, true, 0});
    step[sx][sy][0] = step[sx][sy][1] = 0;

    constexpr int to[2][2][2] = {
        {{1, 0}, {-1, 0}},
        {{0, 1}, {0, -1}}
    };

    while(!q.empty()) {
        auto now = q.top(); q.pop();
        if(now.step != step[now.x][now.y][now.hdir])
            continue;
        for(int i=0;i<=1;i++) {
            int tx = now.x + to[now.hdir][i][0],
                ty = now.y + to[now.hdir][i][1];
            if(tx < 1 || tx > n || ty < 1 || ty > m)
                continue;
            if(b[tx][ty] == '#') continue;
            if(step[tx][ty][!now.hdir] > now.step + 1) {
                step[tx][ty][!now.hdir] = now.step + 1;
                q.push({tx, ty, !now.hdir, step[tx][ty][!now.hdir]});
            }
        }
    }
    int ans = min(step[gx][gy][0], step[gx][gy][1]);
    if(ans != INF) cout << ans << endl;
    else cout << -1 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
