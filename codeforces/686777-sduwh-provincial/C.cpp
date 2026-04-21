#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k; cin >> n >> k;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    sort(a.begin() + 1, a.begin() + 1 + n);
    vector<ll> s(n+5);
    rep(i,1,n) s[i] = s[i-1] + a[i];
    int out = 0, outv;
    rep(i,1,n) {
        // target: i
        // find j, st. a[i] * (j - i) - (s[i] - s[j-1]) <= k
        int l = 1, r = i, mid, ans = -1;
        while(l <= r) {
            mid = l + r >> 1;
            if(1ll * a[i] * (i - mid + 1) - (s[i] - s[mid-1]) <= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if(i - ans + 1 > out) {
            out = i - ans + 1;
            outv = a[i];
        }
        // out = max(out, i - ans + 1);
    }
    cout << out << ' ' << outv << endl;
}