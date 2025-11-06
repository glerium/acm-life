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
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    vector<vector<int>> fact(n+5);
    rep(i,1,n) {
        for(int j=i;j<=n;j+=i) {
            fact[j].push_back(i);
        }
    }
    vector<vector<int>> mul(n+5);
    rep(i,1,n) {
        for(auto j : fact[a[i]]) {
            mul[j].push_back(a[i]);
        }
    }
    rep(i,1,n) sort(mul[i].begin(), mul[i].end());
    auto b = a;
    sort(b.begin() + 1, b.begin() + 1 + n);
    int ans = 0;
    rep(i,1,n) {    // loop through gcd
        int all_gr_3i = b.begin() + 1 + n - lower_bound(b.begin() + 1, b.begin() + 1 + n, 4 * i + 1);
        int mul_gr_3i = mul[i].end() - lower_bound(mul[i].begin(), mul[i].end(), 4 * i + 1);
        
        int all_leq_3i = n - all_gr_3i;
        int mul_leq_3i = mul[i].size() - mul_gr_3i;

        if(all_leq_3i - mul_leq_3i > k) continue;
        // if(all_gr_3i - mul_gr_3i > k) continue;
        ans = max(ans, i);
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