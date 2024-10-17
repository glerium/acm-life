#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,x; cin >> n >> x;
    int a[n+5];
    for(int i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+1+n);
    int mex = 0;
    map<int, multiset<int, greater<int>>> st;
    for(int i=1;i<=n;i++)
        st[a[i]%x].insert(a[i]);
    while(true) {
        if(st.count(mex%x)) {
            auto p = st[mex%x].lower_bound(mex);
            if(p != st[mex%x].end()) {
                st[mex%x].erase(p);
                mex++;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    cout << mex << endl;
}
int main() {
    ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
