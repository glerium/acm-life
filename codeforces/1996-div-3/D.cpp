#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,x; cin >> n >> x;
    ll ans = 0;
    for(int a=1;a<=n;a++) {
        for(int b=1;b<=n/a;b++) {
            ans += max(0,min(x-a-b, (n-a*b)/(a+b)));
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
