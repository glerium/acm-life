#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll INF = 0x3f3f3f3f;
int BLOCK_SIZE, nowAns;
struct Query {
    int l,r,id;
    bool operator<(const Query& rhs) const {
        if(l / BLOCK_SIZE != rhs.l / BLOCK_SIZE) return l < rhs.l;
        if((l / BLOCK_SIZE) & 1) return r < rhs.r;
        return r > rhs.r;
    }
};
void solve() {
    int n,m,k; cin >> n >> m >> k;
    BLOCK_SIZE = n / sqrt(m);
    nowAns = 0;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    vector<Query> querys(m + 5);
    rep(i,1,m) {
        cin >> querys[i].l >> querys[i].r;
        querys[i].id = i;
    }
    sort(querys.begin() + 1, querys.begin() + 1 + m);
    int l = 1, r = 0;
    vector<ll> ans(m+5), ct(k+5);
    auto update = [&](int pos, int sign) {
        ll old = ct[a[pos]];
        ct[a[pos]] += sign;
        nowAns += ct[a[pos]] * ct[a[pos]] - old * old;
    };
    rep(i,1,m) {
        const auto &q = querys[i];
        while(l > q.l) update(--l, 1);
        while(r < q.r) update(++r, 1);
        while(l < q.l) update(l++, -1);
        while(r > q.r) update(r--, -1);
        ans[q.id] = nowAns;
    }
    rep(i,1,m) {
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
