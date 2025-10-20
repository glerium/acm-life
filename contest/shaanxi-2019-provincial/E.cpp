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
    int n,k; cin >> n >> k;
    string s; cin >> s; s = ' ' + s;
    int l = 1, r = n, mid, ans = 0;
    auto check = [&](int x) -> bool {
        int i = 1;
        int ct = 0;
        while(i <= n) {
            while(i <= n && s[i] != '1') {
                i++;
            }
            if(i > n) break;
            i += x;
            ct++;
        }
        return ct <= k;
    };
    while(l <= r) {
        mid = l + r >> 1;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
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