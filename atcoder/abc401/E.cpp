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
struct BCJ {
    vector<int> fa, sz;
    void init(int x) {
        fa.resize(x+5);
        sz.resize(x+5);
        rep(i,1,x) fa[i] = i;
        rep(i,1,x) sz[i] = 1;
    }
    int find(int x) {
        if(fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return;
        fa[x] = y;
        sz[y] += sz[x];
    }
} bcj;
void solve() {
    int n,m; cin >> n >> m;
    bcj.init(n+5);
    vector<vector<int>> a(n+5);
    rep(i,1,m) {
        int x,y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    set<int> st;
    for(auto i : a[1])
        st.insert(i);
    cout << st.size() << endl;
    rep(i,2,n) {
        if(st.count(i)) st.erase(i);
        for(auto j : a[i]) {
            if(j > i)
                st.insert(j);
            else if(j < i)
                bcj.merge(i, j);
        }
        bool ok = bcj.sz[bcj.find(1)] == i;
        if(!ok) cout << -1 << endl;
        else cout << st.size() << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}