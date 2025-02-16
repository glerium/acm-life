#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
struct State {
    int i, j;
    int val;
    bool operator<(const State &rhs) const {
        return val < rhs.val;
    }
};
void solve() {
    int n,m,k; cin >> n >> m >> k;
    int a[n+5] = {}, b[m+5] = {};
    rep(i,1,n) cin >> a[i];
    rep(i,1,m) cin >> b[i];
    int mask[(1 << m) + 5] = {};
    for(int i=0;i<(1<<m);i++) {
        mask[i] = 0xffffffff;
        rep(j,0,m-1) {
            if(i & (1 << j))
                mask[i] &= b[j+1];
        }
    }
    int g[n+5][m+5] = {};
    int mn[m+2] = {};
    // int f[(1 << m) + 10] = {};
    rep(i,1,n) {
        rep(j,0,m) mn[j] = a[i];
        for(int j=0;j<(1<<m);j++) {
            int tmp = __popcount(j);
            mn[tmp] = min(mn[tmp], a[i] & mask[j]);
        }
        rep(j,1,m)
            g[i][j] = mn[j-1] - mn[j];
    }
    ll sum = accumulate(a+1, a+1+n, 0ll);
    priority_queue<State> q;
    rep(i,1,n) 
        q.push({i, 1, g[i][1]});
    while(k) {
        auto now = q.top(); q.pop();
        k--;
        sum -= now.val;
        if(now.j + 1 <= m)
            q.push({now.i, now.j+1, g[now.i][now.j+1]});
    }
    cout << sum << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
