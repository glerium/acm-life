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
vector<vector<int>> fact;
struct Number {
    int x,y;
    bool operator<(const Number& rhs) const {
        return x < rhs.x;
    }
};

void solve() {
    int n; cin >> n;
    vector<Number> a(n+5);
    rep(i,1,n) cin >> a[i].x;
    rep(i,1,n) cin >> a[i].y;
    vector<int> odd;
    rep(i,1,n) {
        if(a[i].x % 2 == 1) {
            odd.push_back(a[i].y);
        }
    }
    sort(odd.begin(), odd.end());
    ll ans = LLONG_MAX;
    if(odd.size() >= 2) {
        ans = min(ans, ll(odd[0] + odd[1]));
    }
    sort(a.begin() + 1, a.begin() + 1 + n);
    map<int,int> ct;
    rep(i,1,n) {
        for(auto j : fact[a[i].x]) {
            ct[j] ++;
        }
    }
    for(auto [k, v] : ct) {
        if(v >= 2) {
            cout << 0 << endl;
            return;
        }
    }
    vector<int> val(n+5), w(n+5);
    rep(i,1,n) {
        val[i] = a[i].x;
        w[i] = a[i].y;
    }
    // v <= 1
    map<int,int> st;
    for(auto [k, v] : ct) {
        int now = 1;
        while(now <= n) {
            int target = (a[now].x + k - 1) / k * k;
            st[target] += v;
            auto fnd = upper_bound(val.begin() + now, val.begin() + n + 1, target);
            now = fnd - val.begin();
        }
    }
    rep(i,1,n) {
        for(auto k : fact[val[i]]) {
            int now = 1;
            while(now <= n) {
                int target = (a[now].x + k - 1) / k * k;
                st[target]--;
                if(st[target] == 0) {
                    st.erase(target);
                }
                auto fnd = upper_bound(val.begin() + now, val.begin() + n + 1, target);
                now = fnd - val.begin();
            }
        }
        
        if(!st.empty()) {
            auto fnd = st.upper_bound(val[i]);
            ans = min(ans, 1ll * w[i] * (fnd->first - val[i]));
        }
        
        for(auto k : fact[val[i]]) {
            int now = 1;
            while(now <= n) {
                int target = (a[now].x + k - 1) / k * k;
                st[target]++;
                if(st[target] == 0) {
                    st.erase(target);
                }
                auto fnd = upper_bound(val.begin() + now, val.begin() + n + 1, target);
                now = fnd - val.begin();
            }
        }
    }
    cout << ans << endl;
}
void init() {
    bitset<maxn> isprime;
    isprime.set();
    isprime[1] = false;
    fact.resize(maxn);
    rep(i,2,2e5) {
        if(isprime[i]) {
            fact[i].push_back(i);
            for(int j=i+i;j<=2e5;j+=i) {
                fact[j].push_back(i);
                isprime[j] = false;
            }
        }
    }
}
int main() {
    init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}