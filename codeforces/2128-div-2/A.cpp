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
    ll n,c; cin >> n >> c;
    vector<ll> a(n+5);
    rep(i,1,n) cin >> a[i];
    sort(a.begin() + 1, a.begin() + 1 + n);
    for(int i=n;i>=0;i--) {
        ll w = 1;
        // test if answer is i
        bool ok = true;
        for(int j=i;j>=1;j--) {
            if(a[j] * w > c) {
                ok = false;
                break;
            }
            w *= 2;
        }
        if(ok) {
            cout << n - i << endl;
            return;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}