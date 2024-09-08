#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
ll getans(ll x) {
    ll l = 0, r = x, mid, ans;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(mid * (mid + 1) / 2 <= x) {
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return ans + 1;
}
void solve() {
    ll l, r; cin >> l >> r;
    cout << getans(r - l) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
