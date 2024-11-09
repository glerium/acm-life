#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 50005;
struct Trie {
    int ct;
    int nxt[maxn * 10][10];
    char val[maxn * 10];
    bool end[maxn * 10];
    void reset() {
        ct = 0;
        memset(nxt, 0, sizeof(nxt));
        memset(val, 0, sizeof(val));
        memset(end, 0, sizeof(end));
    }
    void add(const string &s) {
        int now = 0;
        for(int i=0;i<s.size();i++) {
            if(!nxt[now][s[i] - '0']) {
                nxt[now][s[i] - '0'] = ++ct;
                val[ct] = s[i];
            }
            now = nxt[now][s[i] - '0'];
        }
        end[now] = true;
    }
} trie;
void solve() {
    trie.reset();
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        string s; cin >> s;
        trie.add(s);
    }
    for(int i=1;i<=trie.ct;i++) {
        if(!trie.end[i]) continue;
        for(int j=0;j<=9;j++) {
            if(trie.nxt[i][j]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}
int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}