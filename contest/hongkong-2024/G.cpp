#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 1e6+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
int trie[maxn][26];
int val[maxn], dep[maxn];
int tot;
int newNode() {
    tot++;
    fill(trie[tot], trie[tot] + 26, 0);
    val[tot] = 0;
    return tot;
}
vector<vector<int>> fact(500005);
void solve() {
    int n; cin >> n;
    tot = 0;
    newNode();
    dep[1] = 0;
    
    ll ans = 0;
    vector<ll> f(n+5);
    rep(i,1,n) {
        string s; cin >> s;
        int now = 1;
        map<int,int> mp;
        for(auto j : s) {
            if(!trie[now][j - 'a']) {
                trie[now][j - 'a'] = newNode();
                dep[trie[now][j - 'a']] = dep[now] + 1;
            }
            now = trie[now][j - 'a'];
            val[now]++;
            for(auto k : fact[val[now]])
                mp[k]++;
        }
        for(auto [k, v] : mp) {
            ans ^= f[k] * k;
            f[k] += mp[k];
            ans ^= f[k] * k;
        }
        cout << ans << ' ';
    }
    cout << endl;
}
void init() {
    // init factors
    rep(i,1,5e5) {
        for(int j=i;j<=5e5;j+=i) {
            fact[j].push_back(i);
        }
    }
}
int main() {
    init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}