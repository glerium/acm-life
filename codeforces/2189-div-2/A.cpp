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
    int n,h,l; cin >> n >> h >> l;
    if(h > l) swap(h, l);
    // h <= l
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    sort(a.begin() + 1, a.begin() + 1 + n);
    int s = 0;
    // rep(i,1,h*l) {
    //     int x; cin >> x;
    //     s += x;
    // }
    int ct0 = 0, ct1 = 0;
    rep(i,1,n) {
        if(a[i] <= h) ct0++;
        else if(a[i] <= l) ct1++;
    }
    // cout << ct1 << ' ' << ct0 << endl;
    if(ct1 > ct0) cout << ct0 << endl;
    else cout << (ct1 + ct0) / 2 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}