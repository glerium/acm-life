#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
int popcount(int x) {
    int ans = 0;
    while(x) {
        ans += x&1;
        x >>= 1;
    }
    return ans;
}
void solve() {
    int n,m; cin>>n>>m;
    string s[n+5];
    rep(i,1,n) cin >> s[i];
    int t[n+5];
    rep(i,1,n) {
        t[i] = 0;
        for(auto j : s[i]) {
            t[i] = (t[i] << 1) | (j == 'o');
        }
    }
    
    int ans = 114514;
    for(int i=0;i<(1<<n);i++) {
        int now = 0;
        for(int j=0;j<n;j++) {
            if(i & (1 << j)) {
                now |= t[j+1];
            }
        }
        if(now == (1 << m) - 1) {
            ans = min(ans, popcount(i));
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
