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
struct Task {
    ll t,b;
    bool operator<(const Task& rhs) const {
        if(t + b != rhs.t + rhs.b) return t + b > rhs.t + rhs.b;
        return t > rhs.t;
    }
};
bool cmp(const Task& lhs, const Task& rhs) {
    return lhs.t < rhs.t;
}
void solve() {
    ll n,T; cin >> n >> T;
    vector<Task> a, b;
    rep(i,1,n) {
        ll x, y; cin >> x >> y;
        if(y >= 0) {
            a.push_back({x, y});
        } else {
            b.push_back({x, y});
        }
    }
    sort(a.begin(), a.end(), cmp);
    ll now = T;
    for(auto task : a) {
        if(now <= task.t || now <= 0) {
            cout << "-1s" << endl;
            return;
        }
        now += task.b;
    }
    sort(b.begin(), b.end());
    for(auto task : b) {
        if(now <= task.t || now <= 0) {
            cout << "-1s" << endl;
            return;
        }
        now += task.b;
    }
    if(now <= 0)
        cout << "-1s" << endl;
    else
        cout << "+1s" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}