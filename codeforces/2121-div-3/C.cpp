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
void solve() {
    int n,m; cin >> n >> m;
    auto a = Vec<int>(n+5, m+5, 0);
    rep(i,1,n) rep(j,1,m) cin >> a[i][j];
    int mx = 0;
    rep(i,1,n) rep(j,1,m) mx = max(a[i][j], mx);
    vector<pair<int,int>> vec;
    rep(i,1,n) rep(j,1,m) {
        if(a[i][j] == mx) {
            vec.push_back({i,j});
        }
    }
    vector<int> ctx(n+5), cty(m+5);
    for(auto [x,y] : vec) {
        ctx[x]++;
        cty[y]++;
    }
    vector<int> ismxx, ismxy;
    rep(i,1,n) {
        if(ctx[i] > 0)
            ismxx.push_back(i);
    }
    rep(i,1,m) {
        if(cty[i] > 0)
            ismxy.push_back(i);
    }
    // cout << ismxx.size() << ' ' << ismxy.size() << endl;
    if(ismxx.size() <= 1 || ismxy.size() <= 1) {
        cout << mx - 1 << endl;
        return;
    }
    {
        int mxct = 0;
        for(auto i : ctx) mxct = max(mxct, i);
        vector<int> ismx;
        rep(i,1,n) if(ctx[i] == mxct) ismx.push_back(i);
        if(ismx.size() <= 3) {
            for(auto x : ismx) {
                rep(j,1,m) if(a[x][j] == mx) cty[j]--;
                vector<int> ismxy;
                rep(j,1,m) if(cty[j] > 0) ismxy.push_back(j);
                if(ismxy.size() <= 1){
                    cout << mx - 1 << endl;
                    return;
                }
                rep(j,1,m) if(a[x][j] == mx) cty[j]++;
            }
        }
    }
    
    {
        int mxct = 0;
        for(auto i : cty) mxct = max(mxct, i);
        vector<int> ismx;
        rep(j,1,m) if(cty[j] == mxct) ismx.push_back(j);
        for(auto y : ismx) {
            rep(i,1,n) if(a[i][y] == mx) ctx[i]--;
            vector<int> ismxx;
            rep(i,1,n) if(ctx[i] > 0) ismxx.push_back(i);
            if(ismxx.size() <= 1){
                cout << mx - 1 << endl;
                return;
            }
            rep(i,1,n) if(a[i][y] == mx) ctx[i]++;
        }
    }
    cout << mx << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
