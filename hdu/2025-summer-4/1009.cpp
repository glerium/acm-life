#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
void solve() {
    int n; cin >> n;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    ll ct1 = 0, ct2 = 2;
    rep(i,1,n) {
        if(a[i] == 0) {
            goto no;
        } else if(a[i] == 1)
            ct1++;
        else {
            ct2 += a[i] - 2;
        }
    }
    if(ct1 > ct2) goto no;
    else goto yes;
no: cout << "NO" << endl;
    return;
yes:cout << "YES" << endl;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}