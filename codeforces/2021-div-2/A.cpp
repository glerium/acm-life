#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    multiset<int> st;
    for(int i=1;i<=n;i++) {
        int t; cin >> t;
        st.insert(t);
    }
    while(st.size() > 1) {
        int x = *st.begin(); st.erase(st.begin());
        int y = *st.begin(); st.erase(st.begin());
        st.insert((x+y)>>1);
    }
    cout << *st.begin() << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
