#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1e5+10;
int n,x[maxn],y[maxn],r[maxn];
double d[maxn],f[maxn];
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i]>>r[i];
    for(int i=1;i<=n;i++) d[i]=x[i];
    sort(d+1,d+1+n);
    double mx=0;
    double step=200.0/n;
    for(int i=1;i<=n;i++) {
        double f_exp=1.0*i/n;
        double f_obs=(d[i]+100)/200;
        mx=max(mx,abs(f_obs-f_exp));
    }
    double conf=1.22385/sqrt(n);
    if(conf>mx) puts("bit-noob");       // 满足均匀分布
    else puts("buaa-noob");
    return 0;
}