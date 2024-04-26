#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1e5+10;
int n,m;
set<int> st[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        int k; cin >> k;
        while(k--) {
            int tt; cin >> tt;
            st[i].insert(tt);
        }
    }
    int q; cin >> q;
    while(q--) {
        int x,y; cin>>x>>y;
        int ans = 0;
        for(int i=1;i<=n;i++) {
            if(st[i].count(x) && st[i].count(y))
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}