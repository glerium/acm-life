#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    set<int> st;
    for(int i=1;i<=1000;i+=2) st.insert(i*i);
    int s = 0;
    int ans = 0;
    rep(i,1,n) {
        int tmp; cin >> tmp;
        s += tmp;
        if(st.count(s))
            ans++;
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
