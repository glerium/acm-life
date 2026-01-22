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
    vector<int> b(n+5);
    rep(i,2,n) cin >> b[i];
    rep(i,1,n) {
        set<int> st;
        vector<int> vec;
        int last = i;
        st.insert(i);
        vec.push_back(i);
        bool flag = true;
        rep(j,2,n) {
            int cur = b[j] - last;
            if(cur > n || cur < 1) {
                flag = false;
                break;
            }
            st.insert(cur);
            vec.push_back(cur);
            last = cur;
        }
        if(flag && st.size() == n) {
            for(int i = 0; i < n; i++) {
                cout << vec[i];
                if(i != n - 1) cout << ' ';
            }
            return;
        }
    }
}
int main() {
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}