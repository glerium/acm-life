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
    int n; cin >> n;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    int q; cin >> q;
    BLOCK_SIZE = n / sqrt(q);
    nowAns = 0;
    vector<Query> querys(q+5);
    vector<int> ans(q+5);
    rep(i,1,q) {
        cin >> querys[i].l >> querys[i].r;
        querys[i].id = i;
    }
    int l = 1, r = 0;
    sort(querys.begin() + 1, querys.begin() + 1 + q);
    vector<int> mp(1000007);
    auto update = [&](int pos, int sign) {
        int bef = mp[a[pos]] != 0;
        mp[a[pos]] += sign;
        int aft = mp[a[pos]] != 0;
        nowAns += aft - bef;
    };
    rep(i,1,q) {
        const auto &q = querys[i];
        while(l > q.l) update(--l, 1);
        while(r < q.r) update(++r, 1);
        while(l < q.l) update(l++, -1);
        while(r > q.r) update(r--, -1);
        ans[q.id] = nowAns;
    }
    rep(i,1,q) cout << ans[i] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
