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
    int ct0 = 0, ct1 = 0;
    for(auto ch : s) {
        if(ch == 'Y') ct1++;
        else if (ch == 'N') ct0++;
    }
    if(ct1 >= 4) cout << 1;
    else if(ct0 >= 2) cout << -1;
    else cout << 0 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}