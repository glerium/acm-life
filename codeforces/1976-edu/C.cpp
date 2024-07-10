#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
struct Person {
    int a,b,i;
    bool operator<(const Person& rhs) const {
        return a - b > rhs.a - rhs.b;
    }
};
void solve() {
    int n,m; cin >> n >> m;
    Person p[n+m+5];
    rep(i,1,n+m+1) cin >> p[i].a;
    rep(i,1,n+m+1) cin >> p[i].b;
    ll ans[n+m+5] = {};
    rep(i,1,n+m+1) 
        ans[i] = ans[i-1] + max(p[i].a, p[i].b);
    int cta[n+m+5] = {}, ctb[n+m+5] = {};
    rep(i,1,n+m+1)
        cta[i] = cta[i-1] + (p[i].a > p[i].b);
    rep(i,1,n+m+1)
        ctb[i] = ctb[i-1] + (p[i].a < p[i].b);
    auto check1 = [&](int x, int i) {
        int ctta = cta[x] - (i <= x && p[i].a > p[i].b);
        return ctta == n;
    };
    auto check2 = [&](int x, int i) {
        int cttb = ctb[x] - (i <= x && p[i].a < p[i].b);
        return cttb == m;
    };
    rep(i,1,n+m+1) {
        int tmp[] = {p[i].a, p[i].b};
        if(cta[n+m+1] - (p[i].a < p[i].b) == n && ctb[n+m+1] - (p[i].a > p[i].b) == m) {
            cout << ans[n+m+1] - tmp[p[i].a > p[i].b] << ' ';
        }else {
            cout << -1 << ' ';
        }
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
