#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr ll mod = 998244353;
constexpr ll base = 256;
constexpr int maxn = 1.1e6+10;
struct BIT {
    int n, f[50], zerocnt = 0;
    void init(int x = 30) {
        this->n = x;
        zerocnt = 0;
        memset(f, 0, sizeof(f));
    }
    int lowbit(int x) {
        return x&-x;
    }
    void add(int x, int v) {
        // cout << "Add at " << x << endl;
        if(x == 0) {
            zerocnt += v;
            return;
        }
        while(x <= n) {
            f[x] += v;
            x += lowbit(x);
        }
    }
    int query(int x) {
        int ret = 0;
        while(x) {
            ret += f[x];
            x -= lowbit(x);
        }
        return ret + zerocnt;
    }
};
BIT bit;
ll basn[maxn];
void solve() {
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    ll hs[n+5] = {};
    for(int i=1;i<=n;i++)
        hs[i] = (hs[i-1] * base + s[i]) % mod;
    auto get_hash = [&](int l, int r) {
        return (hs[r] - hs[l - 1] * basn[r - l + 1] % mod + mod) % mod;
    };
    int ct[n+5][26] = {};
    for(int i=1;i<=n;i++) {
        for(int j=0;j<26;j++) {
            ct[i][j] = ct[i-1][j] + (s[i] == 'a' + j);
        }
    }
    int odd_cnt[n+5] = {}, suf_cnt[n+5] = {};
    for(int i=1;i<=n;i++) {
        for(int j=0;j<26;j++) {
            odd_cnt[i] += (ct[i][j] % 2 == 1);
            suf_cnt[i] += ((ct[n][j] - ct[i-1][j]) % 2 == 1);
        }
    }
    bit.init(30);
    ll ans = 0;
    for(int i=2;i<n;i++) {                  // length of AB
        bit.add(odd_cnt[i-1], 1);
        for(int j=1;j<=(n-1)/i;j++) {       // count of AB
            int l = (j-1)*i+1, r = j*i;
            if(get_hash(1, i) != get_hash(l, r)) {
                break;
            }
            int sufcnt = suf_cnt[r+1];
            ans += bit.query(sufcnt);
            // cout << sufcnt << ' ' << bit.query(sufcnt) << endl;
            // cout << "ans: " << ans << endl;
        }
    }
    cout << ans << endl;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    basn[0] = 1;
    for(int i=1;i<=(1<<20)+5;i++)
        basn[i] = basn[i-1] * base % mod;
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}