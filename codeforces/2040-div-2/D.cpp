#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
struct Edge {
    int to, nxt;
};
void solve() {
    int n; cin >> n;
    int u[n+5]={}, v[n+5]={};
    int ct = 0;
    Edge a[n << 1] = {};
    int head[n+5] = {};
    auto add = [&](int x, int y) {
        a[++ct] = {y, head[x]};
        head[x] = ct;
    };
    rep(i,1,n-1) {
        cin >> u[i] >> v[i];
        add(u[i], v[i]);
        add(v[i], u[i]);
    }
    int ans[n+5] = {};
    int now = 0;
    function<void(int,int)> dfs = [&](int x, int fa) {
        // cout << ":" << x << ' ' << fa << ' ' << now << endl;
        if(fa == -1) {
            ans[x] = 1;
            now = 2;
        }else{
            if(now - ans[fa] == 1 || ((now - ans[fa]) > 2 && ((now - ans[fa]) % 2) == 0)) {
                ans[x] = now;
            }else if(((now - ans[fa]) % 2 == 1)) {
                ans[x] = now + 1;
            }else{
                ans[x] = now + 2;
            }
            now = ans[x] + 1;
        }
        for(int i=head[x];i;i=a[i].nxt) {
            if(fa == a[i].to) continue;
            dfs(a[i].to, x);
        }
    };
    dfs(1, -1);
    rep(i,1,n) cout << ans[i] << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
