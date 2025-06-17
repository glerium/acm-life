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
    int k,a,b,x,y; cin >> k >> a >> b >> x >> y;
    int ans = 0;
    int kk = k;
    int now = 0;

    now = 0;
    kk = k;
    if(kk >= a) {
        int tmp = (kk - a) / x + 1;
        now += tmp;
        kk -= tmp * x;
    }
    // cout << ":" << now << endl;
    if(kk >= b) {
        int tmp = (kk - b) / y + 1;
        now += tmp;
        kk -= tmp * y;
    }
    ans = max(ans, now);
    
    now = 0;
    kk = k;
    if(kk >= b) {
        int tmp = (kk - b) / y + 1;
        now += tmp;
        kk -= tmp * y;
    // cout << ":" << now << endl;
    }
    if(kk >= a) {
        int tmp = (kk - a) / x + 1;
        now += tmp;
        kk -= tmp * x;
    }
    ans = max(ans, now);
    
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
