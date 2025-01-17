#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n, k; cin >> n >> k;
    int a[n+5] = {}, ct = 0;
    for(int i=k;i<=n;i+=k) {
        a[i] = ++ct;
    }
    rep(i,1,n) if(!a[i]) {
        a[i] = ++ct;
    }
    rep(i,1,n) cout << a[i] << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
