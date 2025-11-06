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
ll qpow(ll x, ll y) {
    if(!x) return 0;
    if(!y) return 1;
    if(y&1) return x * qpow(x, y - 1) % mod;
    return qpow(x * x % mod, y / 2);
}
ll frac(ll x, ll y) {
    return x * qpow(y, mod - 2) % mod;
}
typedef vector<vector<ll>> Matrix;
Matrix matmul(const Matrix& a, const Matrix& b, int c) {
    Matrix ret = Vec<ll>(c+1, c+1, 0ll);
    rep(k,0,c) rep(i,0,c) rep(j,0,c) {
        ret[i][j] += a[i][k] * b[k][j] % mod;
        ret[i][j] %= mod;
    }
    return ret;
}

Matrix qpow(Matrix a, ll y, int c) {
    Matrix res = a;
    y--;
    while (y != 0) {
        if (y & 1) res = matmul(res, a, c);
        a = matmul(a, a, c);
        y >>= 1;
    }
    return res;
}
void solve() {
    int n,m,a,b,c;
    cin >> n >> m >> a >> b >> c;
    vector<ll> w(m+1);
    rep(i,1,m) cin >> w[i];
    auto P = Vec<ll>(m+1, c+1, c+1, 0ll);
    rep(i,1,m) {
        P[i][0][0] = 1;
        rep(j,1,c) {
            ll sum = 0;
            rep(k,0,j) {
                cin >> P[i][j][k];
                sum += P[i][j][k];
            }
            rep(k,0,j) {
                P[i][j][k] = frac(P[i][j][k], sum);
            }
        }
    }
    vector<ll> pzero(n+5), tv(n+5);
    rep(i,1,n) {
        Matrix now = Vec<ll>(c+1, c+1, 0);
        now[0][c] = 1;
        int t; cin >> t;
        rep(j,1,t) {
            ll ty, num;
            cin >> ty >> num;
            now = matmul(now, qpow(P[ty], num, c), c);
            tv[i] += num * w[ty] % mod;
        }
        tv[i] %= mod;
        pzero[i] = now[0][0] % mod;
    }
    vector<ll> pok(n+5);
    rep(i,1,n) pok[i] = (1 - pzero[i] + mod) % mod;
    auto dp = Vec<ll>(n+1, a, 0);
    auto p = Vec<ll>(n+1, a, 0);
    p[0][0] = 1;
    dp[0][0] = 0;
    rep(i,1,n-1) {
        rep(j,0,a-1) {
            dp[i][(j + tv[i]) % a] += (dp[i-1][j] + tv[i]) * pok[i] % mod * p[i-1][j] % mod;
            dp[i][tv[i] % a] += (dp[i-1][j] - j + tv[i] + mod) % mod * pzero[i] % mod * p[i-1][j] % mod;

            p[i][(j + tv[i]) % a] += p[i-1][j] * pok[i] % mod;
            p[i][tv[i] % a] += p[i-1][j] * pzero[i] % mod;
        }
        rep(j,0,a-1) {
            dp[i][j] %= mod;
            p[i][j] %= mod;
        }
    }
    if(!pok[n]) {
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    rep(j,0,a-1) {
        ll ct = frac((dp[n-1][j] - j * p[n-1][j] % mod + mod) % mod, a);
        ans += (ct * b % mod + j * p[n-1][j] % mod * pok[n] % mod) % mod;
    }
    
    ll reach = 0;
    rep(j,0,a-1) reach = (reach + p[n-1][j]) % mod;
    ans = (ans + tv[n] % mod * reach) % mod;

    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}