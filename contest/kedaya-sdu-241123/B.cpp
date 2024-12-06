#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    ll a[n+5] = {};
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n == 1) {
        cout << a[1] << ' ' << a[1] << endl;
        return 0;
    }
    ll ans1;
    if(a[1] == 1) {
        ans1 = a[1] + a[2];
    }else if(a[1] != 1) {
        ans1 = a[1] * a[2];
    }
    for(int i=3;i<=n;i++) {
        if(a[i] == 1)
            ans1 += a[i];
        else
            ans1 *= a[i];
        ans1 %= mod;
    }
    sort(a+1, a+1+n);
    ll ans2;
    if(a[1] == 1) {
        ans2 = a[1] + a[2];
    }else if(a[1] != 1) {
        ans2 = a[1] * a[2];
    }
    for(int i=3;i<=n;i++) {
        if(a[i] == 1)
            ans2 += a[i];
        else
            ans2 *= a[i];
        ans2 %= mod;
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}