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
    int n; string s;
    cin >> n >> s;
    map<char, set<int>> mp;
    s = ' ' + s;
    rep(i,1,n) mp[s[i]].insert(i);
    rep(i,'a','z') {
        if(mp[i].size() < 2) continue;
        mp[i].erase(1);
        mp[i].erase(n);
        if(mp[i].size() > 0) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
