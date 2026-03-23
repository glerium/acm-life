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
    set<string> st;
    rep(i,1,n) {
        string s; cin >> s;
        st.insert(s);
    }
    int m; cin >> m;
    set<string> ex;
    rep(i,1,m) {
        string s; cin >> s;
        if(!st.count(s)) {
            cout << "WRONG" << endl;
        } else if(ex.count(s)) {
            cout << "REPEAT" << endl;
        } else {
            cout << "OK" << endl;
            ex.insert(s);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}