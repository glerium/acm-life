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
    int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    string s_ = s;
    
    string t = " ";
    set<int> st[2];
    rep(i,1,2*n) st[s[i]-'A'].insert(i);
    rep(i,1,n) t += "AB";
    ll ans0 = 0;
    rep(i,1,2*n) {
        int type = t[i] - 'A';
        if(s[i] == t[i]) {
            st[type].erase(i);
            continue;
        }
        int fnd = *st[type].begin();
        swap(s[i], s[fnd]);
        ans0 += fnd - i;
        st[type].erase(fnd);
        st[!type].erase(i);
    }

    t = " ";
    s = s_;
    rep(i,1,n) t += "BA";
    rep(i,1,2*n) st[s[i]-'A'].insert(i);
    ll ans1 = 0;
    rep(i,1,2*n) {
        int type = t[i] - 'A';
        if(s[i] == t[i]) {
            st[type].erase(i);
            continue;
        }
        int fnd = *st[type].begin();
        swap(s[i], s[fnd]);
        ans1 += fnd - i;
        st[type].erase(fnd);
        st[!type].erase(i);
    }
    cout << min(ans0, ans1) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}