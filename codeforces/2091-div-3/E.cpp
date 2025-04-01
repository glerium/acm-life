#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 1e7+10;
constexpr ll mod = 998244353;
bool pri[maxn];
vector<int> primes;
void init() {
    rep(i,1,1e7) pri[i] = true;
    pri[1] = false;
    rep(i,1,1e7) {
        if(pri[i]) {
            for(int j=i+i;j<=1e7;j+=i) {
                pri[j] = false;
            }
        }
    }
    rep(i,1,1e7) {
        if(pri[i])
            primes.push_back(i);
    }
}
void solve() {
    int n; cin >> n;
    ll ans = 0;
    rep(i,1,n) {
        int lim = n / i;
        auto fnd = lower_bound(primes.rbegin(), primes.rend(), lim, greater<int>());
        if(fnd != primes.rend())
            ans += primes.rend() - fnd;
        // cout << ":" << i << ' ' << n / i << ' ' << ans << endl;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
