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
    int n,q; cin >> n >> q;
    string s; cin >> s; s = ' ' + s;
    bool hasb = s.find('B') != string::npos;
    rep(i,1,q) {
        int x; cin >> x;
        if(!hasb) {
            cout << x << endl;
            continue;
        }
        int j = 1;
        int ct = 0;
        while(x) {
            if(s[j] == 'A') x--;
            else x /= 2;
            ct++;
            j = j % n + 1;
        }
        cout << ct << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}