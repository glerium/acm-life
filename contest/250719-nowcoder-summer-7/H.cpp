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
    #define abegin a.begin() + 1
    #define aend a.begin() + 1 + n
    int mn = *min_element(a.begin() + 1, a.begin() + 1 + n),
        mx = *max_element(a.begin() + 1, a.begin() + 1 + n);
    while(mn != 0 || mx > 1) {
        sort(a.begin() + 1, a.begin() + 1 + n);
        int target = (mx + mn) >> 1;
        rep(i,1,n) a[i] = abs(a[i] - target);
        mn = *min_element(abegin, aend);
        mx = *max_element(abegin, aend);
    }
    int ct0 = count(abegin, aend, 0),
        ct1 = count(abegin, aend, 1);
    cout << 1ll * ct0 * ct1 % mod << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}