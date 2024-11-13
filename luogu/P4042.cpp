#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 1e6+10;
int n,head[maxn],ct,r[maxn];
ll dis[maxn],s[maxn],k[maxn],f[maxn];
bitset<maxn> vis;
struct Edge {
    int to, nxt;
}a[maxn << 1];
struct State {
    int x;
    ll dis;
    bool operator<(const State& rhs)const{
        return dis > rhs.dis;
    }
};
void add(int x, int y) {
    a[++ct] = {y, head[x]};
    head[x] = ct;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> s[i] >> k[i] >> r[i];
        for(int j=1;j<=r[i];j++) {
            int tmp; cin >> tmp;
            add(tmp, i);
        }
    }
    priority_queue<State> q;
    for(int i=1;i<=n;i++) {
        dis[i] = k[i];
        f[i] = s[i];
        q.push({i, dis[i]});
    }
    while(!q.empty()) {
        auto now = q.top(); q.pop();
        if(now.dis != dis[now.x])
            continue;
        int x = now.x;
        for(int i=head[x];i;i=a[i].nxt) {
            int to = a[i].to;
            r[to]--;
            f[to] += now.dis;
            if(dis[to] < f[to])
                continue;
            if(r[to] == 0) {
                dis[to] = f[to];
                q.push({to, dis[to]});
            }
        }
    }
    cout << dis[1] << endl;
}