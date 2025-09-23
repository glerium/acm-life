#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;

const int N = 2e6 + 10; 

int a[N];

struct node{
    int diff;
    int u; 
    int v;
}p[N];

bool cmp(node a, node b) { 
    return a.diff > b.diff;
}

int fa[N], mx[N], mi[N];

int find(int x) {
    if(x == fa[x]) return x;
    else return fa[x] = find(fa[x]);  
}

void marge(int x, int y) {
    int fx = find(x); 
    int fy = find(y);
    if(fx != fy) {
        fa[fy] = fx;
        mx[fx] = max(mx[fx], mx[fy]);
        mi[fx] = min(mi[fx], mi[fy]);
    }
}

void solve() {
    using ll = long long;
    int n;
    cin>>n;
    rep(i, 1, n) fa[i] = i;
    rep(i, 1, n) {
        cin >> a[i];
        mx[i] = mi[i] = a[i];
    }
    rep(i, 1, n - 1){
        cin >> p[i].u >> p[i].v;
        p[i].diff = a[p[i].u] - a[p[i].v];
        if(p[i].diff < 0) p[i].diff = - p[i].diff;
    }
    sort(p + 1, p + n, cmp);
    rep(i, 1, n - 1) { 
        int x = p[i].u, y = p[i].v;
        int fx = find(x), fy = find(y); 
        if(fx == fy) return ;
        int mx1 = mx[fx], mx2 = mx[fy];
        int mi1 = mi[fx], mi2 = mi[fy];
        if(mi1 > mi2) {
            swap(mi1, mi2);
            swap(mx1, mx2);
        }
        if(mx1 < mi2) {
            // cout << mi1 << " " << mx1 << " " << mi2 << " " << mx2 << '\n';
            // cout << x << " " << y << " " << p[i].diff << '\n';
            marge(fx, fy);
        }
    }
    long long ans = 0;
    rep(i, 1, n) {
        // cout << i << " " << fa[i] << '\n';
        if(fa[i] == i) ans += mx[i] - mi[i];
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    // while(t--) solve();
    solve();
    return 0;
}