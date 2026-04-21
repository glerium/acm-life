#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
void solve() {
    int n,k; cin >> n >> k;
    set<int> st;
    rep(i,1,n) {
        int x; cin >> x;
        st.insert(x);
    }
    int now = 0;
    int ans = 0;
    rep(i,1,k) {
        while(st.count(now))
            now++;
        ans ^= now & 1;
        now++;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}