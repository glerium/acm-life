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
    int n,m,q; cin >> n >> m >> q;
    auto a = Vec<int>(n+5, m+5, 0);
    rep(i,1,n) rep(j,1,m) cin >> a[i][j];
    while(q--) {
        int x,y; cin >> x >> y;
        set<pair<int,int>> st;
        int step = 0;
        while(true) {
            st.insert({x,y});
            if(a[x][y] == 1) x--;
            else if(a[x][y] == 2) x++;
            else if(a[x][y] == 3) y--;
            else y++;
            step++;
            if(st.count({x,y})) {
                cout << -1 << endl;
                break;
            }
            if(x == 0 || y == 0 || x == n+1 || y == m+1) {
                cout << step << endl;
                break;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}