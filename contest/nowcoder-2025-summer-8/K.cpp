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
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    int i = 1;
    bool flag = true;
    while(i <= n) {
        if(s.substr(i, 3) != "ava") {
            flag = false;
            break;
        } else if (s.substr(i, 5) == "avava") {
            i += 5;
        } else {
            i += 3;
        }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}