#include <bits/stdc++.h>

#define rep(i,x,y) for(int i=x;i<=y;i++)

const int  N = 2e5 + 10, inf = 1e9 + 7;

using namespace std;

int n, q; 

int mp[N], tot = 0;

int h[N];

int len[N];

void solve() {
    cin >> n >> q;
    rep(i, 1, n) cin >> h[i];
    rep(i, 1, n) {
        int tmp = 0;
        while(tot && h[mp[tot]] < h[i]) {
            len[mp[tot]] = i - mp[tot];
            tmp ++, tot --;
        }
        h[]
    }
    int ans = inf;
    rep(i, 1, q) {
        int l, r;
        cin >> l >> r;
        ans = min(max(len[l] - (r - l), 0), len[r]);
        
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}