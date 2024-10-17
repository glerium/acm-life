#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,m,q; cin >> n >> m >> q;
    bool v[n+5] = {};
    int a[n+5], b[m+5];
    rep(i,1,n) cin >> a[i];
    rep(i,1,m) cin >> b[i];
    int j=1;
    rep(i,1,m) {
        if(v[b[i]]) continue;
        if(a[j] == b[i]) {
            j++;
            v[b[i]] = true;
            continue;
        }
        cout << "TIDAK" << endl;
        return;
    }
    cout << "YA" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
