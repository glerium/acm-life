#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int q, m; cin >> q >> m;
    ll now = 1;
    int gl[q+5] = {};
    rep(i,1,q) {
        int op; ll x;
        cin >> op >> x;
        if(op == 1) {
            gl[i] = x;
            now *= x;
            cout << now % m << endl;
        } else {
            now /= gl[x];
            cout << now % m << endl;
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
