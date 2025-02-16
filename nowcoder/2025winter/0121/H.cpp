#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
struct Item {
    int l, r, i;
    bool operator<(const Item& rhs) const {
        if(r - l != rhs.r - rhs.l)
            return r - l < rhs.r - rhs.l;
        // return l < rhs.l;
        return rand() % 2;
    }
};
void solve() {
    int n; cin >> n;
    Item a[n+5] = {};
    rep(i,1,n) {
        cin >> a[i].l >> a[i].r;
        a[i].i = i;
    }
    int ans[n+5] = {};
    sort(a+1, a+1+n);
    set<int> st;
    rep(i,1,n) st.insert(i);
    rep(i,1,n) {
        auto fnd = st.lower_bound(a[i].l);
        if(fnd == st.end() || *fnd > a[i].r) {
            cout << -1 << endl;
            return;
        }
        ans[a[i].i] = *fnd;
        st.erase(fnd);
    }
    rep(i,1,n) cout << ans[i] << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
