#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 1e9+7;
constexpr ll inf = 0x3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
ll ct[100] = {};
auto f = Vec<ll>(107, 3007, 0);
void init() {
    f[0][0] = 1;
    rep(i,1,100) {
        rep(j,1,3000) {
            rep(k,1,26) {
                if(j - k < 0) continue;
                f[i][j] += f[i - 1][j - k];
                f[i][j] %= mod;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin>>t;
    while(t--) {
        string s; cin >> s;
        int sum = 0;
        for(auto i : s) sum += i - 'a' + 1;
        cout << (f[s.size()][sum] - 1 + mod) % mod << endl;
    }
    return 0;
}