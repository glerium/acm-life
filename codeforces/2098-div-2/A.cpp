#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    string s; cin >> s;
    vector<int> vec;
    for(auto i : s)
        vec.push_back(i - '0');
    string ans;
    rep(i,1,10) {
        int cur = 10 - i;
        auto fn = vec.end();
        for(auto it = vec.begin(); it != vec.end(); it++) {
            if(*it >= cur && (fn == vec.end() || *it < *fn)) {
                fn = it;
            }
        }
        ans += '0' + *fn;
        vec.erase(fn);
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
