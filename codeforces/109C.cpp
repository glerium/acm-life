#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
int n, head[maxn], ct, sz[maxn], f1[maxn], f2[maxn];
struct Edge {
    int to, nxt;
    bool yes;
}a[maxn<<1];
bool check(int x) {
    while(x) {
        if(x % 10 != 4 && x % 10 != 7)
            return false;
        x /= 10;
    }
    return true;
}
void add(int x, int y, bool yes) {
    a[++ct] = {y, head[x], yes};
    head[x] = ct;
}
void dfs1(int x, int fa) {
    sz[x] = 1;
    for(int i=head[x];i;i=a[i].nxt) {
        if(a[i].to == fa) continue;
        dfs1(a[i].to, x);
        sz[x] += sz[a[i].to];
        if(a[i].yes) f1[x] += sz[a[i].to];
        else f1[x] += f1[a[i].to];
    }
}
void dfs2(int x, int fa) {
    for(int i=head[x];i;i=a[i].nxt) {
        if(a[i].to == fa) continue;
        if(a[i].yes) f2[a[i].to] += sz[1] - sz[a[i].to];
        else f2[a[i].to] += f2[x] + f1[x] - f1[a[i].to];
        dfs2(a[i].to, x);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1;i<=n-1;i++){
        int x, y, z; cin >> x >> y >> z;
        bool yes = check(z);
        add(x, y, yes);
        add(y, x, yes);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    ll ans = 0;
    for(int i=1;i<=n;i++) {
        ll ct = f1[i] + f2[i];
        ans += ct * (ct - 1);
    }
    cout << ans << endl;
    return 0;
}
