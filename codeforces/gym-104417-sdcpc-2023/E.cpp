#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int t;
ll n,k,m,a,b;
inline bool check(__int128 l, __int128 r, __int128 k) {
    return l/k!=r/k || l%k==0 || r%k==0;
}
void solve(){
    cin>>n>>k>>m>>a>>b;
    if(n%m==0) {
        cout << 0 << endl;
        return;
    }
    if(k==1) {
        cout << -1 << endl;
        return;
    }
    ll ans = LLONG_MAX;
    ll start_now = n;
    for(int i=0;i<=70;i++) {
        ll now=start_now;
        ll cost=b*i;
        if(!now) {
            ans = min(ans, cost);
            break;
        }
        __int128 l=now, r=now;
        while(!check(l, r, m)) {
            l = l*k;
            r = r*k+k-1;
            cost += a;
        }
        ans = min(ans, cost);
        start_now /= k;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}