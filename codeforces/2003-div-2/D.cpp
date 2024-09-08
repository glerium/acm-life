#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n, m; cin >> n >> m;
    int mex[n+2][2] = {};
    auto input_calc_mex = [&](int idx) -> void {
        int m; cin >> m;
        int a[m+5]; rep(i,1,m) cin >> a[i];
        set<int> st;
        for(int i=1;i<=m;i++) st.insert(a[i]);
        int mexx=-1, mexx2=-1;
        bool fail=false;
        for(int i=0;;i++) {
            if(st.count(i)) continue;
            if(!fail) {
                mexx = i;
                fail = true;
            } else {
                mexx2 = i;
                break;
            }
        }
        mex[idx][0] = mexx; mex[idx][1] = mexx2;
    };
    for(int i=1;i<=n;i++) input_calc_mex(i);
    int lim = 0;
    for(int i=1;i<=n;i++) 
        lim = max(lim, max(mex[i][0], mex[i][1]));
    int f[lim+5] = {};
    int maxmex = 0;
    for(int i=1;i<=n;i++)
        maxmex = max(maxmex, mex[i][0]);
    for(int i=0;i<=lim;i++)
        f[i] = max(maxmex, i);
    map<int,vector<int>> to;
    for(int i=1;i<=n;i++) {
        to[mex[i][0]].push_back(mex[i][1]);
        f[mex[i][0]] = max(f[mex[i][0]], mex[i][1]);
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<mex[i][0];j++) {
            to[j].push_back(mex[i][0]);
        }
        for(int j=mex[i][0]+1;j<mex[i][1];j++)
            to[j].push_back(mex[i][1]);
    }
        for(int i=lim;i>=0;i--) {
            if(!to.count(i))
                continue;
            for(auto j : to[i])
                f[i] = max(f[i], f[j]);
        }
    ll ans = 0;
    for(int i=0;i<=min(lim, m);i++) {
        ans += f[i];
        // cout <<  "f[" << i << "]=" << f[i] << endl;
    }
    if(m > lim) {
        lim++;
        ll count = m - lim + 1;
        ans += count * (m + lim) / 2;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
