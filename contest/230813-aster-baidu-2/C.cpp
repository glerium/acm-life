/*
in: 6
    0 1 2 3 1 5
out:3
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int maxm=1e6+10;
int n,a[maxn],ms[maxm],f[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<=1e6;i++) ms[i]=1e8;
    for(int i=1;i<=n;i++) f[i]=1e8;
    f[1]=0;
    ms[a[1]]=0;
    for(int i=2;i<=n;i++) {
        f[i]=min(f[i],f[i-1]+1);
        f[i]=min(f[i],ms[a[i]]+1);
        ms[a[i]]=min(ms[a[i]],f[i]);
        f[i-1]=min(f[i-1],f[i]+1);
        ms[a[i-1]]=min(ms[a[i-1]],f[i-1]);
    }
    cout<<f[n]<<endl;
    return 0;
}