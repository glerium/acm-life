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
struct String {
    string s;
    string p;
    bool operator<(const String& rhs) const {
        return s < rhs.s;
    }
};
void solve() {
    int n,q; cin >> n >> q;
    string s; cin >> s; s = ' ' + s;
    char x[q+5] = {}, y[q+5] = {};
    rep(i,1,q) cin >> x[i] >> y[i];
    map<int,int> mp;
    rep(i,1,q) {
        mp[x[i] * 256 + y[i]]++;
    }
    auto check = [&](char x, char y) -> bool {
        if(x == y) return true;
        int key = x * 256 + y;
        if(mp[key] > 0) {
            mp[key]--;
            return true;
        }
        
    };
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
