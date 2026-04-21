#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
struct State {
    int x,y;
    array<int,3> p{4, 4, 4};
    int d;
    bool operator<(const State& rhs) const {
        return d > rhs.d;
    }
};
constexpr int inf = 0x3f3f3f3f;
constexpr int to[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin >> n >> m;
    vector<string> a(n+5);
    rep(i,1,n) {
        cin >> a[i];
        a[i] = ' ' + a[i];
    }

    auto enc = [&](int x, int y, const array<int,3>& p) -> int {
        return 125 * ((x - 1) * m + (y - 1)) + p[0] * 25 + p[1] * 5 + p[2];
    };

    priority_queue<State> q;
    int sx, sy, dx, dy;
    rep(i,1,n) rep(j,1,m) {
        if(a[i][j] == 'S')
            sx = i, sy = j;
        else if(a[i][j] == 'T')
            dx = i, dy = j;
    }
    
    vector<int> dis(n * m * 130, inf);
    q.push({sx, sy, {4, 4, 4}, 0});
    dis[enc(sx, sy, {4, 4, 4})] = 0;
    while(!q.empty()) {
        auto [nx, ny, np, nd] = q.top();
        q.pop();
        if(nx == dx && ny == dy) {
            cout << nd << endl;
            return 0;
        }
        rep(i,0,3) {
            int tx = nx + to[i][0],
                ty = ny + to[i][1];
            if(tx < 1 || ty < 1 || tx > n || ty > m)
                continue;
            if(a[tx][ty] =='#') continue;
            if(np[0] == np[1] && np[1] == np[2] && np[2] == i) continue;
            array<int,3> tp = {i, np[0], np[1]};
            if(dis[enc(tx, ty, tp)] > nd + 1) {
                dis[enc(tx, ty, tp)] = nd + 1;
                q.push({tx, ty, tp, nd + 1});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}