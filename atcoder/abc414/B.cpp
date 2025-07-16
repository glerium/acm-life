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
    string s;
    rep(i,1,n) {
        char c; ll l;
        cin >> c >> l;
        if(l > 100) {
            cout << "Too Long" << endl;
            return;
        }
        s += string(l, c);
    }
    // cout << s << endl;
    if(s.size() > 100) {
            cout << "Too Long" << endl;
    } else {
        cout << s << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}