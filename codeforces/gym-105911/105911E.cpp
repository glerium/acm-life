#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll INF = 0x3f3f3f3f;
int BLOCK_SIZE;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr (sizeof...(args) == 1) {
        return vector<T>(n, args...);
    } else {
        return vector(n, Vec<T>(args...));
    }
}
struct Query {
    int l,r,id;
    bool operator<(const Query& rhs) const {
        if(l / BLOCK_SIZE != rhs.l / BLOCK_SIZE) return l < rhs.l;
        if((l / BLOCK_SIZE) & 1) return r < rhs.r;
        return r > rhs.r;
    }
};
void solve() {
    int n,k,q; cin >> n >> k >> q;
    BLOCK_SIZE = max(1.0, n / sqrt(q));
    vector<int> mp(n + 5);
    ll nowAns = 0, l = 0, r = -1;
    string s; cin >> s; s = ' ' + s;
    
    auto ct = Vec<ll>(n+5, 26, 0);
    vector<ll> cths(n + 5);
    rep(i,1,n) {
        rep(j,0,25) {
            ct[i][j] = (ct[i-1][j] + (s[i] == 'a' + j)) % k;
        }
    }
    rep(i,1,n) {
        ll hs = 0;
        rep(j,0,25) {
            hs = hs * 10007 + ct[i][j];
        }
        cths[i] = hs;
    }
    map<ll,int> allhs;
    int ctt = 0;
    rep(i,0,n) {
        if(!allhs.count(cths[i])) {
            allhs[cths[i]] = ++ctt;
        }
    }
    vector<int> cthsid(cths.size());
    rep(i,0,n) {
        cthsid[i] = allhs[cths[i]];
    }

    vector<Query> querys(q+5);
    rep(i,1,q) {
        querys[i].id = i;
        cin >> querys[i].l >> querys[i].r;
        querys[i].l--;
    }
    sort(querys.begin() + 1, querys.begin() + 1 + q);
    auto update = [&](int pos, int sign) {
        if(sign == 1) {
            // add pos into map
            nowAns += mp[cthsid[pos]];
            mp[cthsid[pos]]++;
        } else {
            // del pos from map
            nowAns -= mp[cthsid[pos]] - 1;
            mp[cthsid[pos]]--;
        }
    };
    vector<ll> ans(q+5);
    rep(i,1,q) {
        const auto &q = querys[i];
        while(l > q.l) update(--l, 1);
        while(r < q.r) update(++r, 1);
        while(l < q.l) update(l++, -1);
        while(r > q.r) update(r--, -1);
        ans[q.id] = nowAns;
    }
    rep(i,1,q) {
        cout << ans[i] << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
