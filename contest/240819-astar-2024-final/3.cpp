#include <iostream>
#include <queue>
#include <map>
#include <bitset>
#include <cstring>

using namespace std;
constexpr int maxn = 1.1e6+10;
typedef int ll;
int n,x1,y1,x2,y2;
bitset<maxn> vis;

inline int enc(int x,int y) {
    return x*1001+y;
}
inline pair<int,int> dec(int x) {
    return make_pair(x/1001, x%1001);
}
struct Edge{
    int to,nxt;
    ll dis;
}a[maxn<<2];
struct State{
    int x;
    ll dis;
    bool operator<(const State& rhs)const{
        return dis > rhs.dis;
    }
};
int head[maxn], ct;
ll dis[maxn];
priority_queue<State> q;
void add(int x,int y,ll dis) {
    a[++ct] = {y, head[x], dis};
    head[x] = ct;
}
map<pair<int,int>,ll> v;
void add_(int x,int y) {
    if(!v.count({x,y})) add(x,y,0);
    else add(x,y,v[{x,y}]);
}
int main() {
    cin >> n >> x1 >> y1 >> x2 >> y2;
    memset(dis, 0x3f, sizeof(dis));
    dis[enc(x1,y1)] = 0;
    for(int i=1;i<=n;i++) {
        int x,y; cin >> x >> y;
        v[{enc(x-1,y),enc(x,y)}] = 1;
        v[{enc(x+1,y),enc(x,y)}] = 1;
        v[{enc(x,y-1),enc(x,y)}] = 1;
        v[{enc(x,y+1),enc(x,y)}] = 1;
    }
    for(int i=0;i<=1001;i++) {
        for(int j=0;j<=1001;j++) {
            add_(enc(i,j), enc(i,j+1));
            if(j-1>=0)
                add_(enc(i,j), enc(i,j-1));
            add_(enc(i,j), enc(i+1,j));
            if(i-1>=0)
                add_(enc(i,j), enc(i-1,j));
        }
    }
    q.push({enc(x1,y1), 0});
    while(!q.empty()) {
        auto now = q.top();
        q.pop();
        if(vis[now.x]) continue;
        vis[now.x] = true;
        // cout << now.x << endl;
        if(now.x == enc(x2,y2))
            break;
        if(now.dis != dis[now.x])
            continue;
        for(int i=head[now.x];i;i=a[i].nxt) {
            // cout << a[i].to << endl;
            if(now.dis + a[i].dis < dis[a[i].to]) {
                dis[a[i].to] = now.dis + a[i].dis;
                q.push({a[i].to, dis[a[i].to]});
            }
        }
    }
    // for(int i=1;i<=3;i++) {
    //     for(int j=1;j<=3;j++)
    //         cout << i << ' ' << j << ' ' << dis[enc(i,j)] << endl;
    // }
    cout << dis[enc(x2, y2)] << endl;
    return 0;
}