#include <bits/stdc++.h>

#define rep(i,x,y) for(int i=x;i<=y;i++)

#define ll long long
using namespace std;

const int mod = 1e9 + 7;

const int N = 1e5 + 10;

ll p3[N];

void solve() {
    string s;
    cin >> s;
    ll ans = 0;
    ll n = s.size();
    p3[0] = 1;
    rep(i, 1, n)  p3[i] = p3[i - 1] * 3 % mod;
    rep(i, 0, n - 2) {
        ans = (ans + p3[i]) % mod;
    }
   // cout << ans << '\n';
    ll tmp = 1;
    rep(i, 1, n - 1){
        if(s[i] == '1'){
            ans += p3[n - 1 - i] * tmp % mod;
            ans %= mod;
            tmp *= 2;
            tmp %= mod;
        }
    }
    ans += tmp;
 //   cout << ans << '\n';
    cout << (ans * 2 + 1) % mod << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}