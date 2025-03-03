#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int a[n+5] = {};
    rep(i,1,n) cin >> a[i];
    struct SpItem {
        int lx,ly,rx,ry;
        int posl, posr;
        bool operator<(const SpItem& rhs) const {
            return abs(posl - posr) > abs(rhs.posl - rhs.posr);
        };
    };
    priority_queue<SpItem> q;
    
    int pos[n+5] = {};
    rep(i,1,n) pos[a[i]] = i;
    rep(i,1,n-1) {
        q.push({i,i,i+1,i+1,pos[i],pos[i+1]});
    }
    ll ans = 0;
    while(!q.empty()) {
        auto now = q.top(); q.pop();
        // pos: r->l; val: l=r;
        ans += abs(now.posl - now.posr);
        now.posr = now.posl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
