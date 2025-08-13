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
    vector<array<int,3>> a(n+5);
    rep(i,1,n) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin() + 1, a.begin() + 1 + n);
    int mx = 0;
    vector<int> out;
    rep(i,1,n) {
        if(a[i][1] <= mx) continue;
        out.push_back(a[i][2]);
        mx = a[i][1];
    }
    cout << out.size() << endl;
    for(auto i : out) cout << i << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}