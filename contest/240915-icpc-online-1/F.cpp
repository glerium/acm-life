#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
int n,a[maxn];
void lisan() {
    int b[maxn];
    memcpy(b, a, sizeof(a));
    sort(b+1,b+1+n);
    map<int,int> mp;
    int ct = 0;
    for(int i=1;i<=n;i++) {
        if(!mp.count(b[i]))
        mp[b[i]] = ++ct;
    }
    for(int i=1;i<=n;i++)
        a[i] = mp[a[i]];
}

// struct BIT {
//     int a[maxn];
//     int lowbit(int x) {
//         return x & -x;
//     }
//     void add(int x, int v) {
//         while(x <= n) {
//             a[x] += v;
//             x += lowbit(x);
//         }
//     }
//     int query(int x) {
//         int ans = 0;
//         ans += a[x];
//         x -= lowbit(x);
//         return ans;
//     }
// }t;

struct Item {
    int i;
    int x;
};

void solve(){
    cin >> n;
    rep(i,1,n) cin >> a[i];
    lisan();
    bool v[n+5] = {};
    ll fnl = 0;
    for(int i=1;i<=n;i++) {
        if(!v[a[i]])
            fnl += i-1;
        v[a[i]] = true;
    }
    int ctl[n+5]={}, ctr[n+5]={};
    Item vec[n+5];
    int tl=0;
    for(int i=1;i<=n;i++) {
        if(tl == 0) {
            vec[++tl] = {i, a[i]};
            continue;
        }
        int l=1, r=tl, mid, ans = -1;
        while(l <= r) {
            mid = (l+r)>>1;
            if(vec[mid].x <= a[i]) {
                ans = mid;
                r = mid - 1;
            }else{
                r = mid - 1;
            }
        }
        if(ans == -1)
            continue;
        ctl[i] = i - vec[ans].i - 1;
        while(vec[tl].x <= a[i] && tl)
            tl--;
    }

    for(int i=n;i>=1;i--) {
        if(tl == 0) {
            vec[++tl] = {i, a[i]};
            continue;
        }
        int l=1, r=tl, mid, ans=-1;
        while(l <= r) {
            mid = (l+r)>>1;
            if(vec[mid].x <= a[i]) {
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        if(ans == -1) continue;
        ctr[i] = vec[ans].i - i - 1;
        while(vec[tl].x <= a[i] && tl)
            tl--;
        vec[++tl] = {i, a[i]};
    }
    cout << fnl << endl;
}

int main() {
    ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}