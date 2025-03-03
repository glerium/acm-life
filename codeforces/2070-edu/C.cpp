#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,k; cin >> n >> k;
    string s; cin >> s; s = ' ' + s;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    auto check = [&](int x) -> bool {
        int now = -1;   // 0 blue 1 red
        int ct = 0;
        rep(i,1,n) {
            if(a[i] <= x) {
                continue;
            } else if(now == -1) {
                now = (s[i] == 'R');
                ct += (s[i] == 'B');
            } else if(now == 0 && s[i] == 'R') {
                now = 1;
            } else if(now == 1 && s[i] == 'B') {
                now = 0;
                ct++;
            }
        }
        return ct <= k;
    };
    int l = 0, r = 1e9, mid, ans;
    while(l <= r) {
        mid = l + r >> 1;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
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
