#include <bits/stdc++.h>
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
int query(const vector<int>& a) {
    cout << "? " << a.size() << ' ';
    for(auto i : a) cout << i << ' ';
    cout << endl;
    int x; cin >> x;
    return x;
}
void answer(const vector<int>& a, int n) {
    cout << "! ";
    rep(i,1,2*n) cout << a[i] << ' ';
    cout << endl;
}
void solve() {
    int n; cin >> n;
    vector<int> a, ans(2*n+5);
    rep(i,1,2*n) {
        a.push_back(i);
        int ret = query(a);
        if(ret != 0) {
            ans[i] = ret;
            a.pop_back();
        }
    }
    vector<int> b;
    rep(i,1,2*n) {
        if(ans[i]) {
            b.push_back(i);
        }
    }
    rep(i,1,2*n) {
        if(!ans[i]) {
            b.push_back(i);
            ans[i] = query(b);
            b.pop_back();
        }
    }
    answer(ans, n);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}