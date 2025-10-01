#include <bits/stdc++.h>
#define double long double
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
constexpr double eps = 1e-10;
int cmp(double x) {
    if(abs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}
void solve() {
    int n,k,x; cin >> n >> k >> x;
    int K = k;
    vector<double> a(n+5);
    rep(i,1,n) {
        int x; cin >> x;
        a[i] = x;
    }
    if(k <= 100 * n) {
        priority_queue<double> q;
        rep(i,1,n) q.push(a[i]);
        while(k > 0) {
            double now = q.top();
            q.pop();
            q.push(now / 2);
            q.push(now / 2);
            k--;
        }
        while(x > 1) {
            q.pop();
            x--;
        }
        cout << q.top() << endl;
        return;
    }
    vector<double> b(1);
    int mn = *min_element(a.begin() + 1, a.begin() + 1 + n);
    rep(i,1,n) {
        int ct = 1;
        double now = a[i];
        while(cmp(mn * 2 - now) != 1) {
            now /= 2;
            ct *= 2;
        }
        k -= ct - 1;
        rep(j,1,ct)
            b.push_back(now);
    }
    int m = b.size() - 1;
    ll nowStep = m, totalStep = 0;
    double frac = 1;
    while(totalStep + nowStep < k) {
        totalStep += nowStep;
        nowStep *= 2;
        frac /= 2;
    }
    k -= totalStep;
    ll tmp = nowStep / m;

    vector<pair<double,ll>> fin;
    for(int i=m; i>=1; i--) {
        if(k <= 0) {
            fin.emplace_back(b[i] * frac, tmp);
        } else {
            if(tmp < k) {
                fin.emplace_back(b[i] * frac / 2, tmp * 2);
            } else {
                fin.emplace_back(b[i] * frac / 2, k * 2);
                if(tmp != k)
                    fin.emplace_back(b[i] * frac, tmp - k);
            }
            k -= tmp;
        }
    }
    sort(fin.begin(), fin.end(), greater<>());
    for(auto &[v, ct] : fin) {
        x -= ct;
        if(x <= 0) {
            cout << v << endl;
            return;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    cout << fixed << setprecision(20);
    while(t--) solve();
    return 0;
}