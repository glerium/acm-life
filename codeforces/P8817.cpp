#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef unsigned long long ll;
constexpr int maxn = 5e3+10;
constexpr int maxm = 1e4+5;
int n,m,k,head[maxn],ct,dis[maxn],d[maxn][maxn];
ll w[maxn];
bitset<maxn> v;
struct Edge{
    int to,nxt;
}a[maxm<<1];
struct State {
    int x;
    int dis;
};
struct Node {
    int x;
    ll w;
    bool operator<(const Node& rhs) const {
        return w != rhs.w ? w > rhs.w : x < rhs.x;
    }
};
set<Node> ok[maxn];
void add(int x, int y) {
    a[++ct] = {y, head[x]};
    head[x] = ct;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k; k++;
    rep(i,2,n) cin >> w[i];
    for(int i=1;i<=m;i++) {
        int x, y; cin >> x >> y;
        add(x,y); add(y,x);
    }
    for(int i=1;i<=n;i++) {
        queue<State> q;
        q.push({i, 0});
        memset(dis, 0x3f, sizeof(dis));
        dis[i] = 0;
        v.reset();
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            if(cur.dis != dis[cur.x])
                continue;
            if(v[cur.x]) continue;
            v[cur.x] = true;
            int x = cur.x;
            for(int i=head[x];i;i=a[i].nxt) {
                if(v[a[i].to]) continue;
                if(dis[a[i].to] > dis[x] + 1) {
                    dis[a[i].to] = dis[x] + 1;
                    q.push({a[i].to, dis[a[i].to]});
                }
            }
        }
        memcpy(d[i], dis, sizeof(dis));
    }
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=n;j++)
    //         cout << d[i][j] << ' ';
    //     cout << endl;
    // }
    for(int i=2;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(j != 1 && j != i && d[i][j] <= k && d[j][1] <= k)
                ok[i].insert({j, w[j]});
        }
        while(ok[i].size() > 3) ok[i].erase(--ok[i].end());
    }

    ll ans = 0;
    for(int i=2;i<=n;i++) {
        for(int j=2;j<=n;j++) {
            if(i == j) continue;
            if(d[i][j] > k)
                continue;

            ll cur = w[i] + w[j];
            int sel=-1, sel2=-1;
            
            for(auto tt : ok[i]) {
                if(tt.x == j || tt.x == 1) continue;
                sel = tt.x;
                break;
            }
            if(sel == -1)
                continue;
            cur += w[sel];

            for(auto tt : ok[j]) {
                if(tt.x == i || tt.x == sel | tt.x == 1) continue;
                sel2 = tt.x;
                break;
            }
            if(sel2 == -1)
                continue;
            cur += w[sel2];

            if(cur > ans) {
                ans = cur;
                // cout << sel << ' ' << i << ' ' << j << ' ' << sel2 << endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}