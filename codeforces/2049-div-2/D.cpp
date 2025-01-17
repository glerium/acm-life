#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;

template<class T, class... Args> auto Vec(size_t n, Args&&... args) {
    if constexpr (sizeof...(args) == 1) {
        return vector<T>(n, args...);
    } else {
        return vector(n, Vec<T>(args...));
    }
}

void solve() {
    int n,m,cost; cin >> n >> m >> cost;
    auto a = Vec<ll>(n+5, m+5, 0);
    rep(i,1,n) rep(j,1,m) cin >> a[i][j];
    auto dp = Vec<ll>(n+5, m+5, m+5, LLONG_MAX / 2);
    auto f = Vec<ll>(n+5, m+5, LLONG_MAX / 2);
    
    f[0][1] = 0;
    rep(i,1,n) {
        rep(j,1,m) {                // from where
            rep(k,0,m-1) {
                int realj = j + k;  // to which number
                if(realj > m) realj -= m;
                dp[i][j][k] = min(dp[i][j][k], f[i-1][j] + a[i][realj] + 1ll * k * cost);
                dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][k] + a[i][realj]);
            }
            rep(k,0,m-1)
                f[i][j] = min(f[i][j], dp[i][j][k]);
        }
    }
    // rep(i,1,n) {
    //     rep(j,1,m)
    //         cout << f[i][j] << ' ';
    //     cout << endl;
    // }
    cout << f[n][m] << endl;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
