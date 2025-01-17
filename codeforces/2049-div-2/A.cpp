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
    int ct = 0;
    rep(i,1,n) {
        int tmp; cin >> tmp;
        if(tmp == a[ct]) continue;
        a[++ct] = tmp;
    }
    int z = 0;
    rep(i,1,ct) z += a[i] == 0;
    if(z == ct) {
        cout << 0 << endl;
        return;
    }
    // cout << ':';rep(i,1,ct) cout << a[i] << ' ';
    // cout << endl;
    // cout << "Z=" << z << endl;
    z -= (a[1] == 0) + (a[ct] == 0);
    cout << min(z+1, 2) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
