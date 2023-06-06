#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m,a[maxn],ct;
struct Node {
    int l,r;
    int s,lazy;
}t[maxn<<2];
inline int ls(int p) {return p<<1;}
inline int rs(int p) {return p<<1|1;}
void pushup(int p) {
    t[p].s=t[ls(p)].s+t[rs(p)].s;
}
void pushdown(int p) {
    t[ls(p)].lazy+=t[p].lazy;
    t[ls(p)].s+=t[p].lazy*(t[ls(p)].r-t[ls(p)].l+1);
    t[rs(p)].lazy+=t[p].lazy;
    t[rs(p)].s+=t[p].lazy*(t[rs(p)].r-t[rs(p)].l+1);
}
void build(int p,int l,int r) {
    int mid=l+r>>1;
    if(l==r) {
        t[p]=(Node){l,r,a[l]};
        return;
    }
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    pushup(p);
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    for(int i=1;i<=m;i++) {
        int op,x,y,k;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1) {
            scanf("%d",&k);

        }else{

        }
    }
}