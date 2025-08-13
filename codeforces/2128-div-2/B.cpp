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
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    string ans;
    int ct = 0, l = 1, r = n;
    while(ct < n) {
        if(ct % 2 == 0) {
            if(a[l] < a[r])
                ans += 'L';
            else
                ans += 'R';
        } else {
            if(a[l] > a[r])
                ans += 'L';
            else
                ans += 'R';
        }
        if(ans[ans.size() - 1] == 'L') l++;
        else r--;
        ct++;
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