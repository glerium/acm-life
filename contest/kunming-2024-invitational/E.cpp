#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
using ll = long long;

const int N = 1e6 + 10;
ll a[N];
ll rd[N];
ll ld[N];

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
void solve() {
    ll n, k;
    cin >> n >> k;
    
    rep(i, 1, n)
        cin >> a[i];
    rd[n] = a[n];
    for(int i = n - 1; i >= 1; i -- ) rd[i] = gcd(a[i], rd[i + 1]);
    ld[1] = a[1];
    rep(i, 2, n) ld[i] = gcd(ld[i - 1], a[i]);
    // rep(i, 1, n) {
    //     cout << ld[i] << ' ';
    // }
    // cout << '\n';
    // rep(i, 1, n) {
    //     cout << rd[i] << ' ';
    // }
    // cout << '\n';
    vector <ll> mp;
    mp.push_back(1);
    ll tmp = a[1];
    rep(i, 2, n) { 
        if(gcd(tmp, a[i]) < tmp) {
            mp.push_back(i);
        }
        tmp = gcd(tmp, a[i]);
    }
    // for(auto i : mp) {
    //     cout << i << ' ';
    // }
    // cout << '\n';
    ll ans = ld[n];
    ll ansx, ansy;
    for(auto i : mp) {
        // [1, i], [i, j], [j, n]
        ll tt = a[i] + k;
        rep(j, i, n) {
            tt = gcd(tt, a[j] + k); 
            ll tt1 = tt;
       //     cout << i << " " << j << " " << tt1 << '\n';
            if(i > 1) tt1 = gcd(tt1, ld[i - 1]);
            if(j < n) tt1 = gcd(tt1, rd[j + 1]);
      //      cout << i << " " << j << " " << tt1 << '\n';
            if(tt1 > ans) {
                ansx = i;
                ansy = j;
            }
            ans = max(ans, tt1);
        }
    } 
 //   cout << ansx << " " << ansy << '\n';
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
}