#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 3e5+10;
constexpr ll mod = 1e9+7;
ll ans[maxn];
void solve() {
    int n,k,p; cin>>n>>k;
    p = n;
    for(int i=1;i<=k;i++) {
        int x,y; cin>>x>>y;
        if(x!=y) p-=2;
        else p--;
    }
    cout << ans[p] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ans[0] = ans[1] = 1;
    for(int i=2;i<=3e5;i++) ans[i] = (ans[i-1] + 2*(i-1)*ans[i-2])%mod;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
