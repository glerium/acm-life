#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int maxn=1e3+10;
int n,d,p[maxn],ct;
struct Line{
    long double l,r;
    bool operator<(const Line& rhs)const{
        return l!=rhs.l?l<rhs.l:r<rhs.r;
    }
}a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>d;
    rep(i,1,n) {
        long double x,y;
        cin>>x>>y;
        if(y-d>0.01) {
            cout<<-1<<endl;
            return 0;
        }
        long double dist=sqrt(d*d-y*y);
        a[i]={x-dist,x+dist};
    }
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--) {
        // cout<<a[i].l<<' '<<a[i].r<<endl;
        bool found=false;
        rep(j,1,ct) {
            if(p[j]>=a[i].l&&p[j]<=a[i].r) {
                found=true;
                break;
            }
        }
        if(!found) p[++ct]=a[i].l;
    }
    cout<<ct<<endl;
}