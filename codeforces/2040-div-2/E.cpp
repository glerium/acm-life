#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e3+10;
constexpr ll mod = 998244353;
struct Edge {
    int to, nxt;
};
void solve() {
    int n,q; cin >> n >> q;
    Edge a[maxn << 1] = {};
    int head[n+5]={}, ct=0, fa[n+5]={}, sz[n+5]={};
    auto add = [&](int x, int y) {
        a[++ct] = {y, head[x]};
        head[x] = ct;
    };
    rep(i,1,n-1) {
        int x, y; cin >> x >> y;
        add(x, y); add(y, x);
    }
    function<void(int,int)> dfs = [&](int x, int from) -> void {
        fa[x] = from;
        for(int i=head[x]; i; i = a[i].nxt) {
            if(a[i].to == from) continue;
            sz[x]++;
            dfs(a[i].to, x);
        }
    };
    dfs(1, 0);
    while(q--) {
        int v,p; cin >> v >> p;
        int ans = 0;
        vector<int> vec;
        int step = 1;
        while(v != 1) {
            if(step % 2 == 1) {
                v = fa[v];
            } else {
                vec.push_back(sz[v]);
                v = fa[v];
            }
            ans++;
            step++;
        }
        // for(auto i : vec) cout << i << ' ';
        // cout << endl;
        sort(vec.begin(), vec.end(), greater<int>());
        for(int i=p;i<vec.size();i++)
            ans += 2 * vec[i];
        cout << ans << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
