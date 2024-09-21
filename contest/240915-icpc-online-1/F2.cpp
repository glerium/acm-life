#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
int n, a[maxn];

struct Node {
    int l,r;
    int val;
    int size() {return r-l+1;}
    bool operator<(const Node& rhs)const {
        if(val != rhs.val)
            return val > rhs.val;
        return l > rhs.l;
    }
};

struct BCJ {
    int fa[maxn],sz[maxn],val[maxn],l[maxn],r[maxn];
    void init(int n) {
        rep(i,0,n+5) {
            fa[i] = i;
            sz[i] = 1;
            val[i] = a[i];
            l[i] = r[i] = i;
        }
    }
    int query(int x) {
        if(fa[x] == x) return x;
        return fa[x] = query(fa[x]);
    }
    void merge(int x, int y, int v) {
        x = query(x);
        y = query(y);
        fa[x] = y;
        sz[y] += sz[x];
        val[y] = v;
        l[y] = min(l[y], l[x]);
        r[y] = max(r[y], r[x]);
    }
}t;

void lisan() {
    int b[n+5];
    memcpy(b, a, sizeof(b));
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

int getcur(int i) {
    return t.val[t.query(i)];
}

void solve() {
    cin >> n;
    memset(a, 0, (n+5)*sizeof(int));
    rep(i,1,n) cin>>a[i];
    // lisan();
    t.init(n);
    priority_queue<Node> q;
    rep(i,1,n)
        q.push({i,i,a[i]});
    ll ans = 0;
    while(!q.empty()) {
        Node now = q.top(); q.pop();
        // cout << now.l << ' ' << now.r << endl;
        if(t.sz[t.query(now.l)] != now.size())
            continue;
        // cout << "ok" << endl;
        if(getcur(now.l-1) == getcur(now.l)) {
            t.merge(now.l-1, now.l, now.val);
            q.push({t.l[t.query(now.l-1)], now.r, now.val});
            continue;
        }else if(getcur(now.r+1) == getcur(now.r)) {
            t.merge(now.r+1, now.r, now.val);
            q.push({now.l, t.r[t.query(now.r+1)], now.val});
            continue;
        }
        if(now.l == 1 && now.r == n)
            break;
        if(now.l == 1 && t.r[t.query(now.r+1)] <= n) {
            t.merge(now.r+1, now.r, getcur(now.r+1));
            q.push({now.l, t.r[t.query(now.r+1)], getcur(now.r+1)});
        }else if(now.r == n && t.l[t.query(now.l)-1] >= 1) {
            t.merge(now.l, now.l-1, getcur(now.l-1));
            q.push({t.l[t.query(now.l-1)], now.r, getcur(now.l-1)});
        }else {
            if(getcur(now.l-1) < getcur(now.r+1)) {
                t.merge(now.l, now.l-1, getcur(now.l-1));
                q.push({t.l[t.query(now.l-1)], now.r, getcur(now.l-1)});
            }else{
                t.merge(now.r, now.r+1, getcur(now.r+1));
                q.push({now.l, t.r[t.query(now.r+1)], getcur(now.r+1)});
            }
        }
        // cout << now.l << ' ' << now.r << ' ' << now.size() << endl;
        ans += now.size();
    }
    cout << ans << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}