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
    array<ll,3> a;
    rep(i,0,2) cin >> a[i];
    sort(a.begin(), a.end(), greater<>());
    if(a[0] > (a[1] + a[2]) * 2)
        cout << (a[1] + a[2]) << endl;
    else
        cout << (a[0] + a[1] + a[2]) / 3 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}