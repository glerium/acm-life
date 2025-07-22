#pragma GCC optimize(3)
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
struct Edge {
    int to, w;
};
struct Edge2 {
    int from, to, w;
};

long double ans = INFINITY;
clock_t start_time;


void solve() {
    int n,m; cin >> n >> m;
    vector<vector<Edge>> a(n+5);
    rep(i,1,m) {
        int x,y,w; cin >> x >> y >> w;
        a[x].push_back({y, w});
    }

    vector<bool> vis(n+5);
    vector<Edge> trace;

    vector<bool> toN(n+5);
    function<void(int,int)> dfs3 = [&](int x, int begin) -> void {
        if(x == n) {
            toN[begin] = true;
            return;
        }
        for(auto [v, w] : a[x]) {
            if(vis[v]) continue;
            vis[v] = true;
            dfs3(v, begin);
        }
    };
    rep(i,1,n) {
        fill(vis.begin(), vis.end(), false);
        vis[i] = true;
        dfs3(i, i);
    }

    if(!toN[1]) {
        cout << -1 << endl;
        return;
    }

    function<void(int)> dfs = [&](int x) -> void {
        if(x == n && !trace.empty()) {
            int k = trace.size();
            long double avg = 0;
            for(auto [x, w] : trace) {
                avg += w;
            }
            avg /= k;
            long double dd = 0;
            for(auto [x, w] : trace) {
                dd += (w - avg) * (w - avg);
            }
            dd /= k;
            ans = min(ans, dd);
        }
        for(auto [v, w] : a[x]) {
            if(vis[v]) continue;
            vis[v] = true;
            trace.push_back({v, w});
            dfs(v);
            trace.pop_back();
            vis[v] = false;
        }
    };
    fill(vis.begin(), vis.end(), false);
    vis[1] = true;
    dfs(1);
    vis[1] = false;

    // with loop
    fill(vis.begin(), vis.end(), 0);
    vector<Edge2> trace2;
    int ct = 0;
    function<void(int)> dfs2 = [&](int x) -> void {
        for(auto [v, w] : a[x]) {
            if(!vis[v]) {
                vis[v] = true;
                trace2.push_back({x, v, w});
                dfs2(v);
                trace2.pop_back();
                vis[v] = false;
            } else {
                vector<int> curLoop;
                curLoop.push_back(w);
                bool ok = false;
                for(int i=trace2.size()-1;i>=0;i--) {
                    curLoop.push_back(trace2[i].w);
                    ok |= toN[trace2[i].from] || toN[trace2[i].to];
                    if(trace2[i].from == v)
                        break;
                }
                if(!ok) continue;
                int k = curLoop.size();
                long double avg = 0;
                for(auto w : curLoop) {
                    avg += w;
                }
                avg /= k;
                long double dd = 0;
                for(auto w : curLoop) {
                    dd += (w - avg) * (w - avg);
                }
                dd /= k;
                ans = min(ans, dd);
            }
        }
    };
    vis[1] = true;
    dfs2(1);
    vis[1] = false;
    cout << fixed << setprecision(15) << ans << endl;
}

int main() {
    start_time = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
