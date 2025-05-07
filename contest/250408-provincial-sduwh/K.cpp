#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
const int maxn = 8e5+10;
using namespace std;
struct tree {
    int a[maxn],w[maxn*4];
    void pushup(const int u) {
        w[u]=max(w[u*2],w[u*2+1]);
    }
    void build(const int u,int L,int R)
    {
        if(L==R)
        {
            w[u]=a[L];
            return;
        }
        int M=(L+R)/2;
        build(u*2,L,M);build(u*2+1,M+1,R);
        pushup(u);
    }
    // ll query1(int u,int L,int R,int p)
    // {
    //     if(L==R)return w[u];
    //     else
    //     {
    //         int M=(L+R)/2;
    //         if(M>=p)
    //             return query1(u*2,L,M,p);
    //         else 
    //             return query1(u*2+1,M+1,R,p);
    //     }
    // }
    void update1(int u,int L,int R,int p,int x)
    {
        if(L==R)w[u]=x;
        else
        {
            int M=(L+R)/2;
            if(M>=p) update1(u*2,L,M,p,x);
            else     update1(u*2+1,M+1,R,p,x);
            pushup(u);
        }
    }
    bool Inrange(int L,int R,int l,int r)
    {
        return (l<=L)&&(R<=r);
    }
    bool Outofrange(int L,int R,int l,int r)
    {
        return (L>r)||(R<l);
    }
    pair<int, int> query(int u,int L,int R,int l,int r)
    {
        if(L == R && Inrange(L, R, l, r)) return {a[u], L};
        if(Outofrange(L, R, l, r)) return {0, 0};
        int M=(L+R)/2;
        pair<int, int> ls = query(u*2,L,M,l,r), rs = query(u*2+1,M+1,R,l,r);
        if(ls.first > rs.first) return ls;
        else return rs;
    }
}t1, t2;


int f[maxn] = {};

void solve() {
    int n, q; 
    cin >> n >> q;
    int hmax = -1;
    rep(i, 1, n) cin >> t1.a[i], hmax = max(hmax, t1.a[i]);
    t2.build(1, 1, hmax);
    for(int i = n; i >= 1; i --) {
        // q(i + 1, n) 
        if(i == n) f[i] = 1;
        else f[i] = t2.query(1, 1, hmax, t1.a[i] + 1, hmax).first + 1;
        t2.update1(1, 1, hmax, t1.a[i], f[i]);
    }
    // rep(i, 1, n) cout << f[i] << " ";
    // cout <<'\n';
    t1.build(1, 1, n);
    rep(i, 1, q) {
        int l, r;
        cin >> l >> r;
        int tmp = t1.query(1, 1, n, l + 1, r).second;
     //   cout << tmp << " ";
        cout << max(f[tmp], f[r])  - 1 << '\n';
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}