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
    string s; cin >> s; s = ' ' + s;
    int ct = 0;
    char last = 0;
    rep(i,1,n) {
        if(s[i] != last) {
            last = s[i];
            ct++;
        }
    }
    if(s[1] != s[n]) {
        rep(i,1,n-1) {
            if(s[i] == s[i+1]) {
                ct++;
                break;
            }
        }
    }
    cout << ct << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}