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
    vector<int> a(n+5), b(n+5);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    int ans = 0;
    auto getans = [&](int in1, int in2) {
        swap(a[in1], a[in2]);
        int x = 1, y = 1, pt = 0, ct = 0;
        while(ct < n) {
            if(a[x] > b[y]) {
                x++;
                pt++;
            }
            else {
                y++;
            }
            ct++;
        }
        swap(a[in1], a[in2]);
        return pt;
    };
    int xx = 0, yy = 0;
    rep(i,1,n) rep(j,(i==1)?i:i+1,n) {
        int tmp = getans(i, j);
        if(tmp > ans) {
            ans = tmp;
        }
        // cerr << i << ' ' << j << ' ' << tmp << endl;
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
