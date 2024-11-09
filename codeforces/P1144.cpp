#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr int maxn = 5e6+10;
constexpr ll mod = 100003;
int n,m,ct,head[maxn],dis[maxn];
bitset<maxn> vis;
ll ans[maxn];
struct Edge {
    int to, nxt;
}a[maxn << 1];
struct State {
    int x;
    int dis;
};
void add(int x, int y) {
    a[++ct] = {y, head[x]};
    head[x] = ct;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=1;i<=m;i++) {
        int x, y; cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    memset(dis, 0x3f, sizeof(dis));
    vis.reset();
    dis[1] = 0;
    ans[1] = 1;
    queue<State> q;
    q.push({1, 0});
    while(!q.empty()) {
        auto now = q.front(); q.pop();
        int x = now.x;
        if(vis[x]) continue;
        vis[x] = true;
        for(int i=head[x];i;i=a[i].nxt) {
            if(vis[a[i].to])
                continue;
            if(dis[a[i].to] > dis[x] + 1) {
                dis[a[i].to] = dis[x] + 1;
                ans[a[i].to] = ans[x];
                q.push({a[i].to, dis[a[i].to]});
            }else if(dis[a[i].to] == dis[x] + 1) {
                ans[a[i].to] += ans[x];
                ans[a[i].to] %= mod;
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout << ans[i] << endl;
    return 0;
}