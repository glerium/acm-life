#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int inf = 0x3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr (sizeof...(args) == 1) {
        return vector<T>(n, args...);
    } else {
        return vector(n, Vec<T>(args...));
    }
}
void solve() {
    int n,m; cin >> n >> m;
    vector<int> a(n+5);
    rep(i,1,n) {
        cin >> a[i];
        a[i]--;
    }
    auto s = Vec<int>(n+5, m+5, 0);
    rep(i,1,n) {
        s[i] = s[i-1];
        s[i][a[i]]++;
    }
    auto getCount = [&](int band, int l, int r) -> int {
        return s[r][band] - s[l-1][band];
    };
    vector<int> f((1<<m) + 10, inf);
    f[0] = 0;
    rep(i,0,(1<<m)-1) {
        int ct = 0;
        rep(j,0,m-1) {
            if(!(i & (1 << j))) continue;
            ct += getCount(j, 1, n);
        }
        rep(j,0,m-1) {
            if(i & (1 << j)) continue;
            int l = ct + 1, r = ct + getCount(j, 1, n);
            int len = r - l + 1, ori = getCount(j, l, r);
            int diff = len - ori;
            int newstt = i | (1 << j);
            f[newstt] = min(f[newstt], f[i] + diff);
        }
    }
    cout << f[(1 << m) - 1] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}