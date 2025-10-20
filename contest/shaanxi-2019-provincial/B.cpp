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
void solve() {
    int n,m; cin >> n >> m;
    vector<string> s(n+5);
    rep(i,1,n) {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }
    auto a = Vec<int>(n+5, m+5, 0);
    rep(i,1,n) rep(j,1,m) cin >> a[i][j];
    auto in = Vec<int>(n+5, m+5, 0);
    auto to = Vec<pair<int,int>>(n+5, m+5, make_pair(-1, -1));
    rep(x,1,n) rep(y,1,m) {
        int tx = x, ty = y;
        if(s[x][y] == 'r') ty += a[x][y];
        else if(s[x][y] == 'l') ty -= a[x][y];
        else if(s[x][y] == 'd') tx += a[x][y];
        else tx -= a[x][y];
        if(tx < 1 || ty < 1 || tx > n || ty > m) continue;
        in[tx][ty] ++;
        to[x][y] = {tx, ty};
    }
    int x = 1, y = 1;
    rep(i,1,n) rep(j,1,m) {
        if(in[i][j] == 0) {
            x = i;
            y = j;
        }
    }
    // cout << x << ' ' << y << endl;
    auto vis = Vec<bool>(n+5, m+5, 0);
    int ct = 0;
    while(ct < n * m) {
        // cout << x << ' ' << y << ' ' << to[x][y].first << ' ' << to[x][y].second << endl;
        if(vis[x][y]) {
            break;
        }
        vis[x][y] = true;
        ct ++;
        if(to[x][y].first == -1) {
            break;
        }
        tie(x, y) = to[x][y];
    }
    // cout << ct << endl;
    if(ct == n * m) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}