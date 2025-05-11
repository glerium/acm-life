#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
using ll = long long;

const int N = 1e6 + 10;

ll n;
ll c[N], t[N];
ll lr = 1e9;

bool check(ll mid) {
    ll l = 1, r = 1e9;
    rep(i, 2, n) {
        ll now = c[i - 1];
        ll dt = t[i] - t[i - 1];
        ll ds = dt * mid;
        // if(mid == 2){
        //     cout << l << " " << r << " " << dt << " " << ds << '\n';
        // }
        if((now - ds <= c[i] && now + ds >= c[i]) && (l - ds <= c[i] && r + ds >= c[i])){
            l = min(l - ds, now - ds);
            r = max(r + ds, now + ds);
        }else if((now - ds <= c[i] && now + ds >= c[i])){
            l = l - ds;
            r = r + ds;
        }else if((l - ds <= c[i] && r + ds >= c[i])){
            l = now - ds;
            r = now + ds;
        }else return false;
        l = max(1ll, l);
        r = min(lr, r);
    }
    return true;
}

void solve() {
    cin >> n;
    rep(i, 1, n) {
        cin >> t[i] >> c[i];
    }
    ll l = 0, r = 1e9; 
    ll ans = -1;
    while(l <= r) {
        ll mid = (l + r) >> 1;
    //    cout << l << " " << r << '\n';
        if(check(mid)) {
            r = mid - 1;
            ans = mid;
        }else l = mid + 1;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while(_--)
        solve();
}