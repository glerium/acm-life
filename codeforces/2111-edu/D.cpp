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
    int n,m; cin >> n >> m;
    int a[m+5] = {};
    rep(i,1,m) cin >> a[i];
    sort(a+1,a+1+m);
    rep(i,1,n) {
        int k = (i + 1) / 2;
        if(i&1) {
            cout << a[k] << ' ' << a[m-k+1] << ' ' << a[k] << ' ' << a[m-k+1] << ' ' << a[k] << ' ' << a[m-k+1] << endl;
        } else {
            cout << a[m-k+1] << ' ' << a[k] << ' ' << a[m-k+1] << ' ' << a[k] << ' ' << a[m-k+1] << ' ' << a[k] << endl;
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
