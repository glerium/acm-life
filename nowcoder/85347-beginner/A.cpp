#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n;
    multiset<int> st;
    cin >> n;
    rep(i,1,n) {
        int x; cin >> x;
        st.insert(x);
        if(st.count(x) >= 3) {
            puts("YES");
            return;
        }
    }
    puts("NO");
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
