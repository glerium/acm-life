#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int n,q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while(n != 0) {
        cin >> q;
        int a[n+5] = {};
        a[0] = 114514;
        rep(i,1,n) cin >> a[i];
        int g[n+5] = {}, b[n+5] = {}, ct = 0, end[n+5] = {};
        int cur = 0;
        rep(i,1,n) {
            if(a[i] != a[i-1]) {
                end[ct] = i-1;
                b[ct] = cur;
                cur = 0;
                ct++;
            }
            g[i] = ct;
            cur++;
        }
        b[ct] = cur;
        end[ct] = n;

        int mx[n+5][20] = {};
        rep(i,1,n)
            mx[i][0] = b[i];
        rep(i,1,18) {
            rep(j,1,n) {
                if(j+(1<<i)-1<=n)
                    mx[j][i] = max(mx[j][i-1], mx[j+(1<<(i-1))][i-1]);
            }
        }
        while(q--) {
            int x, y; cin >> x >> y;
            if(g[x] == g[y]) {
                cout << y - x + 1 << endl;
                continue;
            }
            int ans = max(end[g[x]]-x+1, y-end[g[y]-1]);
            for(int i=18,cur=g[x]+1; i>=0&&cur<=g[y]-1; i--) {
                if(cur + (1<<i) - 1 <= g[y] - 1) {
                    ans = max(ans, mx[cur][i]);
                    cur += (1 << i);
                }
            }
            cout << ans << endl;
        }
        cin >> n;
    }
    return 0;
}