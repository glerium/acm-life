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
    auto check = [&](int x, int y, int z) {
        if(x + y > z && x + z > y && z + y > x)
            return true;
        return false;
    };
    bool ok = false;
    rep(i,1,n-1) {
        if(check(a[i], a[i+1], a[i+1]) && check(a[i], a[i], a[i+1]))
            ok = true;
    }
    if(ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
