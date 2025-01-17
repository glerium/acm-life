#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
struct Edge {
    int to;
    int w;
};
struct State {
    int x;
    int dis;
    bool operator<(const State& rhs) const {
        return dis > rhs.dis;
    }
};
void solve() {
    int n,m,q; cin >> n >> m >> q;
    vector<Edge> a[n+5];
    int b[m+5] = {};
    rep(i,1,m) {
        int x,y,w; cin >> x >> y >> w;
        a[x].push_back({y, w});
        a[y].push_back({x, w});
        b[i] = w;
    }
    sort(b+1, b+1+m);
    int dis[n+5] = {};
    bool vis[n+5] = {};

    // begin, end, x
    // 表示从i出发，到达j，中间经过大于b[x]的边数的最小值
    int ans[n+5][n+5][m+5] = {};
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            memset(dis, 0x3f, sizeof(dis));
            memset(vis, 0, sizeof(vis));
            priority_queue<State> q;
            dis[i] = 0;
            q.push({i, 0});
            while(!q.empty()) {
                auto now = q.top(); q.pop();
                if(dis[now.x] != now.dis) continue;
                if(vis[now.x]) continue;
                vis[now.x] = true;
                for(auto [to, w] : a[now.x]) {
                    int dis_e = w > b[j];
                    if(dis[to] > dis[now.x] + dis_e) {
                        dis[to] = dis[now.x] + dis_e;
                        q.push({to, dis[to]});
                    }
                }
            }
            for(int k=1;k<=n;k++) {
                ans[i][k][j] = dis[k];
            }
        }
    }
    
    while(q--) {
        int x,y,k; cin >> x >> y >> k;
        // for(int i=1;i<=m;i++) {
        //     cout << ans[x][y][i] << ' ' ;
        // }
        // cout << endl;
        int anss = b[lower_bound(ans[x][y]+1, ans[x][y]+1+m, k-1, greater<int>()) - ans[x][y]];
        // int l=1, r=1e9, mid, ans;
        // while(l <= r) {
        //     mid = (l + r) >> 1;
        //     if(check(mid, k, a, b)) {
        //         ans = mid;
        //         r = mid - 1;
        //     } else {
        //         l = mid + 1;
        //     }
        // }
        cout << anss << ' ';
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
