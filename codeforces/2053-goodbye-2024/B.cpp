#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int l[n+5] = {}, r[n+5] = {};
    rep(i,1,n) cin >> l[i] >> r[i];
    multiset<int> st;
    rep(i,1,n) {
        if(l[i] == r[i])
            st.insert(l[i]);
    }
    int s[2*n+5] = {};
    rep(i,1,2*n)
        s[i] = s[i-1] + bool(!st.count(i));
    string ans;
    rep(i,1,n) {
        bool ok;
        if(l[i] == r[i])
            ok = st.count(l[i]) == 1;
        else  ok = s[r[i]] - s[l[i]-1];
        ans += ok ? '1' : '0';
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
