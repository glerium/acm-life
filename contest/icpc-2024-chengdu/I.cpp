#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100010;
int n,m;
int a[N];
struct Tree{
    int l,r;
    ll sum;
    ll lz;
}tr[N*4];
void pushup(int p) {
    tr[p].sum=tr[p<<1].sum+tr[p<<1|1].sum;
}
void pushdown(int p)
{
    auto &root=tr[p],&left=tr[p<<1],&right=tr[p<<1|1];
    if(root.lz) {
        left.lz=root.lz;
        left.sum+=(ll)(left.r-left.l+1)*root.lz;
        right.lz+=root.lz;
        right.sum+=(ll)(right.r-right.l+1)*root.lz;
        root.lz=0;
    }
}
void build(int p,int l,int r) {
    tr[p]={l,r};
    if(l==r) {
        tr[p]={l,r,a[r],0};
        return;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    pushup(p);
}
void modify(int p,int l,int r,int v) {
    if(tr[p].l>=l&&tr[p].r<=r) {
        tr[p].sum+=(tr[p].r-tr[p].l+1)*v;
        tr[p].lz+=v;
        return;
    }
    pushdown(p);
    int mid=(tr[p].l+tr[p].r)/2;
    if(l<=mid)modify(p<<1,l,r,v);
    if(p>mid)modify(p<<1|1,l,r,v);
    pushup(p);
}
ll query(int p,int l,int r) {
    if(tr[p].l>=l&&tr[p].r<=r) {
        return tr[p].sum;
    }
    pushdown(p);
    int mid=(tr[p].l+tr[p].r)/2;
    ll res=0;
    if(l<=mid)res+=query(p<<1,l,r);
    if(r>mid)res+=query(p<<1|1,l,r);
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
}