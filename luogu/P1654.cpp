#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=1e5+10;
int n;
double a[maxn],b[maxn],f[maxn];
int main() {
    cin>>n;
    rep(i,1,n) {
        double p; cin>>p;
        a[i]=p*(a[i-1]+1);
        b[i]=p*(b[i-1]+2*a[i-1]+1);
        f[i]=f[i-1]+p*(3*a[i-1]+3*b[i-1]+1);
    }
    cout<<fixed<<setprecision(1)<<f[n]<<endl;
    return 0;
}