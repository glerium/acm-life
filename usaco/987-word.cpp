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
    int cur = 0;
    vector<string> ans;
    string cline;
    rep(i,1,n) {
        string s; cin >> s;
        if(cur + s.size() > k) {
            ans.push_back(cline);
            cline = "";
            cur = 0;
        }
        cline += s + ' ';
        cur += s.size();
    }
    ans.push_back(cline);
    for(auto l : ans) {
        while(l.back() == ' ')
            l.pop_back();
        cout << l << endl;
    }
}
int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}