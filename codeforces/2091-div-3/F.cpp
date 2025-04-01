#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr ll mod = 998244353;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr (sizeof...(args) == 1) {
        return vector<T>(n, args...);
    } else {
        return vector(n, Vec<T>(args...));
    }
}
void solve() {
    // f[i][j][k(0/1)]: count of routes at row i, col j, as the k-th move at this row
    int n,m,d; cin >> n >> m >> d;
    vector<string> a(n+5);
    rep(i,1,n) {
        cin >> a[i];
        a[i] = ' ' + a[i];
    }
    auto f = Vec<ll>(n+5, m+5, 2, 0);
    rep(i,1,m) {
        if(a[n][i] == 'X') f[n][i][0] = 1;
        else f[n][i][0] = 0;
    }
    for(int i=n;i>=1;i--) {         // at row n
        if(i != n) {
            vector<ll> slast(m+5);
            for(int j=1;j<=m;j++) {
                slast[j] = slast[j - 1] + f[i+1][j][0] + f[i+1][j][1];
                slast[j] %= mod;
            }
            // at first try
            for(int j=1;j<=m;j++) {     // dest: col 
                if(a[i][j] == '#') continue;
                double ld = j - sqrt(d * d - 1 * 1), rd = j + sqrt(d * d - 1 * 1);
                int l = max(1, int(ceil(ld))), r = min(m, int(floor(rd)));
                f[i][j][0] = ((slast[r] - slast[l - 1]) % mod + mod) % mod;
            }
        }
        // at second try
        vector<int> snow(m+5);
        for(int j=1;j<=m;j++) {
            snow[j] = snow[j - 1] + f[i][j][0];
            snow[j] %= mod;
        }
        for(int j=1;j<=m;j++) {
            if(a[i][j] == '#') continue;
            int l = max(1, j - d), r = min(m, j + d);
            f[i][j][1] = ((snow[r] - snow[l - 1] - f[i][j][0]) % mod + mod) % mod;
        }
    }
    ll ans = 0;
    rep(j,1,m) {
        ans += f[1][j][0] + f[1][j][1];
        ans %= mod;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
