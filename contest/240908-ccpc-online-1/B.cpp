#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr ll mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int a[n+5];
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+1+n);
    ll ans = 0;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++)
            ans += a[j] - a[i];
    }
    ll jc[n+5];
    jc[0] = 1;
    for(int i=1;i<=n;i++) jc[i] = jc[i-1] * i % mod;
    ll ct = 1;
    map<int,int> ctm;
    for(int i=1;i<=n;i++)
        ctm[a[i]]++;
    for(auto [x,y] : ctm) {
        ct = ct * jc[y] % mod;
    }
    if(ctm.size() != 1)
        ct = ct * 2 % mod;
    cout << ans << ' ' << ct << endl;
    return 0;
}