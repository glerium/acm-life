#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
void solve() {
    int n,m,x,y; cin >> n >> m >> x >> y;
    vector<int> a(n+1), b(m+1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,m) cin >> b[i];
    sort(a.begin() + 1, a.begin() + 1 + n);
    sort(b.begin() + 1, b.begin() + 1 + m);
    auto check = [&](int mid) -> bool {
        // 1...mid for art (y)
        // mid+1...n for books (x)
        vector<int> curh(m+1);
        int ct = 0;
        for(int i=n;i>=1;i--) {
            int tmp;
            if(i <= mid)
                tmp = y;
            else
                tmp = x;
            rep(j,1,tmp) {
                curh[++ct] = a[i];
                if(ct == m) break;
            }
            if(ct == m) break;
        }
        if(ct < m) return false;
        sort(curh.begin() + 1, curh.begin() + 1 + m);
        rep(i,1,m) {
            if(curh[i] < b[i])
                return false;
        }
        return true;
    };
    int l=1, r=n, mid, ans=-1;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if(ans == -1) {
        cout << "impossible" << endl;
    } else {
        cout << ans << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}