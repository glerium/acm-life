#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
// int lowbit(int x) {
//     return x & -x;
// }
void solve() {
    int n; cin >> n;
    int a[n+5] = {};
    rep(i,1,n) cin >> a[i];
    ll ans = 0;
    map<int,int> st;
    rep(i,1,n) {
        vector<int> fact;
        for(int j=1;j*j<=a[i];j++) {
            if(a[i] % j == 0) {
                if(2 * (a[i] - j) >= a[i])
                    fact.push_back(a[i] - j);
                if(j*j != a[i] && 2 * (a[i] - a[i] / j) >= a[i])
                    fact.push_back(a[i] - a[i] / j);
            }
        }
        for(auto j : fact) {
            if((a[i] ^ j) != gcd(a[i], j)) continue;
            ans += st[j];
        }
        st[a[i]]++;
    }

    st.clear();

    for(int i=n;i>=1;i--) {
        vector<int> fact;
        for(int j=1;j*j<=a[i];j++) {
            if(a[i] % j == 0) {
                if(2 * (a[i] - j) >= a[i])
                    fact.push_back(a[i] - j);
                if(j*j != a[i] && 2 * (a[i] - a[i] / j) >= a[i])
                    fact.push_back(a[i] - a[i] / j);
            }
        }
        for(auto j : fact) {
            if((a[i] ^ j) != gcd(a[i], j)) continue;
            ans += st[j];
        }
        st[a[i]]++;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
