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
    int n,k; cin >> n >> k;
    string s; cin >> s; s = ' ' + s;
    int ct = 0;
    rep(i,1,n) {
        bool ok = false;
        rep(j,max(1,i-k+1),i-1) {
            if(s[j] == '1') {
                ok = true;
            }
        }
        if(!ok && s[i] == '1') {
            ct++;
        }
    }
    cout << ct << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}