#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef unsigned long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    ll n, k; cin >> n >> k;
    ll len = n;
    ll ct = 1;
    ll ans = 0;
    while(len >= k) {
        if(len % 2 == 1) {
            ans += (1 + n) * ct / 2;
        }
        ct *= 2;
        len /= 2;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

