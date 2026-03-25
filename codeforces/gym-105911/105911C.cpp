#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll INF = 0x3f3f3f3f;

template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr (sizeof...(args) == 1) {
        return vector<T>(n, args...);
    } else {
        return vector(n, Vec<T>(args...));
    }
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
ll C(ll x, ll y) {
    // x >= y
    if(x < y) return 0;
    ll ans = 1;
    rep(i,x-y+1,x) ans = (ans * i) % mod;
    rep(i,1,y) ans = frac(ans, i);
    return ans;
}

void solve() {
    vector<int> c(6);
    rep(i,1,5) {
        string s; cin >> s;
        if(s == "10") {
            c[i] = 10;
        } else {
            const char ch = s[0];
            if(ch == 'A')
                c[i] = 1;
            else if(ch == 'J')
                c[i] = 11;
            else if(ch == 'Q')
                c[i] = 12;
            else if(ch == 'K')
                c[i] = 13;
            else
                c[i] = ch - '0';
        }
    }
    sort(c.begin() + 1, c.begin() + 6);
    auto f = Vec<ll>(6, 107, 6, 107, 0);
    f[0][0][0][0] = 1;
    vector<int> deck;
    rep(i,1,13) {
        rep(j,1,4) {
            deck.push_back(i);
        }
    }
    rep(i,1,5) {
        deck.erase(find(deck.begin(), deck.end(), c[i]));
    }

    // me1, me2, you1, you2
    for(auto a : deck) {
        for(int i1=5; i1>=0; i1--) {
            for(int j1=100; j1>=0; j1--) {
                for(int i2=5; i2>=0; i2--) {
                    for(int j2=100; j2>=0; j2--) {
                        if(i1 >= 1 && j1 >= a) {
                            f[i1][j1][i2][j2] += f[i1-1][j1-a][i2][j2];
                            f[i1][j1][i2][j2] %= mod;
                        }

                        if(i2 >= 1 && j2 >= a) {
                            f[i1][j1][i2][j2] += f[i1][j1][i2-1][j2-a];
                            f[i1][j1][i2][j2] %= mod;
                        }
                    }
                }
            }
        }
    }

    rep(k,1,5) {
        int ins = 0;
        rep(i,k+1,5) ins += c[i];
        ll win = 0, eq = 0, lose = 0;
        rep(j1,0,100) {
            rep(j2,0,100) {
                const ll val = f[k][j1][5][j2];
                if(j1 + ins > j2) win = (win + val) % mod;
                else if(j1 + ins == j2) eq = (eq + val) % mod;
                else lose = (lose + val) % mod;

            }
        }
        ll all = (win + eq + lose) % mod;
        ll score = frac((k * (win - lose) % mod + mod) % mod, all);
        score = (score % mod + mod) % mod;
        cout << score << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
