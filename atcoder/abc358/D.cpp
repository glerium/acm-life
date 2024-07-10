#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,m; cin>>n>>m;
    ll a[n+5], b[m+5]; 
    rep(i,1,n) cin >> a[i];
    rep(i,1,m) cin >> b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    ll ans = 0;
    int i=1,j=1;
    while(i <= m) {
        while(a[j] < b[i] && j <= n) j++;
        if(a[j] >= b[i] && j <= n)
            ans += a[j];
        else {
            cout << -1 << endl;
            return;
        }
        i++;
        j++;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
