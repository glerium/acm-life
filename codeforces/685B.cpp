#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 6e5+10;
constexpr ll mod = 998244353;
struct Edge{
    int to, nxt;
};
void solve() {
    int n,q; cin >> n >> q;
    int head[maxn]={},ct=0,sz[maxn]={},maxsz[maxn]={},centroid[maxn]={},fa[maxn]={};
    Edge a[maxn]={};
    auto add = [&](int x,int y) {
        a[++ct]={y,head[x]};
        head[x] = ct;
        fa[y] = x;
    };
    for(int i=2;i<=n;i++) {
        int x; cin >> x;
        add(x, i);
    }
    function<void(int)> dfs = [&](int x) {
        sz[x] = 1;
        centroid[x] = x;
        for(int i=head[x];i;i=a[i].nxt) {
            dfs(a[i].to);
            sz[x] += sz[a[i].to];
            maxsz[x] = max(maxsz[x], sz[a[i].to]);
        }
        for(int i=head[x];i;i=a[i].nxt) {
            int p = centroid[a[i].to];
            while(p != x) {
                if(max(sz[x] - sz[p], maxsz[p]) <= sz[x] / 2) {
                    centroid[x] = p;
                    break;
                }
                p = fa[p];
            }
        }
    };
    dfs(1);
    while(q--) {
        int x; cin >> x;
        cout << centroid[x] << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
