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
    int step;
    bool operator<(const State& rhs) const {
        return step > rhs.step;
    }
};
void solve() {
    int n,k; cin >> n >> k;
    vector<vector<int>> a(n+5);
    rep(i,1,n-1) {
        int x, y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    auto nb = Vec<int>(n+5, k+5, 0, 0);
    int anc = 0;
    set<int> st;
    function<void(int,int)> dfs = [&](int x, int step) {
        if(step > k) return;
        if(st.count(x)) return;
        st.insert(x);
        nb[anc][step].push_back(x);
        for(auto v : a[x]) {
            dfs(v, step + 1);
        }
    };
    rep(i,1,n) {
        anc = i;
        st.clear();
        dfs(i, 0);
    }
    priority_queue<State> q;
    vector<int> dis(n+5, inf);
    vector<bool> vis(n+5);
    q.push({1, 0});
    dis[1] = 0;
    while(!q.empty()) {
        auto now = q.top(); q.pop();
        if(dis[now.x] != now.step) continue;
        if(vis[now.x]) continue;
        vis[now.x] = true;
        for(auto v : nb[now.x][k]) {
            if(dis[v] > dis[now.x] + 1) {
                dis[v] = dis[now.x] + 1;
                q.push({v, dis[v]});
            }
        }
    }
    rep(i,2,n) {
        if(dis[i] == inf) cout << -1 << ' ';
        else cout << dis[i] << ' ';
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}