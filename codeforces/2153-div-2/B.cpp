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
    int x,y,z; cin >> x >> y >> z;
    rep(i,0,30) {
        bool ok = false;
        rep(aa,0,1) {
            rep(bb,0,1) {
                rep(cc,0,1) {
                    if(((aa & bb) == (bool)(x & (1 << i))) && 
                       ((bb & cc) == (bool)(y & (1 << i))) &&
                       ((cc & aa) == (bool)(z & (1 << i)))) {
                        ok = true;
                    }
                }
            }
        }
        if(!ok) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}