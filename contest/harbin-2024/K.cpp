#include <bits/stdc++.h>
#define endl '\n'

#define rep(i, o, p) for(int i = o; i <= p; i ++ )

using namespace std;
typedef long long ll;
constexpr int maxn = 1e5+10;

ll n,m,sl[maxn],sr[maxn],ansrs[maxn],ansls[maxn];
struct Crop {
    int l, r;
    ll w;
    bool operator<(const Crop& rhs)const {
        return w > rhs.w;
    }
}a[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    rep(i,1,n) cin >> a[i].w >> a[i].l >> a[i].r;
    sort(a+1, a+1+n);
    rep(i,1,n) sl[i] = sl[i-1] + a[i].l;
    rep(i,1,n) sr[i] = sr[i-1] + a[i].r;
    rep(i,1,n) ansrs[i] = ansrs[i-1] + a[i].r * a[i].w;
    rep(i,1,n) ansls[i] = ansls[i-1] + a[i].l * a[i].w;
    ll ansi = 0;
    ll timec = sl[n];
    rep(i,1,n) ansi += a[i].l * a[i].w;
    int sep = -1;
    rep(i,1,n) {
        ll tmp = min(m - timec, 1ll * (a[i].r - a[i].l));
        ansi += a[i].w * tmp;
        timec += tmp;
        if(timec == m) {
            sep = i;
            break;
        }
    }
    ll ans = ansi;
    if(sep == -1) {
        cout << ans << endl;
        return 0;
    }
    ll ansl = 0;
    rep(i,1,n) {
        ansl += a[i].l * a[i].w;
    }
    rep(i,1,n) {
        ans = max(ans, ansl - a[i].l * a[i].w + (m - (sl[n] - a[i].l)) * a[i].w);
    }
    rep(i,sep+1,n) {
        // if(sr[i-1] <= m - a[i].l)
        //     continue;
        int l=0, r=i-1, mid, as;
        while(l <= r) {
            mid = (l + r) >> 1;
            if(m - (sl[n] - sl[mid]) + a[i].l - sr[mid-1] > 0) {
                as = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        ll asct = min(m - (sl[n] - sl[as]) + a[i].l - sr[as-1], 1ll * a[as].r);
        ll ict = m - (sl[n] - sl[as]) + a[i].l - sr[as-1] - asct;
        ans = max(ans, ansrs[as - 1] + (ansls[n] - ansls[as]) - a[i].l * a[i].w + asct * a[as].w + a[i].w * ict);
    }
    cout << ans << endl;
    return 0;
}