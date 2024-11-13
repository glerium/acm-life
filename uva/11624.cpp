#include <bits/stdc++.h>
using namespace std;
constexpr int to[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
struct State {
    int x, y;
    int dis;
};
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> a;
    vector<vector<int>> lt;
    vector<vector<bool>> vis;
    a.resize(n+5);
    lt.resize(n+5);
    vis.resize(n+5);
    for(int i=1;i<=n;i++) {
        a[i].resize(m+5);
        lt[i].resize(m+5);
        vis[i].resize(m+5);
    }
    int x0,y0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> a[i][j];
            if(a[i][j] == 'J')
                x0 = i, y0 = j;
        }
    }
    queue<State> q;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            lt[i][j] = 0x3f3f3f3f;
            if(a[i][j] == 'F') {
                lt[i][j] = 0;
                q.push({i,j,0});
                vis[i][j] = true;
            }
        }
    }
    while(!q.empty()) {
        auto now = q.front(); q.pop();
        for(int i=0;i<4;i++) {
            int tx = now.x + to[i][0],
                ty = now.y + to[i][1];
            if(tx < 1 || ty < 1 || tx > n || ty > m)
                continue;
            if(vis[tx][ty])
                continue;
            vis[tx][ty] = true;
            if(a[tx][ty] == '#')
                continue;
            q.push({tx, ty, now.dis+1});
            lt[tx][ty] = now.dis + 1;
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++)
            vis[i][j] = false;
    }
    q.push({x0, y0, 0});
    vis[x0][y0] = true;
    while(!q.empty()) {
        auto now = q.front(); q.pop();
        if(now.x == 1 || now.y == 1 || now.x == n || now.y == m) {
            cout << now.dis+1 << endl;
            return;
        }
        for(int i=0;i<4;i++) {
            int tx = now.x + to[i][0],
                ty = now.y + to[i][1];
            if(tx < 1 || ty < 1 || tx > n || ty > m)
                continue;
            if(a[tx][ty] == '#')
                continue;
            if(vis[tx][ty]) continue;
            vis[tx][ty] = true;
            if(now.dis + 1 >= lt[tx][ty])
                continue;
            q.push({tx, ty, now.dis+1});
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
