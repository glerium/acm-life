#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr ll mod = 998244353;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr (sizeof...(args) == 1) {
        return vector<T>(n, args...);
    } else {
        return vector(n, Vec<T>(args...));
    }
}
void solve() {
    int n; cin >> n;
    auto h = Vec<int>(n+5, n+5, 0);
    vector<ll> a(n+5), b(n+5);
    rep(i,1,n) rep(j,1,n) cin >> h[i][j];
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    auto f1 = Vec<ll>(n+5, 2, INF);     // 前i行合法，是否对第i行操作
    auto check1 = [&](int x, int y, bool b1, bool b2) -> bool {
        rep(i,1,n) {
            if(h[x][i] + b1 == h[y][i] + b2)
                return false;
        }
        return true;
    };
    f1[1][0] = 0;
    f1[1][1] = a[1];
    rep(i,2,n) {
        rep(x,0,1) rep(y,0,1) {
            if(check1(i-1, i, x, y)) {
                f1[i][y] = min(f1[i][y], f1[i-1][x] + (y ? a[i] : 0));
            }
        }
    }
    
    auto f2 = Vec<ll>(n+5, 2, INF);     // 前i列合法，是否对第i列操作
    auto check2 = [&](int x, int y, bool b1, bool b2) -> bool {
        rep(i,1,n) {
            if(h[i][x] + b1 == h[i][y] + b2)
                return false;
        }
        return true;
    };
    f2[1][0] = 0;
    f2[1][1] = b[1];
    rep(i,2,n) {
        rep(x,0,1) rep(y,0,1) {
            if(check2(i-1, i, x, y)) {
                f2[i][y] = min(f2[i][y], f2[i-1][x] + (y ? b[i] : 0));
            }
        }
    }

    if(min(f1[n][0], f1[n][1]) == INF)
        cout << -1 << endl;
    else if(min(f2[n][0], f2[n][1]) == INF)
        cout << -1 << endl;
    else cout << (min(f1[n][0], f1[n][1]) + min(f2[n][0], f2[n][1])) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
