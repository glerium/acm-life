#include <bits/stdc++.h>
#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
using ll = long long;
struct Edge {
    int v,c,l;
};
struct State {
    int x;
    pair<int,int> dis;
    
    bool operator<(const State& rhs) const {
        return dis > rhs.dis;
    }
};
struct ST {
    const int n, k;
    vector<int> in;
    vector<vector<int>> mx;
    ST(int n) : n(n), in(n+1), k(__lg(n)) {
        mx.resize(k + 1, vector<int>(n + 1));
    }
    void init() {
        for(int i = 1; i <= n; i++) {
            mx[0][i] = in[i];
        }
        for(int i = 0, t = 1; i < k; i++, t <<= 1) {
            const int T = n - (t << 1) + 1;
            for(int j = 1; j <= T; j++) {
                mx[i + 1][j] = max(mx[i][j], mx[i][j + t]);
            }
        }
    }
    int getMax(int l, int r) {
        if(l > r)
            swap(l, r);
        int k = __lg(r - l + 1);
        return max(mx[k][l], mx[k][r - (1 << k) + 1]);
    }
    int getNext(int l, int r, int k) {
        if(l > r) return -1;
        if(l == r) {
            if(mx[0][l] >= k)
                return l;
            else
                return -1;
        } 
        int mid = (l + r) >> 1;
        if(getMax(l, mid) >= k)
            return getNext(l, mid, k);
        else if(getMax(mid + 1, r) >= k)
            return getNext(mid + 1, r, k);
        else
            return -1;
    }
};
void solve() {
    int n,m,k; cin >> n >> m >> k;
    vector<vector<Edge>> a(n+5);
    rep(i,1,m) {
        int u,v,c,l; cin >> u >> v >> c >> l;
        a[u].push_back({v,c,l});
        a[v].push_back({u,c,l});
    }
    vector<pair<int,int>> ti(k+5);
    rep(i,1,k) cin >> ti[i].first >> ti[i].second;

    vector<ST> st;
    vector<vector<int>> stin(m+5);
    vector<vector<int>> stini(m+5);
    rep(i,1,m) stin[i].push_back(0);
    rep(i,1,m) stini[i].push_back(0);
    st.push_back(ST(0));
    rep(i,1,k) {
        stin[ti[i].first].push_back(ti[i].second);
        stini[ti[i].first].push_back(i);
    }
    rep(i,1,m) {
        int nx = stin[i].size() - 1;
        st.push_back(ST(nx));
        st[i].in = stin[i];
        st[i].init();
    }
    assert(st.size() == m + 1);

    priority_queue<State> q;
    vector<pair<int,int>> dis(n+5);
    vector<bool> vis(n+5);
    rep(i,1,n) dis[i] = {k + 300, 0};
    dis[1] = {1, 0};
    // vis[1] = true;
    q.push({1, dis[1]});
    while(!q.empty()) {
        auto cur = q.top();
        q.pop();
        if(cur.dis != dis[cur.x])
            continue;
        if(vis[cur.x]) continue;
        vis[cur.x] = true;
        // cout << cur.x << ' ' << cur.dis.first << ' ' << cur.dis.second << endl;
        int nowti = cur.dis.first, nowl = cur.dis.second;
        for(auto [v,c,l] : a[cur.x]) {
            bool ok = false;
            if(c == ti[nowti].first && nowl + l <= ti[nowti].second) {
                auto ndis = make_pair(nowti, nowl + l);
                if(ndis < dis[v]) {
                    dis[v] = ndis;
                    q.push({v, ndis});
                    ok = true;
                }
            }
            if(!ok) {
                // int fnd = -1;
                // for(int i = nowti + 1; i <= k; i++) {
                //     if(ti[i].first == c && ti[i].second >= l) {
                //         fnd = i;
                //         break;
                //     }
                // }
                auto tmp = upper_bound(stini[c].begin(), stini[c].end(), nowti);
                if(tmp == stini[c].end())
                    continue;
                int nowti_in_c = tmp - stini[c].begin();
                int nk = st[c].getNext(nowti_in_c, st[c].n, l);
                if(nk == -1)
                    continue;
                auto ndis = make_pair(stini[c][nk], l);
                // cout << "find " << stini[c][nk] << endl;
                // if(fnd == -1)
                //     continue;
                // auto ndis = make_pair(fnd, l);
                // if(ndis < dis[v]) {
                //     dis[v] = ndis;
                //     q.push({v, ndis});
                // }
                if(ndis < dis[v]) {
                    dis[v] = ndis;
                    q.push({v, ndis});
                }
            }
        }
    }
    rep(i,1,n) cout << vis[i];
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
}