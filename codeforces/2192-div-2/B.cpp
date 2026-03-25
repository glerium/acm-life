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
    string s; cin >> s;
    s = ' ' + s;
    vector<int> zr, on;
    rep(i,1,n) {
        if(s[i] == '0')
            zr.push_back(i);
        else
            on.push_back(i);
    }
    if(on.size() % 2 == 0) {
        cout << on.size() << endl;
        for(auto i : on)
            cout << i << ' ';
        cout << endl;
    } else if(zr.size() % 2 == 1) {
        cout << zr.size() << endl;
        for(auto i : zr)
            cout << i << ' ';
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}