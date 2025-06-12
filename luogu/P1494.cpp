#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll INF = 0x3f3f3f3f;
int BLOCK_SIZE;
struct Frac {
    int x, y;
} nowAns;
struct Query {
    int l,r,id;
    bool operator<(const Query& rhs) const {
        if(l / BLOCK_SIZE != rhs.l / BLOCK_SIZE) return l < rhs.l;
        if((l / BLOCK_SIZE) & 1) return r < rhs.r;
        return r > rhs.r;
    }
};
void solve() {
    int n,m; cin >> n >> m;
    BLOCK_SIZE = n / sqrt(m);
    nowAns = {0, 1};
    vector<Query> querys(m+5);
    vector<Frac> ans(m+5);
    vector<int> c(n+5);
    rep(i,1,n) cin >> c[i];
    rep(i,1,m) {
        querys[i].id = i;
        cin >> querys[i].l >> querys[i].r;
    }
    sort(querys.begin() + 1, querys.begin() + 1 + m);
    vector<ll> ct(n+5);
    ll sum = 0;
    auto update = [&](int pos, int sign) {
        int oldc = ct[c[pos]] * (ct[c[pos]] - 1) / 2;
        ct[c[pos]] += sign;
        int newc = ct[c[pos]] * (ct[c[pos]] - 1) / 2;
        sum += sign;
        nowAns.x += newc - oldc;
        nowAns.y = sum * (sum - 1) / 2;
    };
    int l = 1, r = 0;
    rep(i,1,m) {
        const auto &q = querys[i];
        while(l > q.l) update(--l, 1);
        while(r < q.r) update(++r, 1);
        while(l < q.l) update(l++, -1);
        while(r > q.r) update(r--, -1);
        ans[q.id] = nowAns;
    }
    rep(i,1,m) {
        int g = gcd(ans[i].x, ans[i].y);
        if(g) {
            ans[i].x /= g;
            ans[i].y /= g;
        } else {
            ans[i].x = 0;
            ans[i].y = 1;
        }
        cout << ans[i].x << '/' << ans[i].y << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
