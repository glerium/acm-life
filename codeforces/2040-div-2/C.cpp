#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    ll n,k; cin >> n >> k;
    if(n < 61 && k > (1ll << (n-1))) {
        cout << -1 << endl;
        return;
    }
    int a[n+5] = {};
    function<void(ll,int,int,int)> compute = [&](ll kk, int l, int r, int x) -> void{
        // cout << kk << ' ' << l << ' ' << r << ' ' << x << endl;
        int len = r - l + 1;
        if(len == 0) {
            return;
        } else if(len == 1) {
            a[l] = 1 + x;
            return;
        }
        ll ct = 1ll << (len-1);
        if(len >= 61 || kk <= ct / 2) {
            a[l] = 1 + x;
            compute(kk, l+1, r, x+1);
        }else{
            a[r] = 1 + x;
            compute(kk - ct/2, l, r-1, x+1);
        }
    };
    compute(k, 1, n, 0);
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
