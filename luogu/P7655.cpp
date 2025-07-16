#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
struct State {
    int x;
    bool type;
    int day, hour;
    bool operator<(const State& rhs) const {
        if(day != rhs.day)
            return day > rhs.day;
        return hour > rhs.hour;
    }
};
struct Road {
    int from, type;
    int to, day, len;
};
void solve() {
    int from, to; cin >> from >> to;
    int n,m; cin >> n >> m;
    vector<vector<tuple<int,int,bool>>> a(n+5);
    rep(i,1,m) {
        int x,y,z; cin >> x >> y >> z;
        if(z > 12) continue;
        a[x].push_back({y, z, 1});
        a[y].push_back({x, z, 0});
    }
    priority_queue<State> que;
    pair<int,int> dis[n+5][2];
    bool vis[n+5][2] = {};
    Road fr[n+5][2] = {};

    rep(i,1,n) rep(j,0,1) {
        dis[i][j] = {inf, inf};
    }

    dis[from][1] = {1,0};
    que.push({from, 1, 1, 0});
    // vis[from][1] = true;
    while(!que.empty()) {
        auto now = que.top(); que.pop();
        auto [nowx, nowt, nowd, nowh] = now;
        if(vis[nowx][nowt]) continue;
        vis[nowx][nowt] = true;
        for(auto [v, d, ty] : a[nowx]) {
            auto newdis = make_pair(nowd, nowh + d);
            if(newdis.second >= 12) {
                newdis.first ++;
                newdis.second = d;
            }
            if(newdis.first % 2 != ty) {
                newdis.first ++;
                newdis.second = d;
            }
            if(dis[v][ty] > newdis) {
                dis[v][ty] = newdis;
                fr[v][ty] = {nowx, nowt, v, newdis.first, d};
                que.push({v, ty, newdis.first, newdis.second});
            }
        }
    }
    // cout << dis[to][0].first << ' ' << dis[to][0].second << ' ' << dis[to][1].first << ' ' << dis[to][1].second << endl;
    pair<int,int> fina;
    if(dis[to][0] < dis[to][1])
        fina = {to, 0};
    else
        fina = {to, 1};
    vector<array<int,4>> ans;
    auto now = fina;
    while(now.first != from) {
        auto &road = fr[now.first][now.second];
        ans.push_back({road.from, road.to, road.day, road.len});
        now = {road.from, road.type};
    }
    // auto &road = fr[now.first][now.second];
    // ans.push_back({road.from, road.to, road.day, road.len});
    reverse(ans.begin(), ans.end());
    for(auto [x, y, z, w] : ans) {
        cout << x << ' ' << y << ' ' << z << ' ' << w << endl;
    }
    return ;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}