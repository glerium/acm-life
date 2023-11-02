#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=1e3+10;
int n,a[maxn],b[maxn];
int t12,t13,t23,t21,t31,t32;
int main() {
    cin>>n;
    rep(i,1,n) cin>>a[i];
    rep(i,1,n) b[i]=a[i];
    sort(b+1,b+1+n);
    rep(i,1,n) {
        if(a[i]==1&&b[i]==2) t12++;
        else if(a[i]==1&&b[i]==3) t13++;
        else if(a[i]==2&&b[i]==1) t21++;
        else if(a[i]==2&&b[i]==3) t23++;
        else if(a[i]==3&&b[i]==1) t31++;
        else if(a[i]==3&&b[i]==2) t32++;
    }
    cout<<min(t12,t21)+min(t13,t31)+min(t23,t32)+2*(abs(t12-t21))<<endl;
}