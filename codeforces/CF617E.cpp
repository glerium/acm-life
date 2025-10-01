#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll INF = 0x3f3f3f3f;
int BLOCK_SIZE;
ll nowAns;
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
    BLOCK_SIZE = sqrt(n);
    nowAns = 0;

    vector<int> a(n+5), s(n+5);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) {
        s[i] = s[i-1] ^ a[i];
    }

    vector<Query> querys(m+5);
    vector<ll> ans(m+5);
    rep(i,1,m) {
        cin >> querys[i].l >> querys[i].r;
        querys[i].l --;
        querys[i].id = i;
    }
    sort(querys.begin() + 1, querys.begin() + 1 + m);
    vector<int> mp1(1.2e6+10), mp2(1.2e6+10);
    auto update = [&](int pos, int sign) {
        if(sign == 1) nowAns += mp2[s[pos]];
        mp1[s[pos]] += sign;
        mp2[s[pos] ^ k] += sign;
        if(sign == -1) nowAns -= mp2[s[pos]];
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
