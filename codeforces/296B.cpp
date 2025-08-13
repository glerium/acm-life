#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 1e9+7;
constexpr ll inf = 0x3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
void solve() {
    int n; cin >> n;
    string s,t; cin >> s >> t;
    s = ' ' + s; t = ' ' + t;
    auto f = Vec<ll>(n+5, 3, 0ll);
    f[0][0] = f[0][1] = f[0][2] = 1;
    rep(i,1,n) {
        int ct[3] = {};
        rep(a,0,9) {
            if(s[i] != '?' && s[i] != '0' + a) continue;
            rep(b,0,9) {
                if(t[i] != '?' && t[i] != '0' + b) continue;
                if(a >= b) ct[0]++;
                if(a <= b) ct[1]++;
                if(a == b) ct[2]++;
            }
        }
        rep(j,0,2) {
            f[i][j] = f[i-1][j] * ct[j] % mod;
        }
    }
    ll ans = 1;
    rep(i,1,n) {
        if(s[i] == '?') ans = ans * 10 % mod;
        if(t[i] == '?') ans = ans * 10 % mod;
    }
    ans = ((ans - (f[n][0] + f[n][1] - f[n][2])) % mod + mod) % mod;
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}