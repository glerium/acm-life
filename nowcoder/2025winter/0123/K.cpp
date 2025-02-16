#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr int to[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
template<class T, class... Args> auto Vec(size_t n, Args&&... args) {
    if constexpr(sizeof... (args) == 1) {
        return vector<T>(n, args...);
    }else{
        return vector(n, Vec<T>(args...));
    }
}
void solve() {
    int n,m; cin >> n >> m;
    string s[n+5];
    rep(i,1,n) {cin >> s[i]; s[i] = ' ' + s[i];}
    auto vis = Vec<bool>(n+5, m+5, 0);
    int ans = 0x3f3f3f3f;
    set<pair<int,int>> st;
    function<void(int, int)> dfs = [&](int x, int y) {
        if(vis[x][y]) return;
        vis[x][y] = true;
        rep(i,0,3) {
            int tx = x + to[i][0], ty = y + to[i][1];
            if(tx < 1 || tx > n || ty < 1 || ty > m)
                continue;
            if(s[tx][ty] == '1')
                dfs(tx, ty);
            else
                st.insert({tx, ty});
        }
    };
    rep(i,1,n) rep(j,1,m) {
        if(!vis[i][j] && s[i][j] == '1') {
            st.clear();
            dfs(i, j);
            ans = min(ans, int(st.size()));
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
