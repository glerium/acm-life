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
    int n,k; cin >> n >> k;
    string s; cin >> s;
    s = ' ' + s;
    auto f = Vec<int>(n+5, k+5, n+1);
    for(int i=n;i>=1;i--) {
        rep(j,1,k) {
            if(s[i] == 'a' + j - 1) {
                f[i][j] = i;
            } else {
                f[i][j] = f[i+1][j];
            }
        }
    }
    auto g = Vec<int>(n+5, 0);
    for(int i=n;i>=1;i--) {
        int mx = 0;
        rep(j,1,k) {
            mx = max(mx, f[i+1][j]);
        }
        g[i] = g[mx] + 1;
    }

    int q; cin >> q;
    while(q--) {
        string t; cin >> t;
        int pos = 1;
        int m = t.size();
        t = ' ' + t;
        rep(i,1,m) {
            int nxt = f[pos][t[i] - 'a' + 1];
            if(nxt != -1) {
                pos = nxt + 1;
            } else {
                cout << 0 << endl;
                goto end;
            }
        }
        // cout << "pos=" << pos << endl;
        cout << g[pos-1] << endl;
end:    ;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}