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
    string x, y; cin >> x >> y;
    int n = x.size();
    x = ' ' + x; y = ' ' + y;
    int ans = 0;
    int pos = 0;
    rep(i,1,n) {
        if(x[i] == y[i])
            ans += 2;
        else {
            pos = i;
            break;
        }
    }
    // cout << "pos=" << pos << ";ans=" << ans << endl;
    int diff = y[pos] - x[pos];
    if(diff >= 2 || diff == 0) {
        cout << ans << endl;
        return;
    }
    if(pos == n) {
        cout << ans + 1 << endl;
        return;
    }
    // diff == 1
    int ctx = 0, cty = 0;
    rep(i,pos+1,n) {
        if(x[i] == '9')
            ctx++;
        else
            break;
    }
    rep(i,pos+1,n) {
        if(y[i] == '0')
            cty++;
        else
            break;
    }
    cout << (ans + 1 + min(ctx, cty)) << endl;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
