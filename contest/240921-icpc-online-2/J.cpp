#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 1e5+10;
struct Good {
    ll w, v, c;
    bool operator<(const Good& rhs)const{
        return w*rhs.c > c*rhs.w;
    }
}a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i].w >> a[i].v >> a[i].c;
    sort(a+1, a+1+n);
    ll ans = 0, W = 0;
    for(int i=1;i<=n;i++) {
        ans += a[i].v - a[i].c * W;
        W += a[i].w;
    }
    cout << ans << endl;
    return 0;
}