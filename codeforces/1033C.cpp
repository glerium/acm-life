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
    vector<int> ans(n+5, -1);  // 1: A; 0: B
    rep(i,1,n) {
        if(a[i] == n)
            ans[i] = 0;
    }
    function<int(int)> dfs = [&](int x) -> int {
        if(ans[x] != -1) return ans[x];
        int nowAns = 0;
        for(int i=x+a[x]; i<=n; i+=a[x]) {
            if(a[i] <= a[x]) continue;
            if(!dfs(i)) {
                nowAns = 1;
            }
        }
        for(int i=x-a[x]; i>=1; i-=a[x]) {
            if(a[i] <= a[x]) continue;
            if(!dfs(i)) {
                nowAns = 1;
            }
        }
        return ans[x] = nowAns;
    };
    rep(i,1,n) {
        if(dfs(i))
            cout << "A";
        else
            cout << "B";
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}