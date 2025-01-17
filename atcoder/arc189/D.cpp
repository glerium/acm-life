#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 5e5+10;
constexpr ll mod = 998244353;
int n, a[maxn];
ll ans[maxn], s[maxn];
struct SegTree {
    int mx[maxn << 2];
    void pushup(int x) {
        mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
    }
    void build(int x, int l, int r) {
        if(l == r) {
            mx[x] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(x << 1, l, mid);
        build(x << 1 | 1, mid+1, r);
        pushup(x);
    }
    int max_right(int x, int l, int r, int L, ll v) {
        if(r < L) return -1;
        if(L <= l) {
            if(mx[x] < v) return -1;
            if(l == r) return l;
        }
        int mid = l + r >> 1;
        int ret = max_right(x << 1, l, mid, L, v);
        if(ret != -1) return ret;
        return max_right(x << 1 | 1, mid+1, r, L, v);
    }
    int min_left(int x, int l, int r, int R, ll v) {
        if(l > R) return -1;
        if(R >= r) {
            if(mx[x] < v) return -1;
            if(l == r) return l;
        }
        int mid = l + r >> 1;
        int ret = min_left(x << 1 | 1, mid+1, r, R, v);
        if(ret != -1) return ret;
        return min_left(x << 1, l, mid, R, v);
    }
    int query(int x, int l, int r, int L, int R) {
        if(l > R || r < L) return 0;
        if(L <= l && r <= R) return mx[x];
        int mid = l + r >> 1;
        return max(
            query(x << 1, l, mid, L, R),
            query(x << 1 | 1, mid+1, r, L, R)
        );
    }
}tr;
signed main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) s[i] = s[i-1] + a[i];
    tr.build(1, 1, n);
    rep(k,1,n) {
        int kl=k,kr=k;
        ll kv = a[k];
        while(kl != 1 || kr != n) {
            int l=1, r=kl-1, ansl=-1;
            if(l <= r) {
                ansl = tr.min_left(1, 1, n, kl-1, kv);
                // cout << kl-1 << ' ' << kv << ' ' << ansl << endl;
                if(ansl != kl-1) {
                    if(ansl == -1) ansl = 1;
                    else ansl++;
                    kv += s[kl - 1] - s[ansl - 1];
                    kl = ansl;
                }else ansl = -1;
            }
            // cout << k << endl;
            // cout << kl << ' ' << kr << endl;

            l = kr + 1, r = n;
            int ansr = -1;
            if(l <= r) {
                ansr = tr.max_right(1, 1, n, kr+1, kv);
                // cout << kr+1 << ' ' << kv << ' ' << ansr << endl;
                if(ansr != kr+1) {
                    if(ansr == -1) ansr = n;
                    else ansr--;
                    // kr+1, ansr
                    kv += s[ansr] - s[kr];
                    kr = ansr;
                }else ansr = -1;
            }
            if(ansl == -1 && ansr == -1) {
                break;
            }
            // cout << kl << ' ' << kr << endl;
        }
        ans[k] = kv;
    }
    rep(i,1,n) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
