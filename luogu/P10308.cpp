#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 3e5+10;
constexpr ll mod = 1e9+7;
int n,q,a[maxn];
struct BIT {
    int f[maxn];
    int lowbit(int x) {
        return x & -x;
    }
    void add(int k, int x) {
        while(k <= n) {
            f[k] += x;
            k += lowbit(k);
        }
    }
    int query(int k) {
        int ans = 0;
        while(k) {
            ans += f[k];
            k -= lowbit(k);
        }
        return ans;
    }
} bit;
void solve() {
    cin >> n >> q;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        if(a[i]) bit.add(i, 1);
    }
    auto fnd = [&]() -> int {
        int l=1,r=n,mid,ans=0;
        while(l<=r) {
            mid=(l+r)>>1;
            if(!bit.query(mid)) {
                ans = mid;
                l = mid+1;
            }else r = mid-1;
        }
        return ans;
    };
    
    while(q--) {
        int x,y; cin>>x>>y;
        bit.add(x, -bool(a[x])+bool(y));
        a[x] = y;
        int tmp = n - fnd();
        if(tmp <= 1) cout << 1 << endl;
        else {
            int ans = 1;
            while(ans < tmp) ans *= 2;
            cout << ans << endl;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
