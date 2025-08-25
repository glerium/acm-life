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
const vector<vector<int>> a = {
    {0,0,0,0,0,0},
    {0,1,1,1,1,1},
    {0,0,1,1,1,1},
    {0,0,0,2,1,1},
    {0,0,0,0,0,1},
    {0,0,0,0,0,0}
};
constexpr int to[8][2] = {
    {1,2},{1,-2},{-1,2},{-1,-2},
    {2,1},{2,-1},{-2,1},{-2,-1}
};
int predict(const vector<vector<int>> &b) {
    int ans = 0;
    rep(i,1,5) rep(j,1,5) ans += a[i][j] != b[i][j];
    return max(0, ans);
}
void solve() {
    auto mp = Vec<int>(6, 6, 0);
    rep(i,1,5) rep(j,1,5) {
        char ch; cin >> ch;
        if(ch == '0') mp[i][j] = 0;
        else if(ch == '1') mp[i][j] = 1;
        else mp[i][j] = 2;
    }
    map<ll, int> st;
    int maxdep = -1;
    function<bool(int,int,int)> dfs = [&](int nowdep, int x, int y) -> bool {
        ll hash = 0;
        rep(i,1,5) rep(j,1,5) hash = hash * 3 + mp[i][j];
        if(st.count(hash) && st[hash] < nowdep) return false;
        st[hash] = nowdep;
        int diff = predict(mp);
        if(nowdep + diff > maxdep) return false;
        if(diff == 0) return true;
        rep(i,0,7) {
            int tx = x + to[i][0], ty = y + to[i][1];
            if(tx < 1 || ty < 1 || tx > 5 || ty > 5) continue;
            swap(mp[x][y], mp[tx][ty]);
            if(dfs(nowdep + 1, tx, ty)) return true;
            swap(mp[x][y], mp[tx][ty]);
        }
        return false;
    };
    int x, y;
    rep(i,1,5) rep(j,1,5) {
        if(mp[i][j] == 2) {
            x = i;
            y = j;
        }
    }
    rep(i,0,15) {
        maxdep = i;
        st.clear();
        if(dfs(0, x, y)) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}