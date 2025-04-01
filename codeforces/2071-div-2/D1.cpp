#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; ll l, r;
    cin >> n >> l >> r;
    vector<int> a(2*n+5), s(2*n+5);
    rep(i,1,n) cin >> a[i];
    if(n%2 == 0) {
        n++;
        rep(i,1,n/2) a[n] ^= a[i];
    }
    rep(i,1,n) s[i] = s[i-1] ^ a[i];
    rep(i,n+1,2*n) {
        a[i] = s[i / 2];
    }
    int p = 0;
    rep(i,1,n) p ^= a[i];
    function<int(ll)> get = [&](ll x) -> int {
        if(x <= 2 * n) return a[x];
        if(x / 2 % 2 == 1) return p;
        else return p ^ get(x / 2);
    };
    cout << get(l) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
