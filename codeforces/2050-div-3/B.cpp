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
    ll s = 0;
    rep(i,1,n) s += a[i];
    if(s % n != 0) {
        cout << "NO" << endl;
    }else {
        rep(i,2,n-1) {
            if(a[i-1] != s / n) {
                ll tmp = s / n - a[i-1];
                a[i-1] += tmp;
                a[i+1] -= tmp;
            }
        }
        bool ok = true;
        rep(i,1,n) {
            if(a[i] != s / n) {
                ok = false;
                break;
            }
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
