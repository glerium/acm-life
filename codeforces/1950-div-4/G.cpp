#include <bits/stdc++.h>
using namespace std;
struct Song {
    string sg, sw;
    int g, w;
};
void solve() {
    int n;
    cin >> n;
    vector<Song> a(n+5);
    map<string, int> mp;
    for(int i=0;i<n;i++) cin >> a[i].sg >> a[i].sw;
    for(int i=0,ct=0;i<n;i++) {
        if(!mp.count(a[i].sg))
            mp[a[i].sg] = ++ct;
        if(!mp.count(a[i].sw))
            mp[a[i].sw] = ++ct;
        a[i].g = mp[a[i].sg];
        a[i].w = mp[a[i].sw];
    }
    int g[16][16] = {};
    bool dp[1<<16][16] = {};

    for(int i=0;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(a[i].g == a[j].g || a[i].w == a[j].w) {
                g[i][j] = g[j][i] = true;
            }
        }
    }

    for(int i=0;i<n;i++)
        dp[1<<i][i] = true;

    for(int i=0;i<(1<<n);i++) {
        for(int j=0;j<n;j++) {
            if(!(i & (1 << j))) continue;
            for(int k=0;k<n;k++) {
                if(i & (1 << k)) continue;
                if(!g[j][k]) continue;
                int toi = i | (1 << k);
                dp[toi][k] |= dp[i][j];
            }
        }
    }
    int ans = 0;
    for(int i=0;i<(1<<n);i++) {
        for(int j=0;j<n;j++) {
            if(dp[i][j]) {
                cout << i << ' ' << j << endl;
                ans = max(ans, __builtin_popcount(i));
            }
        }
    }
    cout << n - ans << endl;
    return;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}