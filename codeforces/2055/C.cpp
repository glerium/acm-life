#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
struct State {
    int blank;
    bool row;
    int id;
    bool operator<(const State& rhs) const {
        return blank > rhs.blank;
    }
};
void solve() {
    int n,m; cin >> n >> m;
    string s; cin >> s;
    ll a[n+5][m+5] = {};
    rep(i,1,n) rep(j,1,m) cin >> a[i][j];
    int ba[n+5] = {}, bb[m+5] = {};
    int cx = 1, cy = 1;
    set<int> ea[n+5], eb[m+5];
    ba[1] = bb[1] = 1;
    ea[1].insert(1);
    eb[1].insert(1);
    for(auto ch : s) {
        if(ch == 'D') {
            cx++;
        }else{
            cy++;
        }
        ba[cx]++;
        bb[cy]++;
        ea[cx].insert(cy);
        eb[cy].insert(cx);
    }

    priority_queue<State> q;
    rep(i,1,n) q.push({ba[i], true, i});
    rep(i,1,m) q.push({bb[i], false, i});
    bool first = true;
    ll x = 0;
    while(!q.empty()) {
        auto now = q.top(); q.pop();
        if(now.row) {
            if(now.blank != ba[now.id]) {
                continue;
            }
            // assert(now.blank == 1);
            // if(first) {
            //     rep(i,1,m)
            //         x += a[now.id][i];
            //     first = false;
            // }else{
                ll s = 0;
                rep(i,1,m)
                    s += a[now.id][i];
                a[now.id][*ea[now.id].begin()] = x - s;
            // }
            rep(i,1,m) {
                if(eb[i].count(now.id)) {
                    eb[i].erase(now.id);
                    bb[i]--;
                    q.push({(int)eb[i].size(), false, i});
                }
            }
        }else {
            if(now.blank != bb[now.id]) {
                continue;
            }
            // if(first) {
            //     rep(i,1,n) {
            //         x += a[i][now.id];
            //     }
            //     first = false;
            // }else{
                ll s = 0;
                rep(i,1,n) {
                    s += a[i][now.id];
                }
                a[*eb[now.id].begin()][now.id] = x - s;
            // }
            rep(i,1,n) {
                if(ea[i].count(now.id)) {
                    ba[i]--;
                    ea[i].erase(now.id);
                    q.push({(int)ea[i].size(), true, i});
                }
            }
        }
    }
    rep(i,1,n) {
        rep(j,1,m)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
