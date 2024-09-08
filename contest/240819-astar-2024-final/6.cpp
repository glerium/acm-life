#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
constexpr int maxn = 1e6+10;
constexpr ll mod = 998244353;
int n;
ll a[maxn],cl[maxn],cr[maxn];
// map<int,set<int>, greater<int>> mp, mp2;
void lisan() {
    ll b[maxn];
    memcpy(b, a, sizeof(a));
    sort(a+1,a+n+1);
    map<ll,ll> mp;
    int ct = 0;
    for(int i=1;i<=n;i++) {
        if(!mp.count(a[i]))
            mp[a[i]] = ++ct;
    }
    for(int i=1;i<=n;i++) {
        a[i] = mp[b[i]];
    }
}
struct BIT{
    ll a[maxn];
    int lowbit(int x){
        return x&-x;
    }
    void add(int x,ll v) {
        while(x <= n+5) {
            a[x] += v;
            a[x] %= mod;
            x += lowbit(x);
        }
    }
    ll query(int x) {
        ll ans = 0;
        while(x) {
            ans += a[x];
            ans %= mod;
            x -= lowbit(x);
        }
        return ans;
    }
};
signed main() {
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    lisan();
    BIT bit1;
    for(int i=1;i<=n;i++) {
        cl[i] = 1 + bit1.query(a[i]-1);
        cl[i] %= mod;
        bit1.add(a[i], cl[i]);
    }
    BIT bit2;
    for(int i=n;i>=1;i--) {
        cr[i] = 1 + bit2.query(a[i]-1);
        cr[i] %= mod;
        bit2.add(a[i], cr[i]);
    }
    ll ans = 0;
    for(int i=1;i<=n;i++) {
        ans += cr[i]%mod*cl[i]%mod;
        // cout<<i<<' ' <<cl[i]<<' '<<cr[i]<<endl;
        ans %= mod;
    }
    cout<<ans<<endl;
    return 0;
}