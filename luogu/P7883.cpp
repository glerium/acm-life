#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
struct Point {
    ll x,y;
};
bool cmpx(const Point& lhs, const Point& rhs) {
    return lhs.x < rhs.x;

}
bool cmpy(const Point& lhs, const Point& rhs) {
    return lhs.y < rhs.y;
}
ll dist(const Point& lhs, const Point& rhs) {
    return (lhs.x - rhs.x) * (lhs.x - rhs.x) + (lhs.y - rhs.y) * (lhs.y - rhs.y);
}
void solve() {
    int n; cin >> n;
    vector<Point> a(n+5);
    rep(i,1,n) cin >> a[i].x >> a[i].y;
    sort(a.begin() + 1, a.begin() + 1 + n, cmpx);
    function<ll(int,int)> query = [&](int l, int r) -> ll {
        if(l == r) return inf;
        if(l + 1 == r) return dist(a[l], a[r]);
        int mid = l + r >> 1;
        ll d = min(query(l, mid), query(mid+1, r));
        vector<Point> vec;
        rep(i,l,r) {
            if(abs(a[i].x - a[mid].x) * abs(a[i].x - a[mid].x) <= d)
                vec.push_back(a[i]);
        }
        sort(vec.begin(), vec.end(), cmpy);
        rep(i,0,vec.size()-1) {
            for(int j = i + 1; j < vec.size() && (vec[j].y - vec[i].y) * (vec[j].y - vec[i].y) < d; j++) {
                ll now = dist(vec[i], vec[j]);
                d = min(d, now);
            }
        }
        return d;
    };
    ll ans = query(1, n);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}