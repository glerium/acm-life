#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 5e3+10;
constexpr ll mod = 1e9+7;
ll jc[maxn],C[maxn][maxn];
void init() {
    jc[0] = 1;
    rep(i,1,5000) jc[i] = jc[i-1] * i % mod;
    rep(i,0,5000) {
        rep(j,0,i) {
            if(j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
            }
        }
    }
    // rep(i,1,10) {
    //     rep(j,0,i) 
    //         cout << C[i][j] << ' ';
    //     cout << endl;
    // }
}
void solve() {
    int n; cin >> n;
    int a[n+5] = {};
    rep(i,1,n) cin >> a[i];
    ll ans = 0;
    vector<int> ct(n+5);
    vector<int> pos(n+5), nexist(n+5);
    rep(i,1,n) if(a[i] != -1) pos[a[i]] = i;
    nexist[0] = (pos[0] == 0);
    rep(i,1,n-1) nexist[i] = nexist[i-1] + (pos[i] == 0);
    rep(i,1,n) ct[i] = ct[i-1] + (a[i] == -1);
    vector<int> premin(n+5), sufmin(n+5);
    premin[0] = sufmin[n+1] = n+1;
    rep(i,1,n) {
        premin[i] = premin[i-1];
        if(a[i] != -1)
            premin[i] = min(premin[i], a[i]);
    }
    for(int i=n;i>=1;i--) {
        sufmin[i] = sufmin[i+1];
        if(a[i] != -1)
            sufmin[i] = min(sufmin[i], a[i]);
    }
    int d[n+5][n+5] = {};
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) {
            // [l, r]
            int mn = min(premin[i-1], sufmin[j+1]);
            int nct = ct[j] - ct[i-1];
            // add to d_nct[0...mn-1]
            d[nct][0]++;
            d[nct][mn]--;
        }
    }
    rep(i,0,n) {
        rep(j,1,n) {
            d[i][j] += d[i][j-1];
        }
    }
    rep(i,0,n) {
        rep(j,0,n-1) {
            // i * -1; from 0 ... j are valid
            int need = nexist[j];
            ans += C[i][need] * jc[need] % mod * jc[ct[n] - need] % mod * d[i][j] % mod;
            ans %= mod;
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
