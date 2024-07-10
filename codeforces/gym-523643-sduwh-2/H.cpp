#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
struct Line {
    int l, r; 
    bool operator<(const Line& rhs) const {
        if(l != rhs.l)
            return l < rhs.l;
        return r < rhs.r;
    }
};
void solve() {
    int n; cin >> n;
    Line a[n+5]={};
    rep(i,1,n) cin >> a[i].l >> a[i].r;
    int maxr = 0;
    rep(i,1,n) maxr = max(maxr, a[i].r);
    a[n+1] = {maxr, maxr};
    sort(a+1, a+1+n);
    int ans = 0;
    for(int i=1;i<=n;i++) {
        if(a[i].l != a[i+1].l) {
            ans++;
            
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
