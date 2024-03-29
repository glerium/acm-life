#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 4e5+10;
string s;
struct Manacher {
    int N, lc[maxn];
    char t[maxn];
    int operator[](int idx) const {
        return lc[idx];
    }
    void init() {
        int n = s.size() - 1;
        N = 2 * n + 1;
        memset(lc, 0, sizeof(int) * (n + 5));
        memset(t, 0, sizeof(char) * (n + 5));
        t[0] = '^';
        t[n*2+1] = '#';
        t[n*2+2] = '\0';
        for(int i=1;i<=n;i++) {
            t[i*2] = s[i];
            t[i*2-1] = '#';
        }
    }
    void manacher() {
        lc[1] = 1;
        int k = 1;
        for(int i=2;i<=N;i++) {
            int p = k + lc[k] - 1;
            if(i <= p)
                lc[i] = min(lc[2*k-i], p-i+1);
            else
                lc[i] = 1;
            while(t[i+lc[i]] == t[i-lc[i]]) lc[i]++;
            if(i+lc[i] > k+lc[k])
                k = i;
        }
    }
    void debug() {
        puts(t+1);
        for(int i=1;i<=N;i++)
            printf("lc[%d]=%d]n", i, lc[i]);
    }
} manacher;
void solve() {
    int n, q; cin >> n >> q;
    cin >> s;
    s = ' ' + s;
    manacher.init();
    manacher.manacher();
    vector<int> c1(n+5), c2(n+5);
    for(int i=1;i<=n;i++) {
        c1[i] = c1[i-1] + (s[i] == s[i-1]);
        if(i>1) c2[i] = c2[i-1] + (s[i] == s[i-2]);
    }
    while(q--) {
        int l,r; cin >> l >> r;
        int len = r - l + 1;
        ll ans = 1ll * len * (len+1) / 2 - 1;               // 2 + 3 + ... + n
        if(c1[r] - c1[l] == r - l) ans = 0;                 // 全部字符相等，答案为0
        else {
            if(manacher[l+r] >= len) ans -= len;            // 字符串本身是回文串
            if(c2[r] - c2[l+1] == len-2) {                  // 字符串为间隔串，奇数不存在
                int ii = (len-2) / 2;
                int qr = 2 * ii + 1;
                int qlen = (qr - 3) / 2 + 1;
                ans -= 1ll * (3 + qr) * qlen / 2;           // ans -= (3 + 5 + ... + max(odd) in (len-1))
            }
        }
        cout << ans << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
}