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
    int n,s; cin >> n >> s;
    int ct[3] = {};
    rep(i,1,n) {
        int x; cin >> x;
        ct[x]++;
    }
    int sum = ct[1] + 2 * ct[2];
    if(sum == s || s > sum && ((s - sum) % 2 == 0 || (s - sum) % 2 == 1 && s - sum != 1)) {
        cout << -1 << endl;
        return ;
    }
    rep(i,1,ct[0]) cout << 0 << ' ';
    rep(i,1,ct[2]) cout << 2 << ' ';
    rep(i,1,ct[1]) cout << 1 << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}