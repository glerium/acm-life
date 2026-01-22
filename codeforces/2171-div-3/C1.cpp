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
    int na = 0, nb = 0;
    rep(i,1,n) {
        if(a[i] == b[i]) {
            na ^= a[i];
            nb ^= b[i];
        }
    }
    rep(i,1,n) {
        if(a[i] == b[i]) continue;
        if(i % 2 == 1) {
            if((na ^ a[i]) < (nb ^ b[i]) && a[i] != b[i]) {
                swap(a[i], b[i]);
            }
        } else if (i % 2 == 0) {
            if((na ^ a[i]) > (nb ^ b[i]) && a[i] != b[i]) {
                swap(a[i], b[i]);
            }
        }
        na ^= a[i];
        nb ^= b[i];
    }
    if(na > nb) cout << "Ajisai" << endl;
    else if(na == nb) cout << "Tie" << endl;
    else if(na < nb) cout << "Mai" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}