#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,q; cin >> n >> q;
    int a[n+5] = {};
    multiset<int> s1,s2;
    rep(i,1,n) {
        cin >> a[i];
        s1.insert(a[i]+i);
        s2.insert(a[i]-i);
    }
    cout << min(*s1.rbegin() - *s1.begin(), *s2.rbegin() - *s2.begin()) << endl;
    while(q--) {
        int p,x; cin >> p >> x;
        s1.erase(a[p] + p);
        s1.insert(x + p);
        s2.erase(a[p] - p);
        s2.insert(x - p);
        a[p] = p;
        cout << min(*s1.rbegin() - *s1.begin(), *s2.rbegin() - *s2.begin()) << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
