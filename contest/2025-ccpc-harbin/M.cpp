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
vector<int> rev, roots{0, 1};
void dft(vector<int> &a) {
    int n = a.size();
    if(int(rev.size()) != n) {
        int k = __builtin_ctz(n) - 1;
        rev.resize(n);
        rep(i,0,n-1) {
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
        }
    }
    rep(i,0,n-1) {
        if(rev[i] < i) {
            swap(a[i], a[rev[i]]);
        }
    }
    if(roots.size() < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while((1 << k) < n) {
            int e = qpow(31, 1 << (__builtin_ctz(mod - 1) - k - 1));
            rep(i, 1<<(k-1), (1<<k)-1) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = 1ll * roots[i] * e % mod;
            }
            k++;
        }
    }
    for(int k = 1; k < n; k *= 2) {
        for(int i = 0; i < n; i += 2 * k) {
            for(int j = 0; j < k; j++) {
                int u = a[i + j];
                int v = 1ll * a[i + j + k] * roots[k + j] % mod;
                a[i + j] = (u + v) % mod;
                a[i + j + k] = (u - v) % mod;
            }
        }
    }
}
void idft(vector<int> &a) {
    int n = a.size();
    reverse(a.begin() + 1, a.end());
    dft(a);
    int inv = (1 - mod) / n;
    rep(i,0,n-1) {
        a[i] = 1ll * a[i] * inv % mod;
    }
}
vector<int> mul(vector<int> a, vector<int> b) {
    int n = 1, tot = a.size() + b.size() - 1;
    while(n < tot) {
        n *= 2;
    }
    if(tot < 128) {
        vector<int> c(tot);
        rep(i,0,a.size()-1) {
            rep(j,0,b.size()-1) {
                c[i + j] = (c[i + j] + 1ll * a[i] * b[j]) % mod;
            }
        }
        return c;
    }
    a.resize(n);
    b.resize(n);
    dft(a);
    dft(b);
    rep(i,0,n-1) {
        a[i] = 1ll * a[i] * b[i] % mod;
    }
    idft(a);
    a.resize(tot);
    for(auto &i : a) {
        i = (i + mod) % mod;
    }
    return a;
}
void solve() {
    int n; cin >> n;
    vector<int> xone, xzero, yone, yzero, zone, zzero;
    for(int i=n-1; i>=0; i--) {
        char ch; cin >> ch;
        if(ch == '1') {
            xone.push_back(i);
        } else {
            xzero.push_back(i);
        }
    }
    for(int i=n-1; i>=0; i--) {
        char ch; cin >> ch;
        if(ch == '1') {
            yone.push_back(i);
        } else {
            yzero.push_back(i);
        }
    }
    for(int i=1; i<=n; i++) {
        char ch; cin >> ch;
        if(ch == '1') {
            zone.push_back(i);
        } else {
            zzero.push_back(i);
        }
    }
    ll ans = 0;
    auto work = [&]() {
        vector<int> a(n+1), b(n+1), c(n+1);
        for(auto i : xone) {
            a[i] = 1;
        }
        for(auto i : yone) {
            b[i] = 1;
        }
        for(auto i : zone) {
            c[i] = 1;
        }
        for(int i=n-1;i>=0;i--) {
            c[i] += c[i+1];
        }
        auto f = mul(a, b);
        rep(i,1,n) {
            ans += 1ll * f[i-1] * c[i];
        }
    };
    cerr << "--" << endl;
    for(auto i : xone) cerr << i << ' ';
    cerr << endl;
    for(auto i : yone) cerr << i << ' ';
    cerr << endl;
    for(auto i : zone) cerr << i << ' ';
    work();
    swap(xone, xzero);
    swap(yone, yzero);
    swap(zone, zzero);
    // work();
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}