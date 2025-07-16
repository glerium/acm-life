#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    vector<int> ans(n+5);
    for(int i=0;i<(1<<n);i++) {
        int ct = 0;
        int g = 0, mex = 0;
        set<int> st;
        for(int j=0;j<n;j++) {
            if((1<<j)&i) {
                ct++;
                g = gcd(g, a[j+1]);
                st.insert(a[j+1]);
            }
        }
        while(st.count(mex)) mex++;
        ans[ct] = max(ans[ct], g ^ mex);
    }
    rep(i,1,n) cout << ans[i] << ' ';
    cout << endl;
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}