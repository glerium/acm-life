#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 1e6+10;
int n,m,s,head[maxn],ct;
bitset<maxn> vis;
ll dis[maxn];
struct Edge {
    int to, nxt;
    ll dis;
}a[maxn];
struct State {
    int id;
    ll dis;
    bool operator<(const State& rhs)const {
        return dis > rhs.dis;
    }
};
void add(int x, int y, ll dis) {
    a[++ct] = {y, head[x], dis};
    head[x] = ct;
}
void dijkstra(int x) {
    memset(dis, 0x3f, sizeof(dis));
    dis[x] = 0;
    priority_queue<State> q;
    q.push({x, 0});
    while(!q.empty()) {
        auto now = q.top(); q.pop();
        if(now.dis != dis[now.id])
            continue;
        if(vis[now.id])
            continue;
        vis[now.id] = true;
        for(int i=head[now.id];i;i=a[i].nxt) {
            if(dis[a[i].to] > dis[now.id] + a[i].dis) {
                dis[a[i].to] = dis[now.id] + a[i].dis;
                q.push({a[i].to, dis[a[i].to]});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll inf;
    memset(&inf, 0x3f, sizeof(inf));
    cin >> n >> m >> s;
    for(int i=1;i<=m;i++) {
        int x,y; ll z; cin >> x >> y >> z;
        add(x, y, z);
    }
    dijkstra(s);
    for(int i=1;i<=n;i++) {
        if(dis[i] == inf)
            cout << (1<<31) - 1 << ' ';
        else
            cout << dis[i] << ' ';
    }
    cout << endl;
}