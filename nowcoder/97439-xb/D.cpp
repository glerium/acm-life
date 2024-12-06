#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
struct State {
    int x;
    bool used;
    int dis;
};
void solve() {
    int n,k,a,b,x,y; cin >> n >> k >> a >> b >> x >> y;
    x %= n; y %= n;
    queue<State> q;
    bool vis[n+5][2] = {};
    q.push({a, false, 0});
    vis[a][0] = true;
    while(!q.empty()) {
        auto now = q.front(); q.pop();
        if(now.x == b) {
            cout << now.dis << endl;
            return;
        }
        int nxt = now.x + x;
        if(nxt > n) nxt -= n;
        if(!vis[nxt][now.used]) {
            vis[nxt][now.used] = true;
            q.push({nxt, now.used, now.dis + 1});
        }
        nxt = now.x - y;
        if(nxt < 1) nxt += n;
        if(!vis[nxt][now.used]) {
            vis[nxt][now.used] = true;
            q.push({nxt, now.used, now.dis + 1});
        }
        if(!now.used && k) {
            nxt = now.x + n / 2;
            if(nxt > n) nxt -= n;
            if(!vis[nxt][now.used]) {
                vis[nxt][now.used] = true;
                q.push({nxt, now.used, now.dis + 1});
            }
        }
    }
    cout << -1 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
