#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 4e5+10;
constexpr ll mod = 998244353;
int n,q,m,a[maxn],orict[maxn];
map<int,int> mp;
map<int,int> rmp;
struct Query {
    int x, v;
}qry[maxn];
struct SegmentTree {
    ll cnt[maxn << 2];
    ll sum[maxn << 2];
    void pushup(int x) {
        sum[x] = sum[x<<1]+sum[x<<1|1];
        cnt[x] = cnt[x<<1]+cnt[x<<1|1];
    }
    void build(int x, int l, int r) {
        if(l == r) {
            cnt[x] = orict[l];
            sum[x] = cnt[x] * rmp[l];
            return;
        }
        int mid = (l+r) >> 1;
        build(x << 1, l, mid);
        build(x << 1 | 1, mid + 1, r);
        pushup(x);
    }
    void add(int x, int id, int l, int r, int cnt_, int val_) {
        if(id > r || id < l) return;
        if(l == r) {
            cnt[x] += cnt_;
            sum[x] += cnt_ * val_;
            return;
        }
        int mid = (l + r) >> 1;
        add(x << 1, id, l, mid, cnt_, val_);
        add(x << 1 | 1, id, mid+1, r, cnt_, val_);
        pushup(x);
    }
    ll query_cnt(int x, int l, int r, int L, int R) {
        if(l > R || r < L) return 0;
        if(L <= l && r <= R) return cnt[x];
        int mid = (l + r) >> 1;
        return query_cnt(x<<1, l, mid, L, R) + query_cnt(x<<1|1, mid+1, r, L, R);
    }
    ll query_sum(int x, int l, int r, int L, int R) {
        if(l > R || r < L) return 0;
        if(L <= l && r <= R) return sum[x];
        int mid = (l + r) >> 1;
        return query_sum(x<<1, l, mid, L, R) + query_sum(x<<1|1, mid+1, r, L, R);
    }
}tree;
void lisan() {
    vector<int> vec;
    for(int i=1;i<=n;i++) vec.push_back(a[i]);
    for(int i=1;i<=q;i++) vec.push_back(qry[i].v);
    sort(vec.begin(), vec.end());
    for(auto i : vec) {
        if(!mp.count(i)) {
            mp[i] = ++m;
            rmp[mp[i]] = i;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    rep(i,1,n) cin >> a[i];
    rep(i,1,q) cin >> qry[i].x >> qry[i].v;
    lisan();
    int pos_begin = m+1;
    rep(i,1,m) {
        if(rmp[i] > 0) {
            pos_begin = i;
            break;
        }
    }

    int pos_cnt = 0;
    ll neg_sum = 0;
    rep(i,1,n) pos_cnt += (a[i] > 0);
    rep(i,1,n) orict[mp[a[i]]]++;
    rep(i,1,n) {
        if(a[i] < 0)
            neg_sum += -a[i];
    }
    tree.build(1, 1, m);
            // rep(i,1,m) {
            //     cout << '%' << tree.query_cnt(1, 1, m, i, i) << ' ' << tree.query_sum(1, 1, m, i, i) << endl;
            // }
    rep(i,1,q) {
        tree.add(1, mp[a[qry[i].x]], 1, m, -1, a[qry[i].x]);
        tree.add(1, mp[qry[i].v], 1, m, 1, qry[i].v);
        a[qry[i].x] = qry[i].v;

        pos_cnt = tree.query_cnt(1, 1, m, pos_begin, m);
        neg_sum = -tree.query_sum(1, 1, m, 1, pos_begin - 1);
            // rep(i,1,m) {
            //     cout << '%' << tree.query_cnt(1, 1, m, i, i) << ' ' << tree.query_sum(1, 1, m, i, i) << endl;
            // }
        int l=pos_begin, r=m, mid, ans = -1;
        while(l <= r) {
            mid = (l + r) >> 1;
            // cout << ":" << tree.query_sum(1, 1, m, pos_begin, mid) << endl;
            if(tree.query_sum(1, 1, m, pos_begin, mid) > neg_sum) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        if(ans == -1) cout << pos_cnt + 1 << endl;
        else {
            ll left_sum = tree.query_sum(1, 1, m, pos_begin, ans - 1);
            ll mid_cnt = (neg_sum - left_sum) / rmp[ans];
            ll right_cnt = tree.query_cnt(1, 1, m, ans, m);
            int ans_min = right_cnt - mid_cnt;
            cout << pos_cnt - ans_min + 1 << endl;
        }
    }
    return 0;
}
