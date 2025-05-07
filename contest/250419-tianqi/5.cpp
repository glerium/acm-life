#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr (sizeof...(args) == 1) {
        return vector<T>(n, args...);
    }else{
        return vector(n, Vec<T>(args...));
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int a[26] = {};
    rep(i,0,25) cin >> a[i];
    int ans = 0;
    int ct[26] = {};
    rep(i,0,s.size()-1) {
        ans += a[s[i] - 'a'];
        ct[s[i] - 'a']++;
    }
    rep(i,0,25) cout << ct[i] << " \n"[i == 25];
    // cout << endl;
    cout << ans << endl;
}