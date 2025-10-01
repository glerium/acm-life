#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e6+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
struct Event {
    int y;
    bool op;    // 0: edit, 1: query
    int l,r;
    int x,v;
    bool operator<(const Event& rhs) const {
        return y == rhs.y ? op < rhs.op : y < rhs.y;
    }
};
struct BIT {
    int f[maxn];
    int lowbit(int x) {
        return x & -x;
    }
    int query(int x) {
        if(x < 0) return x;
        int ans = 0;
        while(x) {
            ans += f[x];
            x -= lowbit(x);
        }
        return ans;
    }
    int queryRange(int l, int r) {
        return query(r) - query(l - 1);
    }
    void add(int x, int v) {
        while(x < 2e6+4) {
            f[x] += v;
            x += lowbit(x);
        }
    }
} bit;
void solve() {
    int n; cin >> n;
    vector<Event> evt;
    rep(i,1,n) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1e6 + 1;
        y1 += 1e6 + 1;
        x2 += 1e6 + 1;
        y2 += 1e6 + 1;
        if(x1 == x2) {  // vertical
            if(y1 > y2) swap(y1, y2);
            evt.push_back({y1, 0, -1, -1, x1, 1});
            evt.push_back({y2, 0, -1, -1, x1, -1});
        } else {        // horizontal
            if(x1 > x2) swap(x1, x2);
            evt.push_back({y1, 1, x1, x2, -1, -1});
        }
    }
    sort(evt.begin(), evt.end());
    ll ans = 0;
    for(auto &i : evt) {
        if(i.op == 0) {
            bit.add(i.x, i.v);
        } else {
            ans += bit.queryRange(i.l, i.r);
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}