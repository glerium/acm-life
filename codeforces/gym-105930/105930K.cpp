#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
int T, testcase;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
void solve() {
    int n,m; cin >> n >> m;
    auto a = Vec<int>(n+5, m+5, 0);
    rep(i,1,n) rep(j,1,m) cin >> a[i][j];
    if(testcase == 4165) {
        cerr << n << ' ' << m << endl;
        rep(i,1,n) {
            rep(j,1,m)
                cerr << a[i][j] << ' ';
            cerr << endl;
        }
    }
    map<int,map<int,vector<int>>> idx;
    rep(i,1,n) rep(j,1,m) {
        idx[a[i][j]][i].push_back(j);
    }
    rep(k,0,n+m) {
        if(idx[k].size() == 0) {
            cout << k << endl;
            return;
        }
        set<pair<int,int>> intervals;
        bool fail = false;
        if(idx[k].count(1)) {
            if(idx[k][1][0] != 1) {     // not (1,1)
                intervals.insert({1, idx[k][1][0] - 1});    // [1, idxk - 1]
                if(!idx[k].count(2) && 2 <= n) {
                    auto begin = *intervals.begin();
                    intervals.clear();
                    intervals.insert({begin.first, m});
                }
            } else {
                continue;
            }
        } else {
            intervals.insert({1, m});
        }
        for(auto &[x, ys] : idx[k]) {
            if(x == 1) {
                continue;
            }
            ys.push_back(m+1);
            if(intervals.empty())
                break;
            set<pair<int,int>> nintervals;
            int yki = 0;
            auto it = intervals.begin();
            while(yki < ys.size() && it != intervals.end()) {
                
            }
            intervals.swap(nintervals);
        }
        if(intervals.empty() || fail)
            continue;
        if(idx[k].count(n)) {
            auto [l,r] = *prev(intervals.end());
            if(l <= m && m <= r) {
                cout << k << endl;
                return;
            }
        } else {
            cout << k << endl;
            return;
        }
    }
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    for(testcase = 1; testcase <= T; testcase++) solve();
    return 0;
}
