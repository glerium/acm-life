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
struct Person {
    int x,y,z;
    bool del = false;
    bool operator<(const Person& rhs) const {
        return z < rhs.z;
    }
    bool operator>(const Person& rhs) const {
        return z > rhs.z;
    }
};
void solve() {
    ll n,m,k; cin >> n >> m >> k;
    vector<int> a(m+5);
    multiset<int> st;
    rep(i,1,m) cin >> a[i];
    rep(i,1,m) st.insert(a[i]);

    vector<Person> p(n+5);
    rep(i,1,n) cin >> p[i].x >> p[i].y >> p[i].z;
    rep(i,1,n) {
        k -= p[i].y;
        p[i].z -= p[i].y;
    }

    sort(p.begin() + 1, p.begin() + 1 + n, greater<>());
    rep(i,1,n) {
        auto fnd = st.lower_bound(p[i].x);
        if(fnd != st.end()) {
            p[i].del = true;
            st.erase(fnd);
        }
    }

    sort(p.begin() + 1, p.begin() + 1 + n);
    int ct = 0;
    rep(i,1,n) {
        if(p[i].del) {
            ct++;
            continue;
        }
        if(k >= p[i].z) {
            k -= p[i].z;
            ct ++;
        }
    }
    cout << ct << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}