#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1e4+10;
int n;
double a[maxn],f[maxn];     // 到n的期望钱数、期望钱数之平方
int main() {
    cin>>n;
    a[n]=f[n]=0;
    for(int i=n-1;i>=0;i--) {
        a[i]=a[i+1]+1.0*n/(n-i);
        f[i]=2.0*i/(n-i)*a[i]+1.0*n/(n-i)+2*a[i+1]+f[i+1];
    }
    cout<<fixed<<setprecision(2)<<(f[0]+a[0])/2<<endl;
    return 0;
}