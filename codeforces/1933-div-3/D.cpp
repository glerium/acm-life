#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1e5+10;
int t,n,a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int ct1=0;
        int g=a[1];
        for(int i=1;i<=n;i++) g = __gcd(g,a[i]);
        for(int i=1;i<=n;i++) a[i]/=g;
        for(int i=1;i<=n;i++) {
            ct1+=a[i]==1;
        }
        if(ct1>1) puts("NO");
        else puts("YES");
    }
}