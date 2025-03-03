#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
struct State {
    int x, y;
    int val;
    bool operator<(const State& rhs) const {
        return val > rhs.val;
    };
};
void solve() {
    int n; cin >> n;
    string c[n+5];
    rep(i,1,n) {
        cin >> c[i];
        c[i] = ' ' + c[i];
    }
    int a[n+5][n+5] = {};
    rep(i,1,n) rep(j,1,n) a[i][j] = inf;
    priority_queue<State> q;
    rep(i,1,n) {
        q.push({i,i,0});
    }
    rep(i,1,n) rep(j,1,n) {
        if(i == j) continue;
        if(c[i][j] != '-') {
            q.push({i,j,1});
            a[i][j] = 1;
        }
    }
    while(!q.empty()) {
        auto now = q.top(); q.pop();
        // if(now.val != a[now.x][now.y])
        //     continue;
        rep(i,1,n) rep(j,1,n) {
            if(c[i][now.x] != c[now.y][j] || c[i][now.x] == '-')
                continue;
            if(now.val + 2 < a[i][j]) {
                a[i][j] = min(a[i][j], now.val + 2);
                q.push({i, j, a[i][j]});
            }
        }
    }
    rep(i,1,n) rep(j,1,n)
        if(a[i][j] == inf)
            a[i][j] = -1;
    rep(i,1,n) a[i][i] = 0;
    rep(i,1,n) {
        rep(j,1,n)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
